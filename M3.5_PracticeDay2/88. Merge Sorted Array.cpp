#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> copy = nums1;
        copy.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        int lp = 0, rp = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (copy[lp] <= nums2[rp])
            {
                nums1[i] = copy[lp];
                lp++;
            }
            else
            {
                nums1[i] = nums2[rp];
                rp++;
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            cout << copy[i] << " ";
        }
    }
};

int main()
{

    return 0;
}