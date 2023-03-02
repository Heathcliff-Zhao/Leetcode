#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>arr(n);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i])
                continue;
            cnt++;
            for (int j = i; j < n; j += i)
                arr[j] = true;
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().countPrimes(n) << endl;
}
