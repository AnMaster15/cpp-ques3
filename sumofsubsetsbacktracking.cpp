#include <iostream>
#include <vector>
using namespace std;

void subsetsum_Backtracking(int Set[], int pos, int sum, int tmpsum, int size, bool &found, vector<int> &subset)
{
    if (sum == tmpsum)
        found = true;

    for (int i = pos; i < size; i++)
    {
        if (tmpsum + Set[i] <= sum)
        {
            tmpsum += Set[i];
            subset.push_back(Set[i]); 

            subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found, subset);
            if (found) 
                return;

            tmpsum -= Set[i];
            subset.pop_back(); 
        }
    }
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    int n = sizeof(set) / sizeof(set[0]);
    bool f = false;
    vector<int> subset;
    subsetsum_Backtracking(set, 0, sum, 0, n, f, subset);
    if (f) {
        cout << "Subset with the given sum found: ";
        for (int i = 0; i < subset.size(); ++i)
            cout << subset[i] << " ";
        cout << endl;
    } else {
        cout << "No required subset found" << endl;
    }
    return 0;
}
