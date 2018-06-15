#!usr/bin/python
import sys

def readFiles():
	channels = sys.argv[1]
	viewers = sys.argv[2]
	#finalQuestion = sys.argv[3]
	channelsFile = open(channels,'r')
	viewersFile = open(viewers,'r')
	#finalQuestionResults = open(finalQuestion,'w')
	dictC = dict()
	dictV = dict()
	for x in channelsFile:
		#only for the shows that we can watch then to NOX as well
		if ('NOX' in ' '.join(x.split()[1:])):
			dictC[x.split()[0]] =  [' '.join(x.split()[1:])]
	for x in viewersFile:
		element = x.split()
		amount=0
		for x in range(1,len(element)):
			amount+=int(element[x])
		dictV[element[0]]=[amount]

	for x in dictC.keys():
		if x in dictV.keys():
			print ('{0}\t{1}\n'.format(x,dictV[x][0]))
		


readFiles()
