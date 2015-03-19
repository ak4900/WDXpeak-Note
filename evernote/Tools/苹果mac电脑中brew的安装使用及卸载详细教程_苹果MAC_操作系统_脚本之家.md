# 苹果mac电脑中brew的安装使用及卸载详细教程

来源：互联网 作者：佚名 时间：09-03 15:59:56 【 大 中 小】

brew 又叫Homebrew，是Mac OSX上的软件包管理工具，能在Mac中方便的安装软件或者卸载软件， 只需要一个命令

brew 又叫Homebrew，是Mac OSX上的软件包管理工具，能在Mac中方便的安装软件或者卸载软件， 只需要一个命令， 非常方便

brew类似ubuntu系统下的apt-get的功能

**安装brew**

brew 的官方网站： http://brew.sh/   在官方网站对brew的用法进行了详细的描述

安装方法：  在Mac中打开Termal:  输入命令：

    
    
    ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"

![](_resources/苹果mac电脑中brew的安装使用及卸载详细教程_苹果MAC_操作系统_脚本之家35A8C373-ACF4-4837-B0A2
-F0E483BCA0B7.jpg)

 不知道为什么， 在国内经常被屏蔽

使用brew安装软件

一个命令就搞定了， 比如安装git

    
    
    brew install git

![](_resources/苹果mac电脑中brew的安装使用及卸载详细教程_苹果MAC_操作系统_脚本之家EC6DA545-6B5E-4154-ACA9
-1E9F80694222.png)

比如安装wget

    
    
    brew install wget

**使用brew卸载软件**

卸载更方便了

    
    
    brew uninstall wget

![](_resources/苹果mac电脑中brew的安装使用及卸载详细教程_苹果MAC_操作系统_脚本之家5F5204E6-11C2-417F-
94AF-52EAB04DB877.png)

使用brew查询软件

有时候，你不知道你安装的软件的名字， 那么你需要先搜索下, 查到包的名字。

比如我要安装

    
    
    brew search /wge*/

/wge*/是个正则表达式， 需要包含在/中

![](_resources/苹果mac电脑中brew的安装使用及卸载详细教程_苹果MAC_操作系统_脚本之家6B1C680D-9938-451E-
9B63-70CA6E1EFCD3.png)

**其他brew命令**

brew list           列出已安装的软件

brew update     更新brew

brew home       用浏览器打开brew的官方网站

brew info         显示软件信息

brew deps        显示包依赖

![](_resources/苹果mac电脑中brew的安装使用及卸载详细教程_苹果MAC_操作系统_脚本之家985B4348-F8A7-4222-AC19
-24DC753CDF68.png)

