# -- coding: utf-8 --

cities = {'CA': 'San Francisco', 'MI': 'Detroit', 'FL': 'Jacksonville'}

cities['NY'] = 'New York'
cities['OR'] = 'Portland'

def findCity(themap, state):
    if state in themap:
        return themap[state]
    else:
        return "Not found."

# ok pay attention!
cities['_find'] = findCity

while True:
    print "State? (ENTER to quit)",
    state = raw_input("> ")

    if not state : break

    # this line isi the most important ever! study!
    cityFound = cities['_find'](cities, state)
    print cityFound
