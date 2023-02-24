#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = 0x7fffffff, sell = 0;
        for (vector<int>::iterator it = prices.begin(); it != prices.end(); it++) {
            buy = buy < *it ? buy : *it;
            res = res < *it - buy ? *it - buy : res;
        }
        return res;
    }
};

int main()
{
    vector<int>prices;
    int nums[] = { 7,6,4,3,1 };
    for (int i = 0; i < 6; i++)
        prices.push_back(nums[i]);
    cout << Solution().maxProfit(prices) << endl;
}
