#!usr/bin/python
import sys

def readFiles():
	resultsA = sys.argv[1]
	resultsB = sys.argv[2]
	resultsC = sys.argv[3]
	#finalResults = sys.argv[4]
	#logic: make three dictionaries, one for each file, then we compare the keys and if the keys are the same we append the values to 
	#the new dictionary
	reduceA = open(resultsA,'r')
	reduceB = open(resultsB,'r')
	reduceC = open(resultsC,'r')
	#finalResults = open(finalResults,'w')
	reducer(reduceA,reduceB,reduceC,finalResults)


def reducer(reduceA,reduceB,reduceC,finalResults):
	dictA=dict()
	for x in reduceA:
		dictA[x.split()[0]] = x.split()[1:]
	for y in reduceB:
		key = y.split()[0]
		if(key in dictA):
			value = y.split()[1:] + dictA[key]
			dictA[key] = [value]
		else:
			dictA[key] = [y.split()[1:]]
	for y in reduceC:
		key = y.split()[0]
		if(key in dictA):
			value = y.split()[1:] + dictA[key][0]
			dictA[key] = [value]
		else:
			dictA[key] = [y.split()[1:]]
	for y in dictA:
		print ('{0}\t{1}\n'.format(y," ".join(map(str, dictA[y][0]))))
	
	

readFiles()
