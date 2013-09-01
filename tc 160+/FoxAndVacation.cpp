#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class FoxAndVacation {
public:
    int maxCities(int total, vector <int> d) {
        int n = d.size();
        sort(d.begin(), d.end());
        for (int i=0; i<n; ++i) {
            if (accumulate(d.begin(), d.begin()+i+1, 0) > total) {
                return i;
            }
        }
        return n;
    }
};
