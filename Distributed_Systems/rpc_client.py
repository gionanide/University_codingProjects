#!usr/bin/python
import xmlrpclib
import sys

#input format
# -----------------------------> client.py operator(pow,add,minus,divide) firstNumber secondNumber <---------------------

#take the inputs from the terminal
operator = sys.argv[1]
x = sys.argv[2]
y = sys.argv[3]

#check if the input is actually a number
def checkNumber(x):
	try:
   		val = int(x)
	except ValueError:
   		print("That's not an int!")

#talk to the server
server = xmlrpclib.ServerProxy('http://localhost:8000')
#check the validity of the operator
if checkNumber(x) and checkNumber(y):
	if (operator=='divide'):
		print server.divide(int(x),int(y))
	elif (operator=='minus'):
		print server.minus(int(x),int(y))
	elif (operator=='add'):
		print server.add(int(x),int(y))
	elif (operator=='power'):
		print server.power(int(x),int(y))
	else:
		print 'Invalid operator'


