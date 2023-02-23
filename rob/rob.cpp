#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        else if (nums.size() == 3)
            return max(nums[1], nums[0] + nums[2]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = max(dp[0] + nums[2], dp[1]);
        int mn = max(dp[0], dp[1]);
        int i = 3;
        for (vector<int>::iterator it = nums.begin() + 3; it != nums.end(); it++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            dp[i] = max(dp[i], dp[i - 3] + nums[i]);
            mn = mn > dp[i] ? mn : dp[i];
            i++;
        }
        return mn;
    }
private:
    int dp[105];
};

int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    cout << Solution().rob(nums) << endl;
}
