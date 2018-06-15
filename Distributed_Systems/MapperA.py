#!usr/bin/python
import sys

def mapper(fileInput,fileComing):
	if(fileComing=='A'):
		#split based on gap
		arrayGap = fileInput.split()
		takeMonth = arrayGap[0]
		takeHashCount = arrayGap[1]
		#find the month, change name to number
		findMonth = takeMonth.split('-')
		month = checkMonthA(findMonth[0])
		#split hashtag and count
		splitHC = takeHashCount.split(',')
		hashtag = splitHC[0]
		count =  splitHC[1]
		return hashtag,count,month
	elif(fileComing=='B'):
		arrayGap = fileInput.split()
		count = arrayGap[1]
		hashtag,month = arrayGap[0].split(',')
		hashtag = hashtag
		month = month.split('/')[1]
		return hashtag,count,month

def openFiles():
	#outFile = sys.argv[1]
	fileComing = raw_input('Give the name of the file you want to read A/B: ')
	fileA  = open('mapreduce1_platform'+fileComing+'.txt','r')
	dictA = dict()
	mapperFile  = open(outFile, 'w')
	for x in fileA:
		#mapreduce1_platformA.txt
		hashtag,count,month = mapper(x,fileComing)
		#append in a dictionary, hashatag = key , count,month = value
		key = str(month)+hashtag
		dictA[key]=[count]
		#print('{0}\t{1}'.format(key,dictA[key][0]))
		print ('{0}\t{1}\n'.format(key,dictA[key][0]))
	


#convert month to numerical
def checkMonthA(findMonth):
	if(findMonth == 'Jan'):
		return 1
	if(findMonth == 'Feb'):
		return 2
	if(findMonth == 'Mar'):
		return 3
	if(findMonth == 'Apr'):
		return 4
	if(findMonth == 'May'):
		return 5
	if(findMonth == 'Jun'):
		return 6
	if(findMonth == 'Jul'):
		return 7
	if(findMonth == 'Aug'):
		return 8
	if(findMonth == 'Sep'):
		return 9
	if(findMonth == 'Oct'):
		return 10
	if(findMonth == 'Nov'):
		return 11
	if(findMonth == 'Dec'):
		return 12

openFiles()
