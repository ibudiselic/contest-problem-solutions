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
#include <numeric>
#include <functional>

using namespace std;

class GooseTattarrattatDiv2 {
public:
    int getmin(string S) {
        vector<int> a;
        for (int c='a'; c<='z'; ++c) {
            a.push_back(count(S.begin(), S.end(), c));
        }
        sort(a.begin(), a.end(), greater<int>());
        return accumulate(a.begin()+1, a.end(), 0);
    }
};
