#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class GearsDiv2 {
public:
    int getmin(string s) {
        if (s==string(s.size(), 'R') || s==string(s.size(), 'L')) {
            return (s.size()+1)/2;
        }
        int sol = 0;
        int cnt = 0;
        while (s.size()>1 && s[s.size()-1]==s[0]) {
            ++cnt;
            s = s.substr(0, s.size()-1);
        }
        for (int i=0; i<(int)s.size(); ++i) {
            int j = i;
            while (j<(int)s.size() && s[j]==s[i]) {
                ++cnt;
                ++j;
            }
            i = j-1;
            sol += cnt/2;
            cnt = 0;
        }
        return sol;
    }
};
