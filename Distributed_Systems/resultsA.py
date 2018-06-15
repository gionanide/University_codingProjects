#!usr/bin/python
import sys


def readFiles():
	#take the first argument after the script command
	inputA = sys.argv[1]
	#take the second argument 
	inputB = sys.argv[2]
	#take the third argument to write the results
	#outFile = sys.argv[3]

	fileA = open(inputA,'r')
	fileB = open(inputB,'r')
	#results = open(outFile,'w')

	dictA = dict()
	dictB = dict()
	#make the dictionaries to compare them
	for x in fileA:
		key = x.split()[0]
		value = x.split()[1]
		dictA[key]=[value]
	for x in fileB:
		key = x.split()[0]
		value = x.split()[1]
		dictB[key]=[value]

	for key in dictA.keys():
		if key in dictB:
			print key,dictA[key]
			month,hashtag = key.split('#')
			hashtag = '#'+hashtag
			month = checkMonthA(int(month))
			if dictA[key][0]>dictB[key][0]:
				print ('{0}\t{1}\t{2}\n'.format(month,hashtag,'A'))
			elif dictA[key][0]<dictB[key][0]:
				print ('{0}\t{1}\t{2}\n'.format(month,hashtag,'B'))
			else:
				print ('{0}\t{1}\t{2}\n'.format(month,hashtag,'AB'))
				


#convert month to numerical
def checkMonthA(findMonth):
	if(findMonth == 1):
		return 'Jan'
	if(findMonth == 2):
		return 'Feb'
	if(findMonth == 3):
		return 'Mar'
	if(findMonth == 4):
		return 'Apr'
	if(findMonth == 5):
		return 'May'
	if(findMonth == 6):
		return 'Jun'
	if(findMonth == 7):
		return 'Jul'
	if(findMonth == 8):
		return 'Aug'
	if(findMonth == 9):
		return 'Sep'
	if(findMonth == 10):
		return 'Oct'
	if(findMonth == 11):
		return 'Nov'
	if(findMonth == 12):
		return 'Dec'

readFiles()
