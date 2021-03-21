#include <fstream>
#include <iostream>
#include "../includes/fileio.h"
#include "../includes/constants.h"
using namespace std;

int writeFile(std::string &filename,char *contents) {
	ofstream output;
	output.open(filename.c_str());
	if (contents == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}
	else {
		output << contents << endl;
		output.close();
		return SUCCESS;
	}
}

int readFile(std::string &filename,std::string &contents) {
	fstream output;
	output.open(filename.c_str(), ios::in);
	if (!output.is_open()) {
		return FAIL_CANNOT_OPEN_FILE;
	}
	else {
		getline(output, contents);
		output.close();
		return SUCCESS;
	}
}
