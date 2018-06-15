#!usr/bin/python
import sys

def readFile():
	inputFile = sys.argv[1]
	#outputFile = sys.argv[2]
	print inputFile,outputFile
	fileRead = open(inputFile,'r')
	#fileWrite = open(outputFile,'w')
	dictA=dict()
	mapper(dictA,fileRead,fileWrite)
	


def mapper(dictA,fileRead,fileWrite):
	for x in fileRead:
		tvshow,channel = x.split(',')
		if tvshow in dictA.keys():
			dictA[tvshow].append(channel[:-1])
		else:
			dictA[tvshow]=[channel[:-1]]
	for key in dictA.keys():
		print ('{0}\t{1}\n'.format(key," ".join(map(str, dictA[key]))))
		


readFile()
