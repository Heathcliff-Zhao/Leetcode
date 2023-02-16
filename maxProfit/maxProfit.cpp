#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.insert(prices.end(), -0x7fffffff);
        int m = 0, p = 0, q = 1, sum = 0;
        bool mark = true;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[p] > prices[q]) {
                sum += (prices[q - 1] - prices[m]);
                p = q;
                m = p;
                mark = false;
            }
            else {
                p += 1;
            }
            q += 1;
        }
        if (mark)
            sum = prices[prices.size() - 1] - prices[0];
        return sum;
    }
};

int main()
{
    vector<int>prices = { 6,1,3,2,4,7 };
    cout << Solution().maxProfit(prices) << endl;
}
