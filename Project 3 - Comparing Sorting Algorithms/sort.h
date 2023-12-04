#pragma once
#include <vector>
#include <string>
using namespace std;
// Merge Sort, Shell Sort, and Quick Sort

// Kamron - Merge Sort
void MergeSortedIntervals(vector<pair<string, string>>& vec, int start, int mid, int end);
vector<pair<string, string>> MergeSort(vector<pair<string, string>> vec, int start, int end, string order);

// Zach - Shell Sort
vector<pair<string, string>> ShellSortA(vector<pair<string, string>> vec);
vector<pair<string, string>> ShellSortD(vector<pair<string, string>> vec);