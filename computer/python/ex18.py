# -- coding: utf-8 --

# this one is like your scripts with argv
def printTwo(*args):
    arg1, arg2, arg3 = args
    print "arg1: %r, arg2: %r, arg3: %r" % (arg1, arg2, arg3)

# ok, that *args is actually pointless, we can just do this
def printTwoAgain(arg1, arg2):
    print "arg1: %r, arg2: %r" % (arg1, arg2)

# this just takes one argument
def printOne(arg1):
    print "arg1: %r" % arg1

# this one takes no arguments
def printNone():
    print "I got nothing."

printTwo("Zed", "Shaw", "Extra")
printTwoAgain("Da", "Wang")
printOne("wdxtub")
printNone()
