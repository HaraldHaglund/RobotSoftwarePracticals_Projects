#!/bin/bash


wget -q http://teletek.st  

# cat index.html
# -q to prevent the output 
# download and display (cat) the website

#how to transform the HTML script to a text file:
# install: sudo apt-get install lynx
# lynx is a web-brwoser, mainly to view web content. It supports HTML and 
# can render HTML pages. 
# lynx -dump index.html > s4.txt


lynx -dump -nonumbers -notitle -nolist -nolog index.html > s4.txt

# dump formats to standard output. e.g. enumerations and symbols disappear
# to remove the ">" symbol:

grep -o '[^>]*' s4.txt | tr -d '>' > s5.txt
sed G s5.txt > s6.txt
# reset line spacing to the origin
cat s6.txt



# in case the ">" symbol appears not in every browser search, you can also
# use the following script:


#if grep ">" s4.txt; then
#   grep -o '[^>]*' s4.txt | tr -d '>' > s5.txt
#   cat e5.txt
#else
#    cat s4.txt
#fi



