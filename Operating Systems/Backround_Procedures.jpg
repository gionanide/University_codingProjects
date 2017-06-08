#!/bin/bash


initialize()
{
 rm -f pids.txt # delete the existing files of previous executions
 rm -f pids2.txt
 rm -f statistics.txt
 ps axf | grep chromium-browser | grep -v grep | awk '{print "kill -9 " $1}' | sh #kill all chromium processes
 touch pids.txt # make a list with pids in a file
}

openTabs()
{
chromium-browser & #call chromium browser with out argument
count=0 #count the URL in the url.in file

while read line; #start to read the url.in file

do
  count=$(( $count+1))

  if((count>5));then #check the number of the urls

         echo "Maximum number reached"

         break;
  fi

done < url.in

echo "Count variable is:  $count"

if (( count <= 5));then

        echo "URL list  is ok"

        while read line; do #call chromium browser for each url in the file
                sleep 10 #sleep 10 sec and then continue
                ps axf | grep chromium-browser | grep -v grep | awk '{print$1}'> pids.txt # write the pids which concern chromium the exact time
                chromium-browser "$line" & #open the chromium with url for argument
ps axf | grep chromium-browser | grep -v grep | awk '{print$1}'> pids.txt
else
echo"URL list  is not ok" # if the urls are above a specific number (in our case 5) the script takes you in the url.in file in order to delete some urls

        nano url.in
fi

}

closeTabs(){
end=0
while((end==0));do
   pkill -n -f chromium-browser #kills the newest chromium's process
   end=$? # return the exit  status of previous command
   sleep 10 #sleep 10 sec
   ps axf | grep chromium-browser | grep -v grep | awk '{print$1}'> pids.txt  #refresh pids list
   # echo >> pids.txt
done
}



Statistics(){
times=0.5 # timer
while true;do
  sleep 0.5 # in order to call and enable the function every 0.5 sec
  sum=0 # sum RSS  counter
  sumline=0 # pids counter every time, the function is called
  ps axf | grep chromium-browser | grep -v grep | awk '{print$1}'> pids2.txt #write the temporary pids in a file
  while read line;do
     x=$(ps -o rss $line) # tame the RSS memory in MBs
     y="${x//[!0-9]/}" # and start the counting
     sum=$((sum+y))
     sumline=$((sumline+1))
  done < pids2.txt # read pids from the pid2 file
  echo "$times   $sumline   $sum" >>statistics.txt
  echo>>statistics.txt
  times=`echo $times + 0.5 | bc` # make the timer
done
}

# calling functions

initialize
openTabs #create processes
Statistics & #statistics function runs in the backround and stops when the create and terminate processes complete
MYSELF=$!
closeTabs #terminate processes
kill MYSELF >/dev/null 2>&1
