# 打造好用的终端 —— iTerm2 别样设置

Sat 2013-04-13

![](%E6%89%93%E9%80%A0%E5%A5%BD%E7%94%A8%E7%9A%84%E7%BB%88%E7%AB%AF%20%E2%80%9
4%E2%80%94%20iTerm2%20%E5%88%AB%E6%A0%B7%E8%AE%BE%E7%BD%AE%20-%20M.Trine.resou
rces/4B168F79-D251-4ED3-9861-F8F71A99CED0.gif)

如上图，让 [iTerm2](https://code.google.com/p/iterm2/downloads/list) 随叫随到而且不占用 Dock
上宝贵的空间，想知道这是如何做到的呢，看下面一步步的讲解吧〜

* * *

### Step1 - 设置窗口

定位到 [Preferences - Profiles - Window] 新窗口设定风格设为 [Top of
Screen]，这样每次新打开终端都会固定出现在屏幕的顶端且**不会有窗口边框**。如果你也使用多 Space 和双显示器的话，同时选择 Main
Screen 和 All Space 会比较方便。

![Window](http://i.minus.com/iAv5Ywf1l2AnJ.png)

### Step2 - 设置快捷键

这一步很简单，定位到 [Preferences - Keys - Hotkey]，这里有两个选项，第一个为设置全局快捷键，在 iTerm
启动的前提下，使用该快捷键可显示或隐藏窗口。第二个指定新窗口使用哪个 Profile，这里就指定为在 Step1 中设置了 WIndow
的那个即可，勾选这个选项能获得显示／隐藏窗口时淡入淡出的技能。

![Hotkey](http://i.minus.com/iRzI4TXGfDjPC.png)

### Step3 - 随时响应

完成上面两步，在 iTerm 已经启动的情况下就能够完成本文最开始GIF中那样的效果了。但是这样还不够，要让其随时响应，就需要 iTerm
随时保持在启动状态。可选的方法有两种：

  1. 定义全局快捷键

第一种，不需要借助任何工具就可实现，在 OSX 系统账户设置中添加 iTerm 为登录启动项即可。  
第二种方法需要借助快捷键工具，我在使用 Alfred2 所以直接在里面添加快捷键就可以。快捷键设置的技巧在于，要使用和 Step2
中相同的快捷键（设置前先退出 iTerm），并且勾选 [Toggle visibility for apps]。

![Alfred2](http://i.minus.com/iEctZIkScVLIH.png)

这一步完成，就可以用快捷键方便的调出／隐藏终端了。但是你应该注意到了，它会一直躺在 Dock上。。。

### Step4 - 隐藏 Dock 图标

让我们的终端变得更 Cool，让它来无影去无踪。这一步我要 iTerm 启动后不再出现在 Dock 上，打开终端输入下面的命令，然后重启 iTerm。

    
    
    /usr/libexec/PlistBuddy  -c "Add :LSUIElement bool true" /Applications/iTerm.app/Contents/Info.plist
    

这个方法是通用的，`LSUIElement`[1](http://imwuyu.me/talk-about/cool-
iterm2.html/#fn:1)可控制 app
以无Dock，无菜单栏的方式运行，另外`LSBackgroundOnly`[2](http://imwuyu.me/talk-about/cool-
iterm2.html/#fn:2)可让 app 以无窗口的方式在后台运行。详细说明可查看 [LaunchServicesKeys](http://deve
loper.apple.com/library/ios/#documentation/general/Reference/InfoPlistKeyRefer
ence/Articles/LaunchServicesKeys.html)

如果要恢复 Dock 图标：

    
    
    /usr/libexec/PlistBuddy  -c "Delete :LSUIElement" /Applications/iTerm.app/Contents/Info.plist
    

想要方便开关 Dock 图标，可将下面的内容添加到 `~/.zshrc` 或 `~/.bash_profile`中，然后只需要输入
`toggleiTerm`，按提示操作即可。

* * *

  * 需要全屏？复制原来的 Profile 然后指定快捷键，再 WIndow - Style 选择全屏。
  * 「CMD+D」水平分割窗口，为保持界面简洁在 [Preferences - Appearance] 中不勾选 [Show per-pane title bar …]
  * 如果使用开机启动 iTerm 的方式则不要勾选 [Preferences - General] [Quit when all windows are closed]
  * 在 [Preferences - Pointer] 勾选 [Focus follows mouse]，方便在窗口间切换。

  1. Specifies whether the app is an agent app, that is, an app that should not appear in the Dock or Force Quit window. [↩](http://imwuyu.me/talk-about/cool-iterm2.html/#fnref:1)

  2. Specifies whether the app runs only in the background. (Mach-O apps only).[↩](http://imwuyu.me/talk-about/cool-iterm2.html/#fnref:2)

