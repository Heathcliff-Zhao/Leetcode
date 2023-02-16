#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string res = "";
        int i = 0, first = 0;
        int special = 0;
        while (int(s[i]) < 49 || int(s[i]) > 57) {
            if (isalpha(s[i]) || s[i] == '.') {
                return 0;
            }
            if (special == 2 && (s[i] == '-' || s[i] == '.' || s[i] == ' ')) {
                return 0;
            }
            if (s[i] == '+' || s[i] == '-') {
                special++;
                if (special == 2)
                    return 0;
            }
            i++;
            if (i == s.length()) {
                return 0;
            }
        }
        first = i;
        int factor = i ? s[first - 1] == '-' ? -1 : 1 : 1;
        for (i; i < s.length(); i++) {
            if (int(s[i]) > 47 && int(s[i]) < 58) {
                res += s[i];
            }
            else break;
        }
        long long ans = 0;
        for (i = res.length() - 1; i + 1; i--) {
            ans += (int(res[i]) - 48) * pow(10, res.length() - i -1);
        }
        return ans < 0x7fffffff ? factor * ans : factor == -1 ? -1 * (static_cast<long long>(0x7fffffff) + 1) : 0x7fffffff;
    }
};

int main()
{
    string s = "-+42";
    
    cout << Solution().myAtoi(s) << endl;
}