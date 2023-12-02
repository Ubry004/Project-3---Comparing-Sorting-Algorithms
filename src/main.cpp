#include "data.h"
#include "sort.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//TODO:
/*
* Create dataset using library
* Data I/O
* Implement sorting algorithms using data
* Compare sorting algorithms and output to console
* (add other stuff here)
*/


int main()
{
	// File pointer 
    ifstream str; 
  
    // Open an existing file 
    str.open("VideoGames.csv", ios::in); 
  
    vector<string> result;
    string line;
    getline(str,line);

    stringstream lineStream(line);
    string cell;

    getline(str,line);
	std::cout << line << '\n';


}