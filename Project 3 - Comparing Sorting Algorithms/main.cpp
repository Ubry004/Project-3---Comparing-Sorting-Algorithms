#include "data.h"
#include "sort.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

//TODO:
/*
* Data I/O might be buggy, check & test
* Implement sorting algorithms using data
* Compare sorting algorithms and output to console
* (add other stuff here)
*/

////////////////////// Helper Functions //////////////////////
// use to sort by second index in pairs
bool sortAscending(const pair<string,string> &a, const pair<string,string> &b)
{
    return (a.second > b.second); // > = greatest to least, < = least to greatest
}

bool sortDescending(const pair<string,string> &a, const pair<string,string> &b)
{
    return (a.second < b.second);
}

// checks to see if data is a valid number (ex: some parts of data have 'N/A' written)
bool validNum (const string &str)
{
    for (auto const& c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

////////////////////// Main //////////////////////
int main()
{
    /////// Reading File ///////
    ifstream file;
  
    // Open an existing file & take buffer
    file.open("VideoGames.csv", ifstream::in); 
    string line;
    getline(file,line);

    // Reading file into a stream, then reading stream
    string name;
    string year;
    string na_sales;
    string eu_sales;
    string jp_sales;
    string other_sales;
    string global_sales;

    vector<pair<string,string>> yearData;
    vector<pair<string,string>> NAData;
    vector<pair<string,string>> EUData;
    vector<pair<string,string>> JPData;
    vector<pair<string,string>> OtherData;
    vector<pair<string,string>> GlobalData;

    while (getline(file,line))
    {
        stringstream ss(line);

        getline(ss, name, ',');

        getline(ss, year, ',');
        getline(ss, na_sales, ',');
        getline(ss, eu_sales, ',');
        getline(ss, jp_sales, ',');
        getline(ss, other_sales, ',');
        getline(ss, global_sales, ',');

        if (validNum(year))
            yearData.push_back({name,year});

        NAData.push_back({name, na_sales});
        EUData.push_back({name, eu_sales});
        JPData.push_back({name, jp_sales});
        OtherData.push_back({name, other_sales});
        GlobalData.push_back({name, global_sales});
    }

    /////// Using Data ///////

    // adjust based on what we're doing, for now manually do it but later we can do actual input and formatting and stuff
    string category = "NA Data";
    string order = "Descending";
    vector<pair<string, string>> data = NAData;

    
    cout << "------------ Sorting by " << category << " - " << order << " ------------" << endl;

    // TODO: Insert Sorting Algorithm Here (sort by second value in pairs)
    auto start = chrono::steady_clock::now();

    sort(data.begin(),data.end(), sortAscending); // placeholder, change with actual implemented sorting algo

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Duration: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    // For testing, adjust with how many values you want to see
    for (int i = 0; i < 50; i++)
    {
        cout << data[i].first << ", " << data[i].second << endl;
    }

    return 0;

}