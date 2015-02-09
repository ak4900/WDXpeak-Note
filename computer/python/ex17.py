# -- coding: utf-8 --

from sys import argv
from os.path import exists

script, fromFile, toFile = argv

print "Copying from %s to %s" % (fromFile, toFile)

# we could do these two on one line too, how?
input = open(fromFile)
indata = input.read()

print "The input file is %d bytes long" % len(indata)

print "Does the output file exist? %r" % exists(toFile)
print "Ready, hit RETURN to continue, CTRL-C to abort."
raw_input()

output = open(toFile, 'w')
output.write(indata)

print "Alright, all done."

output.close()
input.close()
