#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
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

class FoxAndHandleEasy {
public:
    string isPossible(string S, string T) {
        int n = S.size();
        for (int i=0; i<=n; ++i) {
            if (S.substr(0, i)+S+(i<n?S.substr(i):string()) == T) {
                return "Yes";
            }
        }
        return "No";
    }
};
