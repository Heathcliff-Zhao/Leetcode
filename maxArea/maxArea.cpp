#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans, area);
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};

int main()
{
    vector<int>height;
    int nums[] = { 1,8,6,2,5,4,8,3,7 };
    for (int i = 0; i < sizeof(nums) / 4; i++)
        height.push_back(nums[i]);
    cout << Solution().maxArea(height) << endl;
}