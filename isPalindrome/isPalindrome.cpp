#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        regex pattern("[^a-zA-Z0-9\\s]");
        s = regex_replace(s, pattern, "");
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s) << endl;
}
