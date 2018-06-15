#!usr/bin/python
import sys

def readFile():	
	#take the first argument after the script command
	fileRead = sys.argv[1]
	#take the second argument 
	#outFile = sys.argv[2]
	fileA = open(fileRead,'r')
	#return the files
	dictA = dict()
	#reducerFile  = open(outFile, 'w')
	for x in fileA:
		key = x.split()[0]
		if key in dictA:
		#if the key already exists, which means that is the same hashtag the same month, we just add the value
		#because we need the month-sum
			count = x.split()[1]
			value = reducer(dictA,key,count)
			dictA[key] = [value]
		else:
		#if the key does not exist, just initialize it
			value = x.split()[1]
			dictA[key] = [value]
	for x in dictA:
		print ('{0}\t{1}\n'.format(x,dictA[x][0]))

def reducer(dictNeural,key,count):
	value = int(dictNeural[key][0]) + int(count)
	return value


readFile()
