NOTE: All exercises scripts are inside the folders e1->e5 respectively, together with some test files.
For detailed information on how each exercise was solved, there are several comments added in the scripts.
Before running the scripts, change the permission by using: "chmod ugo+rwx filename"

*********************************************
Exercise 1:"mycp"

Description:
./mycp.sh <InputFile> <OutputFile>
Is used to copy the input file to another file , or a directory 

Arguments:
<InputFile>
<OutputFile>/<OutputDirectory>

Example 1:
./mycp.sh Input_File Directory
*Copies Input_File to Directory*

Example 2:
./mycp.sh File1 File2
*Copies content from File1 to File2. Overwrites all content from File2*
*********************************************
Exercise 2:"mygrepcp"

Description: 
./mygrepcp.sh <InputDirectory> <Query> <OutputDirectory> 
Takes an <InputDirectory>, and copies all the txt files containing the string <Query> to the <OutputDirectory>

Arguments:
<InputDirectory>
<Query> (String)
<OutputDirectory>

Example 1:
./mygrepcp.sh ~/Downloads "one" ~/Desktop
*All the txt files inside Downloads containing the word "one" gets copied to the Desktop*
**********************************************
Exercise 3:"mydf"

Description:
./mydf.sh
Displays the amount of free space in Gibibytes on the disk of the root directory

Example 1:
./mydf.sh
*"20G" is displayed in the terminal*
**********************************************
Exercise 4:"killme"

Description:
./killme.sh <username>
Terminates all processes for <username> (Note that this will shut down your PC)

Example 1:
./killme.sh hhaglund
*Ends all processes for user hhaglund*
**********************************************
Exercise 5:"readnews"

Description:
./readnews.sh
Displays the current headlines on Dutch Teletekst in the terminal
Make sure to have lynx installed (sudo apt-get install lynx)

Example 1:
./readnews.sh
*Prints the headlines in the terminal*

Required installation for using the "lynx" command: sudo apt-get install lynx
**********************************************
