//
//  stringbasic.h
//  AlgorithmLearing
//
//  Created by WangDa on 11/13/14.
//  Copyright (c) 2014 DaWang. All rights reserved.
//

#ifndef AlgorithmLearing_stringbasic_h
#define AlgorithmLearing_stringbasic_h

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


// abcdef -> cdefab n = 2
// abcdef -> defabc n = 3
void reverse(char *s, int from, int to)
{
    while (from < to)
    {
        char t = s[to];
        s[to] = s[from];
        s[from] = t;
        from++;
        to--;
    }
}

// 三步反转
void LeftRotateString(char *s, int n, int m)
{
    m %= n;
    reverse(s, 0, m-1);
    reverse(s, m, n-1);
    reverse(s, 0, n-1);
}


// --------------------------
// 链表
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node* CreateSampleLinkedList(int number)
{
    Node *head, *p, *s;
    head = (Node *)malloc(sizeof(Node));
    
    p = head;
    int i = 1;
    while (i <= number )
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = i++;
        p->next = s;
        p = s;
    }
    s = head;
    head = head->next;
    p->next = NULL;
    delete s;

    return head;
}

void OutputLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// origin : 1-2-3-4-5-6
// n = 2: 2-1-6-5-4-3
// n = 3: 3-2-1-6-5-4
Node* ReverseLinkedList(Node *head)
{
    Node *current = head;
    Node *previous = NULL;
    
    while(current != NULL)
    {
        Node* next = current->next;
        current->next = previous;
        
        previous = current;
        current = next;
    }
    // previous 此时为头指针
    return previous;
}

Node *SplitAndReverse(Node *head, int n)
{
    Node *oldHead = head;
    // spit the linkedlist
    Node *secondHead = head;
    Node *firstTail = head;
    for (int i = 0; i < n-1; i++)
    {
        secondHead = secondHead->next;
    }
    firstTail = secondHead;
    secondHead = secondHead->next;
    firstTail->next = NULL; // split
    
    Node *newHead = ReverseLinkedList(oldHead);
    oldHead->next = ReverseLinkedList(secondHead);
    
    return newHead;
}

//---------------------------

// 字符串包含
// length(A) > length(B)
// B 中的字符是否在 A 中都有

// 1.计数
bool StringContains1(string &A, string &B)
{
    int alphebat[26];
    memset(alphebat, 0, sizeof(int)*26);
    
    for (int i = 0; i < A.length(); i++)
    {
        alphebat[A[i] - 'A'] += 1;
    }
    
    for (int i = 0; i < B.length(); i++)
    {
        if (alphebat[B[i] - 'A'] == 0)
        {
            return false;
        }
    }
    return true;
}

// 2.HashTable
bool StringContains2(string &A, string &B)
{
    int hash[26];
    int m = 0;
    memset(hash, 0, sizeof(int)*26);
    
    // 用 B 做标记，可以更快一些
    for (int i = 0; i < B.length(); i++)
    {
        if (hash[B[i] - 'A'] == 0)
        {
            hash[B[i] - 'A'] = 1;
            m++;
        }
    }
    
    for (int i = 0; i < A.length() && m > 0; i++)
    {
        if (hash[A[i] - 'A'] == 1)
        {
            m--;
            hash[A[i] - 'A'] = 0;
        }
    }
    
    return (m == 0);
}

// 3.素数相乘
// 每个字符对应一个素数，然后得到一个乘积，之后用B 中每个字符去试能否整除，可能会溢出

// 4.位运算
// 对字符串 A，用位运算计算出一个“签名”，在用 B 中的字符到 A 里面进行查找，用一个整数代替 hashtable
// 空间复杂度可以降低为 O(1), 时间复杂度还是 O(n+m)
bool StringContains3(string &A, string &B)
{
    int hash = 0;
    for (int i = 0; i < A.length(); i++)
    {
        hash |= (1 << (A[i]-'A'));
    }
    
    for (int i = 0; i < B.length(); i++) {
        if ((hash & (1 << (B[i]-'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}

// -----------------------------

// 带通配符的字符串匹配问题
// 给定一个字符串和匹配规则，以空格为间隔，输出匹配结果
// 匹配规则中包含?和*,?表示匹配任意一个，*表示任意多个(>=0)
// 匹配最大子串，匹配后的输入串不再进行匹配，从当前匹配后继续
// 不能用 C/C++ 库，和 Java 的 String 对象

// 方法一：直接匹配

int str_len(char *a)
{
    if (a == 0)
    {
        return 0;
    }
    char *t = a;
    for ( ; *t; t++) {}
    
    return (int)(t-a);
}

void str_copy(char *a, const char*b, int len)
{
    for (; len > 0; len--, b++, a++)
    {
        *a = *b;
    }
    *a = 0;
}

char *str_join(char *a, const char *b, int lenb)
{
    // 连接字符串，第一个字符串被回收
    char *t;
    if (a == 0)
    {
        t = (char *)malloc(sizeof(char)*(lenb+1));
        str_copy(t, b, lenb);
        return t;
    }
    else
    {
        int lena = str_len(a);
        t = (char *)malloc(sizeof(char)*(lena+lenb+2));
        str_copy(t, a, lena);
        *(t + lena) = ' ';
        str_copy(t+lena+1, b, lenb);
        free(a);
        return t;
    }
}

int canMatch(char *input, char *rule)
{
    //返回最大匹配长度，-1表示不匹配
    if (*rule == 0)
    {
        // end
        return 0;
    }
    int r = -1, may;
    if (*rule == '*')
    {
        r = canMatch(input, rule + 1);
        if (*input)
        {
            may = canMatch(input + 1, rule);
            if ((may >= 0) && (++may > r))
            {
                r = may;
            }
        }
    }
    if(*input == 0)
    {
        // end
        return r;
    }
    
    if ((*rule == '?') || (*rule == *input))
    {
        may = canMatch(input + 1, rule + 1);
        if ((may >= 0)&&(++may > r))
        {
            r = may;
        }
    }
    return r;
}

char* my_find(char input[], char rule[])
{
    int len = str_len(input);
    int *match = (int *)malloc(sizeof(int)*len); // input 第 i 位最多能匹配多少位，匹配不上是-1
    int i, max_pos = -1;
    char *output = 0;
    
    for (i = 0; i < len; i++)
    {
        match[i] = canMatch(input+i, rule);
        if ((max_pos < 0) || (match[i] > match[max_pos]))
        {
            max_pos = i;
        }
    }
    if ((max_pos < 0) || (match[max_pos] <= 0))
    {
        // 不匹配
        output = (char *)malloc(sizeof(char));
        *output = 0;
        return output;
    }
    for (i = 0; i < len; )
    {
        if (match[i] == match[max_pos])
        {
            // 找到匹配
            output = str_join(output, input + i, match[i]);
            i+= match[i];
        }
        else
        {
            i++;
        }
    }
    free(match);
    return output;
}

// 也可以用动态规划做，具体留到动态规划一节

// -------------------------

// 字符串转换成整数
// 自己实现 atoi
// 需要注意的四个细节：
// 1.正负符号
// 2.空指针输入
// 3.非法字符
// 4.整型溢出

int StrToInt(const char *str)
{
    static const int MAX = (int)((unsigned)~0 >> 1);
    static const int MIN = -(int)((unsigned)~0 >> 1)-1;
    static const int MAX_DIV = (int)((unsigned)~0 >> 1) / 10;
    static const int MIN_DIV = (int)((((unsigned)~0 >> 1) +1)/ 10);
    static const int MAX_R = (int)((unsigned)~0 >> 1) % 10;
    static const int MIN_R = (int)((((unsigned)~0 >> 1)+1)%10);
    
    int n = 0;
    int sign = 1;
    int c;
    
    if (!str)
        return 0;
    
    // 跳过空格
    while (isspace(*str)) {
        str++;
    }
    
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }
    
    
    while (*str >= '0' && *str <= '9') {
        c = *str - '0';
        
        if ((sign>0) &&(n > MAX_DIV || (n == MAX_DIV && c >= MAX_R))) {
            n = MAX;
            break;
        }
        else if ((sign<0) &&(n > MIN_DIV || (n == MIN_DIV && c >= MIN_R))) {
            n = MIN;
            break;
        }
        n = n * 10 + c;
        str++;

    }
    return (sign>0)?n:-n;
}

// 举一反三问题： string2double
// 需要更加细致，各种边界条件

// ----------------------
// 回文判断

// 1.头尾一起扫描判断
// 时间复杂度 O(n)，空间复杂度 O(1)
bool isPalindrome1(const char *s, int n)
{
    if (s == NULL) {
        return false;
    }
    
    int head, tail;
    head = 0;
    tail = n-1;
    
    while (head < tail) {
        if (s[head] == s[tail]) {
            // same
            head++;
            tail--;
        }
        else{
            return false;
        }
    }
    return true;
}

// 2.从中间扫描
bool isPalindrome2(const char *s, int n)
{
    if (s == NULL || n < 1) {
        return false;
    }
    
    int first, second;
    int m = ((n >> 1) -1)>=0?(n>>1)-1:0; // middle point
    first = m;
    second = n-1-m;
    
    while (first >= 0) {
        if (s[first--] != s[second++]) {
            return false;
        }
    }
    return true;
}

// 举一反三：判断一个单向链表是否是回文
// 经典的快慢指针来进行遍历，先定位到链表的中间位置，再讲后半链表反转，最后用两个指针同时从头遍历即可
bool isPalindromeLinkedList(Node *head)
{
    stack<Node*> stk;
    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    while (fast) {
        stk.push(slow);
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        } else
            flag = true;
    }
    if (flag)
        stk.pop();
    while (!stk.empty()) {
        if (stk.top()->data == slow->data){
            stk.pop();
            slow = slow->next;
        }
        else
            return false;
    }
    return true;
}

// 举一反三：判断一个栈是否是回文
// 把字符串全部提取出来得到 s1，再入栈出栈得到 s2，比较s1和 s2即可

bool isPalindromeStack(stack<char> text)
{
    stack<char> st;
    queue<char> sq;
    while (!text.empty()) {
        st.push(text.top());
        sq.push(text.top());
        text.pop();
    }
    
    while (!st.empty()) {
        if (st.top() != sq.front()) {
            return false;
        }
        st.pop();
        sq.pop();
    }
    
    return true;
}

// -------------------
// 最长回文子串的长度
// 使用扩展法，从一个字符开始，向两边扩展，看看最多能多长

int LongestPalindrome(const char *s, int n)
{
    int i, j, max;
    
    if (s == 0 || n < 1)
        return 0;
    
    max = 0;
    for (i = 0; i < n; i++) {
        // i is the middle point of the palindrome
        for (j = 0; (i-j >= 0) && (i+j<n); j++) { //odd palindrome
            if (s[i-j] != s[i+j]) {
                break;
            }
            
        }
        
        if ((j-1)*2+1>max) {
            max = (j-1)*2+1;
        }
        
        for(j = 0;(i-j >= 0)&&(i+j+1<n);j++){//even palindrome
            if (s[i-j]!=s[i+j+1]) {
                break;
            }
        }
        
        if ((j-1)*2+2>max) {
            max = (j-1)*2+2;
        }
        
    }
    return max;
}

// O(N)的解法
/*
 这个算法有一个很巧妙的地方，它把奇数的回文串和偶数的回文串统一起来考虑了。这一点一直是在做回文串问题中时比较烦的地方。这个算法还有一个很好的地方就是充分利用了字符匹配的特殊性，避免了大量不必要的重复匹配。
 算法大致过程是这样。先在每两个相邻字符中间插入一个分隔符，当然这个分隔符要在原串中没有出现过。一般可以用‘#’分隔。这样就非常巧妙的将奇数长度回文串与偶数长度回文串统一起来考虑了（见下面的一个例子，回文串长度全为奇数了），然后用一个辅助数组P记录以每个字符为中心的最长回文串的信息。P［id］记录的是以字符str［id］为中心的最长回文串，当以str［id］为第一个字符，这个最长回文串向右延伸了P［id］个字符。
 原串: waabwswfd
 新字符串P: # w # a # a # b # w # s # w # f # d #
 辅助数组P: 1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1
 这里有一个很好的性质，P[id]-1就是该回文子串在原串中的长度（包括‘#’）。如果这里不是特别清楚，可以自己拿出纸来画一画，自己体会体会。当然这里可能每个人写法不尽相同，不过我想大致思路应该是一样的吧。
 好，我们继续。现在的关键问题就在于怎么在O(n)时间复杂度内求出P数组了。只要把这个P数组求出来，最长回文子串就可以直接扫一遍得出来了。
 由于这个算法是线性从前往后扫的。那么当我们准备求P[i]的时候，i以前的P[j]我们是已经得到了的。我们用mx记在i之前的回文串中，延伸至最右端的位置。同时用id这个变量记下取得这个最优mx时的id值。（注：为了防止字符比较的时候越界，我在这个加了‘#’的字符串之前还加了另一个特殊字符‘$’，故我的新串下标是从1开始的）
 */

int LongestPalindromeON(const char *s, int n)
{
    const int MAXN = 10000;
    char str[MAXN * 2];
    int p[MAXN*2], ans=1;
    
    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < n; i++) {
        str[2*i+2] = str[i];
        str[2*i+3] = '#';
    }
    
    int nl = n * 2 + 2;
    str[nl] = 0;
    
    int mx=0, index=1;
    for (int i = 0; i < nl; i++) {
        if(mx > i)
            p[i]=min(p[2*index-i], mx-i);
        else
            p[i]=1;
        
        for(;s[i-p[i]] == s[i+p[i]]; p[i]++);
        
        if(p[i]+i>mx)
        {
            mx = p[i]+i;
            index = i;
        }
        ans=max(ans,p[i]);
    }
    return ans*2 -1;
}


// -----------------------
// 第一个只出现一次的字符

char FirstNotRepeatChar(char *pString)
{
    if (!pString) {
        return '\0';
    }
    
    const int tableSize = 256;
    int hashTable[tableSize] = {0};
    
    char *pHashKey = pString;
    while (*(pHashKey) != '\0') {
        hashTable[*(pHashKey++)]++;
    }
    
    while (*pString != '\0') {
        if (hashTable[*pString] == 1) {
            return *pString;
        }
        pString++;
    }
    return '\0';
}

// ---------------------
// 寻找最小的 K 个数

// 1.普通方法：先排序，后输出前 N 个
// O(nlogn) + O(k)

int comp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

void findSmallK1(int* a, int n, int k)
{
    if (k < n) {
        qsort(a, n, sizeof(int), comp);
        
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

// 2.不必全都排序，给一个大小为 k 的数组，就保存最小的 k 个值即可
// O(n*k)

void findSmallK2(int* a, int n, int k)
{
    int *result = new int(k);
    int rmax = 0;
    int irmax = 0; // index
    
    if (k < n) {
        for (int i = 0; i < k; i++) {
            result[i] = a[i];
            if (a[i] > rmax) {
                rmax = a[i];
                irmax = i;
            }
        }
        
        for (int i = k; i < n; i++) {
            if (rmax > a[i]) {
                result[irmax] = a[i];
                rmax = 0;
            }
            
            // update rmax, irmax
            for (int j = 0; j < k; j++) {
                if (result[j] > rmax) {
                    rmax = result[j];
                    irmax = j;
                }
            }
        }
        
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

    }
    else
    {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

// 3.把第二种方法中的数组改为堆
// O(nlogk)这得益于在堆中查找的复杂度从 O(k)降为 O(logk)

// 4.快速选择算法 来自《数据结构与算法分析-c语言描述》用来找到第 k 个最小的值
// 最坏情况下 O(n)
/*
 n 为数组中的元素个数
 1.如果 n=1，那么 k=1，直接返回即可
 2.选取 array 中的一个元素作为 pivot，称为 v
 3.类似快排，由 v 把 array 分成 a1 和 a2
 4.如果 k<= a1的元素个数，那么第 k 个最小元素一定在 a1 中，返回 quickselect(a1,k)。如果 k=1+a1的个数，那么说明 v 就是第 k 个最小元素，返回 v。否则，第 k 个最小元素就在 a2中，即 a2 中的第(k-a1的元素个数-1)个最小元素，递归调用返回 quickselect(a2, k-a1元素个数-1)
 */

// 举一反三：输入是两个整数数组，他们任意两个数得和又可以组成一个数组，求这个数组中的前 k 个。

// 注意伴随数组的使用


// -------------------------
// 求解500万以内的亲和数
/*
 如果两个数 a 和 b，a 的所有真因数之和等于 b，b 的所有真因数之和等于 a，则 a和 b 是一对亲和数。(220,284)(1184,1210)(2620,2294)
 
 220=1+2+4+71+142=sum[284]
 284=1+2+4+5+10+11+20+22+44+55+110=sum[220]
 sum[220]=sum[sum[284]]=284
 */



#endif
