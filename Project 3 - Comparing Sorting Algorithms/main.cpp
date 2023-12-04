#include "quicksort.h"
#include "sort.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

////////////////////// Helper Functions //////////////////////

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
    vector<string> categories = { "Year", "NA Sales", "EU Sales", "JP Sales", "Other Sales", "Global Sales" };

    int choice;
    int dataAmount; // Let the user choose how much data to sort (to speed up sort times)
    int category;
    string order;
    cout <<
        "Sorting Algorithm Comparisons!\n" <<
        "In this program you can sort video games by various attributes.\n\n"
        "What do you want to sort by?\n";
    
    cout << endl <<
        "1) Year\n"         <<
        "2) NA Sales\n"     <<
        "3) EU Sales\n"     <<
        "4) JP Sales\n"     <<
        "5) Other Sales\n"  <<
        "6) Global Sales\n\n";

    cin >> choice;
    if (choice == 1) category = 0;
    category = choice - 1;

    cout << endl <<
        "1) Ascending\n" <<
        "2) Descending\n\n";

    cin >> choice;
    if (choice == 1) order = "Ascending";
    if (choice == 2) order = "Descending";

    cout << endl << "How many data points?\n Choose a number between 1 and 16720\n (More data means longer sort times)\n";

    cin >> choice;
    dataAmount = choice;

    /////// Using Data ///////

    // adjust based on what we're doing, for now manually do it but later we can do actual input and formatting and stuff
    vector<pair<string, string>> data = choices[category];
    vector<pair<string, string>> sorted_data = choices[category]; // Place sorted data here

    // Make the sorted data vector smaller based on dataAmount (erase from the back)
    data.erase(data.begin() + dataAmount, data.end());

    cout << "------------ Sorting by " << categories[category] << " - " << order << " ------------" << endl;

    if (order == "Ascending") {
        // Quicksort - Brynn
        auto start = chrono::steady_clock::now();
        sorted_data = quicksortA(data, 0, data.size() - 1);
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << "Quicksort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Merge Sort - Kamron
        start = chrono::steady_clock::now();
        sorted_data = MergeSort(data, 0, data.size() - 1, order);
        end = chrono::steady_clock::now();
        diff = end - start;
        cout << "Merge Sort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Shell Sort - Zach
        start = chrono::steady_clock::now();
        sorted_data = ShellSortA(data, data.size());
        end = chrono::steady_clock::now();
        diff = end - start;
        cout << "Shell Sort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Insert Other Sorts Here

    }
    else if (order == "Descending") {
        // Quicksort - Brynn
        auto start = chrono::steady_clock::now();
        sorted_data = quicksortD(data, 0, data.size() - 1);
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << "Quicksort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Merge Sort - Kamron
        start = chrono::steady_clock::now();
        sorted_data = MergeSort(data, 0, data.size() - 1, order);
        end = chrono::steady_clock::now();
        diff = end - start;
        cout << "Merge Sort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Shell Sort - Zach
        start = chrono::steady_clock::now();
        sorted_data = ShellSortD(data, data.size());
        end = chrono::steady_clock::now();
        diff = end - start;
        cout << "Shell Sort Duration: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

        // Insert Other Sorts Here
    }

    // For testing, adjust with how many values you want to see
    for (int i = 0; i < dataAmount; i++)
    {
        cout << right << setfill('.') << sorted_data[i].second <<  ", " << setw(60) << sorted_data[i].first << endl;
    }

    return 0;

}