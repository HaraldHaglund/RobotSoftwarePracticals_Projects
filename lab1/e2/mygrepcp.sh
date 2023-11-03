#!/bin/sh

inp_dir="$1"
word="$2"
outp_dir="$3"
# Assume the output directory already exists.

#Finds all the .txt files within the input directory (and stores them in {})
#Executes grep on all the found files, and searches for "word" within said files
#Separate the exec commands with \; 
#the next exec command copies the files to output_dir
find "$inp_dir" -name "*.txt" -exec grep "$word" {} \; -exec cp {} "$outp_dir" \;

# with "grep -H" the file information could be also displayed
# with "grep -q" there is no further explanation displayed
# example from skript:find /bin -exec grep -H "# Copyright" \{} \;






