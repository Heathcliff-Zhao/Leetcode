#include <iostream>
using namespace std;

bool isBadVersion(int n) {

}

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n, mid = (left + right) >> 1;
        while (left < right && left < mid) {
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid;
            mid = (left + right) >> 1;
        }
        if (left - right && !isBadVersion(left))
            left = right;
        return left;
    }
};
