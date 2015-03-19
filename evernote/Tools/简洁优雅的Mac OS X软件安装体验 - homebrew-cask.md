# 简洁优雅的Mac OS X软件安装体验 - homebrew-cask

05 October 2013 on [Mac技巧](http://ksmx.me/tag/macji-qiao/),
[命令行爱好者](http://ksmx.me/tag/ming-ling-xing-ai-hao-zhe/)

> 在 [Mac OS X，糟透了的软件安装体验](http://ksmx.me/broken-user-experience-of-
installation-applications-on-mac-os-x/) 姐妹篇中，我从用户体验角度分析了现在 Mac OS X
的安装体验糟糕的原因。

## 简洁优雅的命令行工具 homebrew-cask

**使用homebrew-cask安装软件，只需要一行命令**

`brew cask install sublime-text skitch dropbox google-chrome`

这样以下就安装了4个软件，轻松搞定，不需要鼠标点击，no dragging, no dropping。

_* 命令行？好像很高大上的赶脚，我能学会吗？ *_

homebrew-
cask是一套建立在homebrew基础上的Mac软件安装命令行工具（想要详细了解homebrew，自己google）。拥有她只需要简单的3步：

  1. 安装Xcode（Mac App Store免费一键下载） 
  2. 安装homebrew（一行命令直接搞定，easy） 
  3. 安装homebrew-cask（也是一行命令搞定，一点难度都木有）

不要一听到是`命令行`就被吓到，其实没有那么复杂，`命令行`你就简单理解为你输入一行一行指令，指令对了系统就会去执行，用狗血的拟人比喻，就是你让计算机去干活
，只要`命令`下得对，它就屁颠屁颠卖命去了。

### 1\. 安转Xcode

Xcode安装现在已经非常简单，打开「Mac App Store」，又上角搜索 `xcode` 就可以找到，点击安装，耗时较长耐心等待。

![](%E7%AE%80%E6%B4%81%E4%BC%98%E9%9B%85%E7%9A%84Mac%20OS%20X%E8%BD%AF%E4%BB%B
6%E5%AE%89%E8%A3%85%E4%BD%93%E9%AA%8C%20-%20homebrew-
cask.resources/E0305566-A1F3-43BA-B95D-44DFD20AABFD.png)

这一步是鼠标操作，很简单，就这样跳过了。

### 2\. 安装homebrew

homebrew的官网是<http://brew.sh/>，上面有简体版本，可以了解以下homebrew是干啥的，但回到安装的正题，一行命令安装：

先打开 `Terminal`，找不到的可以点击Mac屏幕右上角的放大镜（这货是传说中的Spotlight），然后输入`terminal`回车就能直接打开。

![](%E7%AE%80%E6%B4%81%E4%BC%98%E9%9B%85%E7%9A%84Mac%20OS%20X%E8%BD%AF%E4%BB%B
6%E5%AE%89%E8%A3%85%E4%BD%93%E9%AA%8C%20-%20homebrew-
cask.resources/26F2564D-C395-4F8E-97D1-4EC33FDBF72E.png)

打开`Terminal`后，把下面的一样命令复制粘贴到里面，按下回车：

    
    
    ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"  
    

![](%E7%AE%80%E6%B4%81%E4%BC%98%E9%9B%85%E7%9A%84Mac%20OS%20X%E8%BD%AF%E4%BB%B
6%E5%AE%89%E8%A3%85%E4%BD%93%E9%AA%8C%20-%20homebrew-
cask.resources/9AB0A226-4642-4C5F-9404-E0F27D9DDACD.png)

屏幕一堆英文乱闪之后，就搞定了（命令提示符号回到原来的样子）。

### 3\. 安装homebrew-cask

还是那个「Terminal」窗口，再把下面的命令复制粘贴过去，按下回车。

    
    
    brew tap phinze/homebrew-cask && brew install brew-cask  
    

在安装brew-cask的时候，会要求你输入当前用户的密码，输入过程中不会有屏幕反馈，你就闭着眼睛输入，然后回程就可以。

![](%E7%AE%80%E6%B4%81%E4%BC%98%E9%9B%85%E7%9A%84Mac%20OS%20X%E8%BD%AF%E4%BB%B
6%E5%AE%89%E8%A3%85%E4%BD%93%E9%AA%8C%20-%20homebrew-
cask.resources/961377B7-2BE5-4B9F-8D28-7A2F5E5A8807.png)

又一大波文字乱闪，OK啦。

### 如何使用homebrew-cask

需要安装应用时，打开「Terminal」，输入

    
    
    brew cask install XXX
    
    # 将XXX替换成你想要安装的软件名称就可以了
    

下面做个示范：

![](%E7%AE%80%E6%B4%81%E4%BC%98%E9%9B%85%E7%9A%84Mac%20OS%20X%E8%BD%AF%E4%BB%B
6%E5%AE%89%E8%A3%85%E4%BD%93%E9%AA%8C%20-%20homebrew-
cask.resources/EF07A052-8316-4FEC-9C58-54008BC5E1E8.png)

_* 常用命令 *_

  * `brew cask search` 列出所有可以被安装的软件
  * `brew cask search drop` 查找所有和 _drop_ 相关的应用
  * `brew cask info thunder` 查看 _迅雷_ 应用的信息，这货安装的可是最新版本的迅雷哦！
  * `brew cask uninstall qq` 卸载 _QQ_

> **特别注意** homebrew-cask是将应用程序放置在`/opt/homebrew-cask/Caskroom/`下，会在你的家目录中的「应用程
序」文件夹中创建一个类似快捷方式的替身。在Finder的偏好设置中，第三个侧边栏勾选上你的家目录，这样找应用会方便一些。但不用太担心你，Launchpad是
会找到这个目录下的应用的，需要Alfred支持请查看`brew cask alfred`。

## homebrew-cask vs Mac App Store

homebrew-cask 和 Mac App Store 相比，目前还有很多优势：

  1. 安装软件体验非常一致简洁优雅 
  2. 对常用软件支持更全面，例如 MPlayerX 已经宣布不在更新 Mac App Store上 的版本 
  3. 软件更新速度快，体验好。例如Alfred 2.0已经出了很久，但在 Mac App Store 上还是1.2版本，QQ也是这样的情况

当然我承认，命令行的交互方式并不是人人都能学会和接受，homebrew-cask其实已经做的足够简单易用，习得这一技能能在以后提高效率。homebrew-
cask安装省时省力，更新应用也简单，不用一个一个去找，其实先花时间学习，是值回本钱的，大家自己算算这笔帐。

Mac App Store 生态圈远不完善，审核流程过长，限制太多，维护成本过高让很多应用开发者被迫离开。虽然我个人很喜欢 homebrew-
cask，但还是希望 Apple 尽快完善 Mac App Store ，等到有一天我可以不再使用 homebrew-
cask。这样说是不是显得我很薄情？:)

## 关于软件更新

homebrew-cask团队一直还在探讨软件更新策略，以及homebrew-cask与homebrew的关系。目前倾向于：

  1. homebrew-cask作为软件安装工具体验是不错的（相比你要自己到网页上搜索，下载，拖转安装） 
  2. 大部分软件都有自更新的功能，体验也不错，绝大多数只需要一次点击就能更新 
  3. 实际上软件更新没有那么频繁，使用`brew cask uninstall qq && brew cask install qq` 也比上网自己下载更新方便

**软件更新的结论**

目前通过homebrew-cask安装的软件有两种更新方法：

  1. 使用软件自己的更新流程 
  2. `brew cask uninstall APP && brew cask install APP` 先删除App，再重新安装

详细情况可以围观这个讨论帖子： [brew cask upgrade](https://github.com/phinze/homebrew-
cask/issues/309)， 具体看 [第2条](https://github.com/phinze/homebrew-
cask/issues/309#issuecomment-17777140) 和 [第5条](https://github.com/phinze
/homebrew-cask/issues/309#issuecomment-17782008) 评论。

**一键装机？有了homebrew-cask就可以**
    
    
    # 到目前October 5, 2013 1:43 PM为止，homebrew-cask共收录566款应用程序
    # 瞬间安装所有常用软件
    
    brew cask install alfred
    brew cask install the-unarchiver
    brew cask install qq
    brew cask install line
    brew cask install skype
    brew cask install thunder
    brew cask install mplayerx
    brew cask install evernote
    brew cask install skitch
    brew cask install dropbox
    brew cask install google-chrome
    brew cask install mou
    brew cask install iterm2
    brew cask install sublime-text
    brew cask install virtualbox
    

