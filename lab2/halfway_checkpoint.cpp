#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){ 
	string ans;
	cout << "Would you like to use input from STDIN or from a text file? Enter 0 or 1 respectively\n";
	cout << "0: STDIN\n";
	cout << "1: Text file\n";
	
	while(true){ //Loop until we get a valid input
	cin >> ans; 
	

	if(ans == "0"){ //STDIN
	cout << "Input three random numbers\n";
	int n1, n2, n3;
	cin >> n1;
	cin >> n2;
	cin >> n3;
	//also possible in one line by using: "std::cin >> n1>> n2>> n3;"
	
	int randNumArray[] = {n1, n2, n3};
	int randNumArrayLength = 3;
	
	sort(begin(randNumArray), end(randNumArray)); //Sort array
	ofstream myOutputStream; //storing result in text file "halfway_output.txt"
	myOutputStream.open("halfway-output.txt");
	for (int i = 0; i < randNumArrayLength; i++){
	myOutputStream<<randNumArray[i] << " ";
	cout << randNumArray[i] << " ";
	}
	cout << "\n";
	myOutputStream.close();
	break;
	}
	
	else if (ans == "1"){ //Text file
<<<<<<< HEAD
	
	std::string input_read; //declaring a variable to store the content of the file in
	ifstream myInputStream; //using file streams, declare string variable name
	myInputStream.open("halfway-input.txt"); //reading file and storing in "myInputStream"
	//storing the input in variable without using >> for many words:
	myInputStream>>input_read; //for the first word of the input file
	while (!myInputStream.eof()) //negotiation, it must be true, if no more words to be read -> if false, its not the end, it continues
	 {  
	 	std::cout<<input_read<<std::endl; //prints the words and then proceed with the next one
		myInputStream>>input_read;
	 }
	myInputStream.close();

	
	// INPUT_STREAM_NAME].eof() function returns ‘true’ if ‘End Of File’ is reached, and returns ‘false’ otherwise.)
	
	// input file stored in same directory. 
	//TODO: Read all the contents from a file named “halfway-input.txt” found in the repository, and print them to the console
=======
	//TODO: Read all the contents from a file named “halfway-input.txt” found in the repository; and print them to the console
>>>>>>> feature/task2
	
	break;
	}
	cout << "Unvalid input\n";
	}
	return 0;	
}
