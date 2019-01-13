#!/bin/bash

function fibonacci(){
echo -n "How many numbers of the sequence would you like?"
  read num

f1=0 #initialize the first numbers of the sequence
f2=1

echo -n "The fibonacci sequence for the number $num  is :"

for((i=0;i<num;i++)) # start the fibanacci
do
    echo -n "$f1 " # print the number
    fn=$((f1+f2)) # and the two previous numbers
    f1=$f2
    f2=$fn
done

echo -n
}

# fibanacci function

fibonacci
