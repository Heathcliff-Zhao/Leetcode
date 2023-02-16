#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 0x7fffffff
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0, q = 1, len = nums.size();
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[q] == nums[p]) {
                nums[q] = maxn;
                q += 1;
                len -= 1;
            }
            else {
                p = q;
                q += 1;
            }
        }
        sort(nums.begin(), nums.end());
        return len;
    }
};

int main()
{
    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    cout << Solution().removeDuplicates(nums) << endl;
}
