# -- coding: utf-8 --

tenThings = "Apples Orages Crows Telephone Light Sugar"

print "Wait there's not 10 things in that list, let's fix that."

stuff = tenThings.split(' ')
moreStaff = ["Day", "Night", "Song", "Frisbee", "Corn", "Banana", "Girl", "Boy"]

while len(stuff) != 10:
    nextOne = moreStaff.pop()
    print "Adding: ", nextOne
    stuff.append(nextOne)
    print "There's %d items now." % len(stuff)

print "There we go: ", stuff

print "Let's do some things with stuff."

print stuff[1]
print stuff[-1] # whoa! fancy
print stuff.pop()
print ' '.join(stuff) # what? cool!
print '#'.join(stuff[3:5]) # super stellar!

