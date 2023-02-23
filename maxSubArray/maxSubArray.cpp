#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        dp[0] = nums[0];
        int mn = -0x7fffffff < nums[0] ? nums[0] : -0x7fffffff;
        int i = 1;
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
            int tmp = max(dp[i - 1] + nums[i], nums[i]);
            mn = mn < tmp ? tmp : mn;
            dp[i] = tmp;
            i++;
        }
        return mn;
    }
private:
    int dp[100005];
};

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(8);
    cout << Solution().maxSubArray(nums) << endl;
}
