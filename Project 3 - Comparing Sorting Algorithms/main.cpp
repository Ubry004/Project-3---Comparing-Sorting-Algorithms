#include "data.h"
#include "sort.h"

#include <iostream>
#include <iomanip>
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
    getline(file, line);

    // Reading file into a stream, then reading stream
    string name;
    string year;
    string na_sales;
    string eu_sales;
    string jp_sales;
    string other_sales;
    string global_sales;

    vector<pair<string, string>> yearData;
    vector<pair<string, string>> NAData;
    vector<pair<string, string>> EUData;
    vector<pair<string, string>> JPData;
    vector<pair<string, string>> OtherData;
    vector<pair<string, string>> GlobalData;

    while (getline(file, line))
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
            yearData.push_back({ name,year });

        NAData.push_back({ name, na_sales });
        EUData.push_back({ name, eu_sales });
        JPData.push_back({ name, jp_sales });
        OtherData.push_back({ name, other_sales });
        GlobalData.push_back({ name, global_sales });
    }

    /////// Main Menu Code ///////

    vector<vector<pair<string, string>>> choices = { yearData, NAData, EUData, JPData, OtherData, GlobalData };
    vector<string> categories = { "Name", "Year", "NA Sales", "EU Sales", "JP Sales", "Other Sales", "Global Sales" };

    int choice;
    int category;
    string order;
    cout <<
        "Sorting Algorithm Comparisons!\n" <<
        "In this program you can sort video games by various attributes.\n\n"
        "What do you want to sort by?\n";
    
    cout << endl <<
        "1) Name\n"         <<
        "2) Year\n"         <<
        "3) NA Sales\n"     <<
        "4) EU Sales\n"     <<
        "5) JP Sales\n"     <<
        "6) Other Sales\n"  <<
        "7) Global Sales\n\n";

    cin >> choice;
    if (choice == 1) category = 0;
    category = choice - 2;

    cout << endl <<
        "1) Ascending\n" <<
        "2) Descending\n\n";

    cin >> choice;
    if (choice == 1) order = "Ascending";
    if (choice == 2) order = "Descending";

    /////// Using Data ///////

    // adjust based on what we're doing, for now manually do it but later we can do actual input and formatting and stuff
    //category = "NA Data";
    //order = "Descending";
    vector<pair<string, string>> data = choices[category];

    
    cout << "------------ Sorting by " << categories[category + 1] << " - " << order << " ------------" << endl;

    // TODO: Insert Sorting Algorithm Here (sort by second value in pairs)
    auto start = chrono::steady_clock::now();

    if (order == "Ascending") {
        sort(data.begin(), data.end(), sortAscending); // placeholder, change with actual implemented sorting algo
    }
    else if (order == "Descending") {
        sort(data.begin(), data.end(), sortDescending); // placeholder, change with actual implemented sorting algo
    }

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Duration: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    // For testing, adjust with how many values you want to see
    for (int i = 0; i < 100; i++)
    {
        cout << right << setfill('.') << data[i].second <<  ", " << setw(60) << data[i].first << endl;
    }

    return 0;

}