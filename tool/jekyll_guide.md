## 利用 Jekyll QuickStart 快速搭建博客

之前用 github 配置过博客，但是似乎比较复杂，也没怎么弄好，今天发现了有一个 [repo](http://jekyllbootstrap.com/usage/jekyll-quick-start.html?#) 已经把这些杂七杂八的东西都弄好了，自然是很好。

根据教程一步一步来即可，下面主要记录本地使用时的一些命令

本地安装的时候，最好用 brew install ruby 更新一下，最新版ruby安装完成之后，会提示你最新版本安装在`/usr/local/opt/ruby/bin`目录下面。原来的旧版仍然在`/usr/bin`下面

可以修改环境变量PATH的值，将新版本的路径在查找路径中前置。修改~/.bash_profile文件，如下：

    export PATH=/usr/local/opt/ruby/bin:$PATH

修改后`source ~/.bash_profile`或者重新打开一个Terminal，新版Ruby就生效了。

可以通过`ruby --version`查看版本号

### Create a Post

Create posts easily via rake task:

    $ rake post title="Hello World"

The rake task automatically creates a file with properly formatted filename and YAML Front Matter. Make sure to specify your own title. By default, the date is the current date.

The rake task will never overwrite existing posts unless you tell it to.

### Create a Page

Create pages easily via rake task:

    $ rake page name="about.md"

Create a nested page:

    $ rake page name="pages/about.md"

Create a page with a "pretty" path:

    $ rake page name="pages/about"
    # this will create the file: ./pages/about/index.html

The rake task automatically creates a page file with properly formatted filename and YAML Front Matter as well as includes the Jekyll Bootstrap "setup" file.

### Publish

After you've added posts or made changes to your theme or other files, simply commit them to your git repo and push the commits up to GitHub.

    $ git add .
    $ git commit -m "Add new content"
    $ git push origin master

A GitHub post-commit hook will automatically deploy your changes to your hosted blog. You will receive a success or failure notice for every commit you make to your blog.

### Customize

Jekyll-Bootstrap can be used as-is as a basic blogging platform. However there are plenty of ways to dig into deeper customization. The following outlines deeper Jekyll-Bootstrap customization techniques:

#### Themes

Jekyll-Bootstrap supports modular theming. Themes can co-exist and be enabled/disabled on demand. Editing, configuring, and creating themes is docummented in the Theming section.

#### Blog Configuration

Jekyll and Jekyll-Bootstrap has a simple but powerful Jekyll Configuration System. You can:

+ Specify a custom permalink format for blog posts.
+ Specify a commenting engine like disqus, intensedebate, livefyre, or custom.
+ Specify an analytics engine like google, getclicky, or custom.

#### Programming Interface

The API pages document main data-structures and code available for use in Jekyll and Jekyll-Bootstrap. Consult these pages for how and where to use the data and code provided.

折腾了半天发现还是不好用，弃坑
