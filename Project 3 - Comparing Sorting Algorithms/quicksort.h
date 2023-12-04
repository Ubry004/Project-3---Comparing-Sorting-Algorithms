// by Brynn Li

#include <iostream>
#include <vector>
#include <string>

// Descending
int partitionD(std::vector<std::pair<std::string, std::string>> &data, int left, int right)
{
    // set pivot position (the middle)
    std::pair<std::string, std::string> pivot = data[left + (right - left) / 2];

    int i = left, j = right;
    std::pair<std::string, std::string> temp;

    while (i <= j)
    {
        while (stod(data[i].second) < stod(pivot.second))
        {
            i++;
        }
        while (stod(data[j].second) > stod(pivot.second))
        {
            j--;
        }
        if (i <= j)
        {
            // swap values
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            // increment/decrement i and j
            i++;
            j--;
        }
    }
    return i;
}

std::vector<std::pair<std::string, std::string>> quicksortD(std::vector<std::pair<std::string, std::string>> &data, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partitionD(data, left, right);
        quicksortD(data, left, pivotIndex - 1);
        quicksortD(data, pivotIndex, right);
    }
    return data;
}

// Ascending
int partitionA(std::vector<std::pair<std::string, std::string>> &data, int left, int right)
{
    // set pivot position (the middle)
    std::pair<std::string, std::string> pivot = data[left + (right - left) / 2];

    int i = left, j = right;
    std::pair<std::string, std::string> temp;

    while (i <= j)
    {
        while (stod(data[i].second) > stod(pivot.second))
        {
            i++;
        }
        while (stod(data[j].second) < stod(pivot.second))
        {
            j--;
        }
        if (i <= j)
        {
            // swap values
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            // increment/decrement i and j
            i++;
            j--;
        }
    }
    return i;
}

std::vector<std::pair<std::string, std::string>> quicksortA(std::vector<std::pair<std::string, std::string>> &data, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partitionA(data, left, right);
        quicksortA(data, left, pivotIndex - 1);
        quicksortA(data, pivotIndex, right);
    }
    return data;
}