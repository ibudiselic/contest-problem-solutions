#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class MinCostPalindrome {
public:
    int getMinimum(string s, int oCost, int xCost) {
        int n = s.size();
        int sol = 0;
        for (int i=0; i<n/2; ++i) {
            if (s[i]=='?' && s[n-1-i]=='?') {
                sol += 2*min(oCost, xCost);
            } else if (s[i]=='?' || s[n-1-i]=='?') {
                sol += (s[i]=='x')*xCost + (s[i]=='o')*oCost;
                sol += (s[n-1-i]=='x')*xCost + (s[n-1-i]=='o')*oCost;
            } else if (s[i] != s[n-1-i]) {
                return -1;
            }
        }
        return sol;
    }
};
