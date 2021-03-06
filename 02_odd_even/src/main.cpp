#include <stdio.h>

#include <iostream>
#include <string>
#include <stdlib.h>

bool check_isDigit(std::string str)
{
	for (int i = 1; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool check_negNumber(std::string str)
{
	char s = '-';
	for (int contor = 0; contor < str.length(); contor++)
	{
		if (str[0] == s && check_isDigit(str) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool check_pozNumber(std::string str)
{
	if (check_negNumber(str) == false)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]) == false)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}


//I've been modified this function as you can see; now it takes a string as a parameter because I had to consider the case when the user
//types non-numerical characters
void printOddOrEven(std::string str) 
{
	if (check_pozNumber(str) == true || check_negNumber(str) == true)
	{
		int number;
		number = std::stoi(str);
		if (number % 2 == 0)
		{
			printf("EVEN\n");
		}
		else
		{
			printf("ODD\n");
		}
	}
	else
	{
		printf("NAN");
	}
	
}


int main(int argc, char *argv[])
{

	//int number = -13; 
	
	// What is this program expected to do?
	// - Shows whether an argument is an ODD or EVEN number.
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  02_odd_even.exe 1		=> Output: ODD
	//		  02_odd_even.exe 2		=> Output: EVEN
	//		  02_odd_even.exe 		=> Output: No program arguments found.
	//		  02_odd_even.exe ABC   => Undefined output (do whatever).
	//		

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}
	
	// TODO(Gusti): i don't know why this doesn't work, but someone please FIX it. 

	// --------------- start

	// Get the first argument
	std::string argumentAsString = argv[1]; 
	const char* argumentAsCharArray = argumentAsString.c_str();

	//number = argv[1]; // No
	//should use atoi?
	// or std::stoi?
		
	printOddOrEven(argv[1]);
	
	
	std::cout << argumentAsString << std::endl; // i think this should be removed ---> I've left this row for the user to see what number/character has been introduced
	

	// --------------- stop

	

	return 0;
}