#  Win8+Ubuntu12.04双系统安装(EasyBCD硬盘安装)

分类： [Some Tips](http://blog.csdn.net/yeruby/article/category/1091405)
2013-10-06 11:30 24340人阅读
[评论](http://blog.csdn.net/yeruby/article/details/12340499#comments)(10) 收藏
[举报](http://blog.csdn.net/yeruby/article/details/12340499#report)

注：本文原创，转载请注明出处。

笔者是在win8的os上安装一个ubuntu的os，过程如下：

1.下载ubuntu的镜像文件：

下载地址：<http://www.ubuntu.com/download>

我下载的是ubuntu-12.04-desktop-i386.iso

2.下载easybcd软件：

点击下载：<http://pan.baidu.com/s/15Q3PO>

3.给你的ubuntu系统设置一个独立的分区，笔者设置了大小为20g的分区X

4.好，准备工作已经做好，下面开始具体的操作：

打开刚刚下载的easybcd软件，依次点击“添加新条目”，“NeoGrub”，“安装”后，会激活“配置”按钮，这时点击“配置”，会出现一个名为“menu.l
st”的txt文件。

![](Win8+Ubuntu12.04%E5%8F%8C%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85\(EasyBCD%E7%
A1%AC%E7%9B%98%E5%AE%89%E8%A3%85\)%20-%20%E5%9C%A8%E8%B7%AF%E4%B8%8A%E7%9A%84%
E5%AD%A6%E4%B9%A0%E8%80%85%20-%20%E5%8D%9A%E5%AE%A2%E9%A2%91%E9%81%93%20-%20CS
DN.NET.resources/33F3FA35-9ABF-419F-9CB6-7B85DEB9E74B.jpg)

这时，我们需要重新编辑这个txt文件，将如下内容复制进去，替换掉全来的内容：

  1. title Install Ubuntu  
  2. root (hd0,0)  
  3. kernel (hd0,0)/vmlinuz boot=casper iso-scan/filename=/ubuntu-12.04-desktop-i386.iso ro quiet splash locale=zh_CN.UTF-8  
  4. initrd (hd0,0)/initrd.lz  
    
    
    title Install Ubuntu
    root (hd0,0)
    kernel (hd0,0)/vmlinuz boot=casper iso-scan/filename=/ubuntu-12.04-desktop-i386.iso ro quiet splash locale=zh_CN.UTF-8
    initrd (hd0,0)/initrd.lz

此时，需要特别注意：  
（1）“ubuntu-12.04-desktop-i386.iso”是你下载的ubuntu镜像的名字，笔者的名字就为上面所示的ubuntu-12.04-de
sktop-i386.iso；  
（2）你需要查看一下你的电脑上C盘所在位置是第几个分区，像笔者的电脑上，C盘在第二个分区，所以需要将上述凡是有（hd0，0）的内容改为（hd0，1）  
查看方法：右键我的电脑，点击“管理”，点击“磁盘管理”，即可查看到。下图即可看出，笔者的c盘在第二个分区中。

![](Win8+Ubuntu12.04%E5%8F%8C%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85\(EasyBCD%E7%
A1%AC%E7%9B%98%E5%AE%89%E8%A3%85\)%20-%20%E5%9C%A8%E8%B7%AF%E4%B8%8A%E7%9A%84%
E5%AD%A6%E4%B9%A0%E8%80%85%20-%20%E5%8D%9A%E5%AE%A2%E9%A2%91%E9%81%93%20-%20CS
DN.NET.resources/4E6629DF-9E46-45CC-8E00-4B5D5D330D81.jpg)

接着，我们将下载好的ubuntu-12.04-desktop-i386.iso分别复制到c盘和你开始为ubuntu创建的那个盘符下（笔者是X盘），然后将镜像
文件中的casper文件夹中的vmlinuz、initrd.lz两个文件也分别复制到c盘和你开始为ubuntu创建的那个盘符下（笔者是X盘）。如图所示：  
笔者c盘中的3个文件：

![](Win8+Ubuntu12.04%E5%8F%8C%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85\(EasyBCD%E7%
A1%AC%E7%9B%98%E5%AE%89%E8%A3%85\)%20-%20%E5%9C%A8%E8%B7%AF%E4%B8%8A%E7%9A%84%
E5%AD%A6%E4%B9%A0%E8%80%85%20-%20%E5%8D%9A%E5%AE%A2%E9%A2%91%E9%81%93%20-%20CS
DN.NET.resources/EA3BE117-05F7-4D61-B1D0-494331F86F19.jpg)

笔者x盘中的3个文件：

![](Win8+Ubuntu12.04%E5%8F%8C%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85\(EasyBCD%E7%
A1%AC%E7%9B%98%E5%AE%89%E8%A3%85\)%20-%20%E5%9C%A8%E8%B7%AF%E4%B8%8A%E7%9A%84%
E5%AD%A6%E4%B9%A0%E8%80%85%20-%20%E5%8D%9A%E5%AE%A2%E9%A2%91%E9%81%93%20-%20CS
DN.NET.resources/F0E48968-5014-40A8-B6CD-981C22061C57.jpg)

5.下面重启计算机，在启动菜单中选择刚刚设置的NeoGrub启动加载，之后计算机会去加载相应盘符的ubuntu安装文件，之后就是正常的安装ubuntu系统的
操作了。  
  
6.点击“安装ubuntu”前需要打开终端，输入代码:sudo umount -l /isodevice  
这个是硬盘安装系统时候需要运行的命令，是把已经挂载的iso文件卸载。因为iso文件是存储在硬盘上的，所以只有卸载之后才能够给该硬盘分区。  
之后“傻瓜式”安装即可。  
  
7.收尾工作：  
安装完成后，重启计算机回到win8系统中将先前设置的引导删除，具体方法：  
打开easybcd软件，依次点击“添加新条目”，“NeoGrub”，“删除”，在回到我们的c盘，删除先前复制进去的vmlinuz，initrd.lz和系统的
iso文件。  
  
  
至此，恭喜你成功的完成了双系统的安装。

