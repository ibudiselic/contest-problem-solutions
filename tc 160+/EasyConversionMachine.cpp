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

class EasyConversionMachine {
public:
    string isItPossible(string a, string b, int k) {
        int n = a.size();
        for (int i=0; i<n; ++i) {
            k -= (a[i] != b[i]);
        }
        return k>=0 && k%2==0 ? "POSSIBLE" : "IMPOSSIBLE";
    }
};
