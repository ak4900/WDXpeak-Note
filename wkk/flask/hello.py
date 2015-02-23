# -*- coding: utf-8 -*-

from flask import Flask
# 创建一个Flask类的实例
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World'



@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name = None):
    return render_template('hello.html', name=name)


@app.route('/user/<username>')
def show_user_profile(username):
    return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
    return 'Post %d' % post_id

if __name__ == '__main__':
    app.run(debug = True)
