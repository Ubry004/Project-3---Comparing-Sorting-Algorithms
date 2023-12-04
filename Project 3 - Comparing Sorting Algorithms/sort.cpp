#include "sort.h"

#include <vector>
#include <string>
using namespace std;

// Merge Sort, Shell Sort, and Quick Sort

// Kamron - Merge Sort
void MergeSortedIntervals(vector<pair<string, string>>& vec, int start, int mid, int end) {
	vector<pair<string, string>> temp;
	int i, j;
	i = start;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (stof(vec[i].second) <= stof(vec[j].second)) {
			temp.push_back(vec[i]);
			i++;
		}
		else {
			temp.push_back(vec[j]);
			j++;
		}
	}

	while (i <= mid) {
		temp.push_back(vec[i]);
		i++;
	}

	while (j <= end) {
		temp.push_back(vec[j]);
		j++;
	}

	for (int i = start; i <= end; ++i) {
		vec[i] = temp[i - start];
	}
}

// Currently not entirely functional
vector<pair<string, string>> MergeSort(vector<pair<string, string>> vec, int start, int end, string order) {
	vector<pair<string, string>> temp = vec;
	if (start < end) {
		int mid = (start + end) / 2;
		temp = MergeSort(temp, start, mid, order);
		temp = MergeSort(temp, mid + 1, end, order);
		MergeSortedIntervals(temp, start, mid, end);
	}
	return temp;
}

// shell sort
vector<pair<string, string>> ShellSortA(vector<pair<string, string>> vec, int n) {
	for (int gap = vec.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			string name = vec[i].first;
			string xs = vec[i].second;
			float x = stof(vec[i].second);
			int j;
			for (j = i; j >= gap && stof(vec[j - gap].second) > x; j -= gap) {
				vec[j] = vec[j - gap];
			}
			vec[j] = make_pair(name, xs);
		}
	}
	return vec;
}

vector<pair<string, string>> ShellSortD(vector<pair<string, string>> vec, int n) {
	for (int gap = vec.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			string name = vec[i].first;
			string xs = vec[i].second;
			float x = stof(vec[i].second);
			int j;
			for (j = i; j >= gap && stof(vec[j - gap].second) < x; j -= gap) {
				vec[j] = vec[j - gap];
			}
			vec[j] = make_pair(name, xs);
		}
	}
	return vec;
}