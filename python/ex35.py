# -- coding: utf-8 --

from sys import exit

def goldRoom():
    print "This room is full of gold. How much do you take?"

    next = raw_input("> ")
    if "0" in next or "1" in next:
        howMuch = int(next)
    else:
        dead("Man, learn to type a number")

    if howMuch < 50:
        print "Nice, you're not greedy, you win!"
        exit(0)
    else:
        dead("You greedy bastard")


def bearRoom():
    print "There is a bear here."
    print "The bear has a bunch of honey."
    print "The fat bear is in front of another door."
    print "How are you going to move the bear?"
    bearMoved = False

    while True:
        next = raw_input("> ")

        if next == "take honey":
            dead("The bear looks at you then slaps your face off.")
        elif next == "taunt bear" and not bearMoved:
            print "The bear has moved from the door. You can go though it now."
            bearMoved  = True
        elif next == "open door" and bearMoved:
            goldRoom()
        else:
            print "I got no idea what that means."

def cthulhuRoom():
    print "Here you asee the great evil Cthulhu."
    print "He, it, whatever stares at you and you go insane."
    print "Do you flee for your life or eat your head?"

    next = raw_input("> ")

    if "flee" in next:
        start()
    elif "head" in next:
        dead("Well that was tasty!")
    else:
        cthulhuRoom()


def dead(why):
    print why, "Good job!"
    exit(0)

def start():
    print "You are in a dark room."
    print "There is a door to your right and left."
    print "Which one do you take?"

    next = raw_input("> ")

    if next == "left":
        bearRoom()
    elif next == "right":
        cthulhuRoom()
    else:
        dead("You stumble around the room until you starve.")

start()
