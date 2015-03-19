  

# Manacher's ALGORITHM: O(n)时间求字符串的最长回文子串

![](Manacher's%20ALGORITHM%3A%20O\(n\)%E6%97%B6%E9%97%B4%E6%B1%82%E5%AD%97%E7%
AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.
resources/unstarred.gif) [Manacher's ALGORITHM:
O(n)时间求字符串的最长回文子串](http://www.felix021.com/blog/read.php?2040)

Translated to [ENGLISH
VERSION](http://www.felix021.com/blog/page.php?pageid=6)  
  
源于这两篇文章：  
<http://blog.csdn.net/ggggiqnypgjg/article/details/6645824>  
<http://zhuhongcheng.wordpress.com/2009/08/02/a-simple-linear-time-algorithm-
for-finding-longest-palindrome-sub-string/>  
  
这个算法看了三天，终于理解了，在这里记录一下自己的思路，免得以后忘了又要想很久- -.  
  
首先用一个非常巧妙的方式，将所有可能的奇数/偶数长度的回文子串都转换成了奇数长度：在每个字符的两边都插入一个特殊的符号。比如 abba 变成
#a#b#b#a#， aba变成 #a#b#a#。 为了进一步减少编码的复杂度，可以在字符串的开始加入另一个特殊字符，这样就不用特殊处理越界问题，比如$#a
#b#a#（注意，下面的代码是用C语言写就，由于C语言规范还要求字符串末尾有一个'\0'所以正好OK，但其他语言可能会导致越界）。  
  
下面以字符串12212321为例，经过上一步，变成了 S[] = "$#1#2#2#1#2#3#2#1#";  
  
然后用一个数组 P[i]
来记录以字符S[i]为中心的最长回文子串向左/右扩张的长度（包括S[i]，也就是把该回文串“对折”以后的长度），比如S和P的对应关系：

S  #  1  #  2  #  2  #  1  #  2  #  3  #  2  #  1  #  
P  1  2  1  2  5  2  1  4  1  2  1  6  1  2  1  2  1  
(p.s. 可以看出，P[i]-1正好是原字符串中回文串的总长度）

那么怎么计算P[i]呢？该算法增加两个辅助变量（其实一个就够了，两个更清晰）id和mx，其中id表示最大回文子串中心的位置，mx则为id+P[id]，也就是
最大回文子串的边界。  
  
然后可以得到一个非常神奇的结论，这个算法的关键点就在这里了：如果mx > i，那么P[i] >= MIN(P[2 * id - i], mx -
i)。就是这个串卡了我非常久。实际上如果把它写得复杂一点，理解起来会简单很多：

//记j = 2 * id - i，也就是说 j 是 i 关于 id 的对称点。  
(mx - i > P[j])  
    P[i] = P[j];  
/* P[j] >= mx - i */  
    P[i] = mx - i; // P[i] >= mx - i，取最小值，之后再匹配更新。

当然光看代码还是不够清晰，还是借助图来理解比较容易。  
  
当 mx - i > P[j] 的时候，以S[j]为中心的回文子串包含在以S[id]为中心的回文子串中，由于 i 和 j
对称，以S[i]为中心的回文子串必然包含在以S[id]为中心的回文子串中，所以必有 P[i] = P[j]，见下图。  

![](Manacher's%20ALGORITHM%3A%20O\(n\)%E6%97%B6%E9%97%B4%E6%B1%82%E5%AD%97%E7%
AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.
resources/37705A28-7464-4FA7-956E-D98FB2F298D9.png)

  
  
当 P[j] >= mx - i 的时候，以S[j]为中心的回文子串不一定完全包含于以S[id]为中心的回文子串中，但是基于对称性可知，下图中两个绿框所包围
的部分是相同的，也就是说以S[i]为中心的回文子串，其向右至少会扩张到mx的位置，也就是说 P[i] >= mx -
i。至于mx之后的部分是否对称，就只能老老实实去匹配了。  

![](Manacher's%20ALGORITHM%3A%20O\(n\)%E6%97%B6%E9%97%B4%E6%B1%82%E5%AD%97%E7%
AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.
resources/0A55AD33-34C4-4E0E-AB62-898240647D25.png)

  
  
对于 mx <= i 的情况，无法对 P[i]做更多的假设，只能P[i] = 1，然后再去匹配了。  
  
于是代码如下：

//输入，并处理得到字符串s  
p[1000], mx = 0, id = 0;  
memset(p, 0, sizeof(p));  
(i = 1; s[i] != '\0'; i++) {  
    p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;  
    while (s[i + p[i]] == s[i - p[i]]) p[i]++;  
    (i + p[i] > mx) {  
        mx = i + p[i];  
        id = i;  
    }  
}  
//找出p[i]中最大的

OVER.  
  
#UPDATE@2013-08-21 14:27  
@zhengyuee 同学指出，由于 P[id] = mx，所以 S[id-mx] != S[id+mx]，那么当 P[j] > mx - i
的时候，可以肯定 P[i] = mx - i
，不需要再继续匹配了。不过在具体实现的时候即使不考虑这一点，也只是多一次匹配（必然会fail），但是却要多加一个分支，所以上面的代码就不改了。  
  
转载请注明出自 **<http://www.felix021.com/blog/read.php?2040>** ，如是转载文则注明原出处，谢谢:)  
RSS订阅地址: **<http://www.felix021.com/blog/feed.php>** 。

* * *

  

