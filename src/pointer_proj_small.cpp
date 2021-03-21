//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : Ryan Aruanno
// Version     : 03172021
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"
using namespace KP;

int main(int argc, char *argv[]) {
	if (argc == 1 && *argv[0] == HELP_CHAR) {
		cout << HELP_STRING1 << endl;
		cout << HELP_STRING2 << endl;
		return SUCCESS;
	}
	else if (argc != EXPECTED_NUMBER_ARGUMENTS) {
		cout << HELP_STRING2 << endl;
		return FAIL_WRONG_NUMBER_ARGS;
	}
	else {
		string inputfile = argv[1];
		string outputfile = argv[2];
		string tag = argv[3];
		string replacement_tag = argv[4];
		string string1 = "";
		int str_len = strlen(string1.c_str());
		int tag_len = strlen(tag.c_str());
		int tag_replacement_len = strlen(replacement_tag.c_str());
		readFile(inputfile, string1);
		char *string2 = new char[amountOfMemoryToAllocateForNewString(str_len, findNumbOccurrences(string1.c_str(), tag.c_str()), tag_len, tag_replacement_len)];
		replace(string1.c_str(), string2, tag.c_str(), replacement_tag.c_str());
		int output = writeFile(outputfile, string2);
		delete[] string2;
		return output;
	}
	return SUCCESS;
}
