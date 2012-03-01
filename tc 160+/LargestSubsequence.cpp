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

class LargestSubsequence {
public:
    string getLargest(string s) {
        string sol;
        int i = 0;
        while (i < (int)s.size()) {
            i = max_element(s.begin()+i, s.end()) - s.begin();
            sol += s[i++];
        }
        return sol;
    }
};
