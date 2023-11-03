#!/bin/sh

 #starting the interpreter (sh) 

file_one="$1"
file_two="$2"

#if output file is a directory, make a new file with the same
#name as "file_one", and refer to file_two as this new file
if [ -d "$file_two" ]; then
  file_two="$file_two/$(basename "$file_one")"
fi
#Read the content from file_one and pipe the output to tee.
#Tee reads the input and writes the data in file_two
#File_two is printed in the terminal by default
cat "$file_one" | tee "$file_two"



