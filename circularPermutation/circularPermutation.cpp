#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

    }
};

int main()
{
    int n = 2, start = 3;
    vector<int>nums = Solution().circularPermutation(n, start);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
}
