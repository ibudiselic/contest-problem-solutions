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

class UnsortedSequence {
public:
    vector <int> getUnsorted(vector <int> s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int i = n-2;
        while (i>=0 && s[i]==s[i+1]) {
            --i;
        }
        if (i < 0) {
            return vector<int>();
        } else {
            swap(s[i], s[i+1]);
            return s;
        }
    }
};
