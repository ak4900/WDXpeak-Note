# -- coding: utf-8 --


print "How old are you?",
age = raw_input()
print "How tall are you",
height = raw_input()
print "How much do you weight?",
weight = raw_input()

print "So, you're %r old, %r tall and %r heavy." % (age, height, weight)

# 在每行后面加逗号，这样的话print就不会输出新行符而结束这一行跑到下一行去
