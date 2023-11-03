#!/bin/sh



#Simple stepwise solution:

df -hT $HOME > info.txt    #firt store the information in a text file
grep "G" info.txt > info2.txt   #store only the second row  in another file
cut -d' ' -f15- info2.txt > info3.txt #delete the first 15 columns 
cut -c 1-3 info3.txt #this command  keeps the first 3 characters and remove the characters onwards
