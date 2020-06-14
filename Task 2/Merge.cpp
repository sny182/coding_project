// Merge.cpp:
// The aim of this implementation is to merge intervals of a given list of intervals.
// It consists of 4 functions:
//                              1) readIntervals    - defines a list of intervals to be merged.
//                              2) sortInvtervals   - sorts the list of intervals from minimum to maximum boundaries.
//                              3) mergeIntervals   - merges intervals with overlapping areas.
//                              4) main             - this is the main function to exectute the mentioned functions.
//
// by Senay Karaali
// 14.06.2020

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Defines and returns a list of intervals to be merged.
vector<vector<int>> readIntervals()
{
    // Option 1
    //vector<vector<int>> input{ { 25, 30 },
    //                          { 2,  19 },
    //                          { 14, 23 },
    //                          { 4,  8  } };

    // Option 2
    vector<vector<int>> input{ { 25, 30 },
                               { 33, 38 },
                               { 3,  19 },
                               { 50, 55 },
                               { 55, 70 },
                               { 38, 50 },
                               { 32, 39 },
                               { 1,  2  },
                               { 40, 60 },
                               { 14, 23 },
                               { 4,  8  } };

    return input;
}

// Sorts the list of intervals from minimum to maximum boundaries.
// Input:   list with unsorted intervals
// Output:  list with sorted intervals
vector<vector<int>> sortIntervals(vector<vector<int>> input)
{
    // initialize variables for sorting of input vector
    int rows = input.size();
    int cols = 2; // intervals always consist of 2 values
    vector<vector<int>> sorted(rows, vector<int>(cols, 0)); // initialize vector for storing sorted intervals
    int min_tmp = 0;

    for (int i = 0; i < rows ; i++)
    {
        int min = input[0][0]; // lower boundary of interval
        int j_row = 0;

        for (int j = 0; j < input.size(); j++)
        {
            // determine min value of remaining input list and its index
            min_tmp = input[j][0];
            if (min_tmp < min)
            {
                min = min_tmp;
                j_row = j;
            }
        }
        // cout << "Minimum value is: " << min << " in row: " << j_row << endl;
        // copy new found minimum value with its corresponsing interval to sorted list
        sorted[i][0] = input[j_row][0];; sorted[i][1] = input[j_row][1];
        // delete recently found row with minimum value
        input.erase(input.begin() + j_row);
    }
    return sorted;
}

// Merges intervals with overlapping areas.
// Input:   list with sorted intervals
// Output:  list with merged intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> sorted)
{
    // initialize variables for sorting of input vector
    int rows = sorted.size();
    int cols = 2; // intervals always consist of 2 values

    // initialize vector with 1 row
    vector<vector<int>> merged(1, vector<int>(cols, 0));
    // copy entries of first row
    merged[0][0] = sorted[0][0]; merged[0][1] = sorted[0][1];

    // initialize variables for merging intervals
    int j = 0;
    int lb_tmp_1 = 0; // lower boundary
    int ub_tmp_1 = 0; // upper boundary
    int lb_tmp_2 = 0;
    int ub_tmp_2 = 0;

    for (int i = 0; i < (sorted.size()-1); i++)
    {
        // extract current interval for comparison
        lb_tmp_1 = merged[j][0];
        ub_tmp_1 = merged[j][1];

        // extract next interval for comparison
        lb_tmp_2 = sorted[i+1][0];
        ub_tmp_2 = sorted[i+1][1];

        // case 1: next interval within current interval
        //         new upper boundary
        if ((lb_tmp_2 <= ub_tmp_1) && (ub_tmp_2 > ub_tmp_1))
            merged[j][1] = ub_tmp_2;

        // case 2: next interval not within current interval
        //         add new row to list
        if (lb_tmp_2 > ub_tmp_1)
        {
            j = j + 1;
            merged.push_back({ lb_tmp_2 , ub_tmp_2 });
        }
    }
    return merged;
}


int main(void)
{
    // for time measurement
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // create list with intervals
    vector<vector<int>> input   = readIntervals();

    // sort list with intervals from minimum to maximum
    vector<vector<int>> sorted  = sortIntervals(input);

    // merge intervals
    vector<vector<int>> merged  = mergeIntervals(sorted);

    // display the result
    for (int i = 0; i < merged.size(); i++)
    {
        for (int j = 0; j < merged[i].size(); j++)
            cout << merged[i][j] << " ";
        cout << endl;

    }

    // for time measurement
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Merging took "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << "us.\n";
    return 0;
}