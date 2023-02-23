#include <iostream>
using namespace std;

class Solution1 {
public:
    long long uniquePaths(int m, int n) {
        long long prod = 1;
        if (m < n) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        for (int i = m; i <= m+n-2; i++)
            prod *= i;
        for (int i = 1; i <= n - 1; i++)
            prod /= i;
        return prod;
    }
};

class Solution2 {
public:
    long long uniquePaths(int m, int n) {

    }
private:
    int dp[210][210] = { 0 };
};

int main()
{
    int m = 16, n = 16;
    cout << Solution1().uniquePaths(m, n) << endl;
}
