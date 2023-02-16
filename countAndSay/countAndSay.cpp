#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string lastres = countAndSay(n - 1);
        string res = "";
        char now = lastres[0];
        int count = 0;
        for (int i = 0; i < lastres.length(); i++) {
            if (lastres[i] == now) {
                count++;
            }
            else {
                res.append(to_string(count));
                res += now;
                count = 1;
                now = lastres[i];
            }
        }
        res.append(to_string(count));
        res += now;
        return res;
    }
};

int main()
{
    int n;
    while (cin >> n) {
        cout << Solution().countAndSay(n) << endl;
    }
    return 0;
}

