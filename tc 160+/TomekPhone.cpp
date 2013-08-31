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

class TomekPhone {
public:
    int minKeystrokes(vector <int> F, vector <int> C) {
        int n = F.size();
        if (accumulate(C.begin(), C.end(), 0) < n) {
            return -1;
        }
        int sol = 0;
        sort(F.begin(), F.end(), greater<int>());
        sort(C.begin(), C.end(), greater<int>());
        int i = 0;
        int round = 1;
        int j = 0;
        int m = C.size();
        while (i < n) {
            if (j==m || C[j]==0) {
                j = 0;
                ++round;
            }
            --C[j++];
            sol += F[i++]*round;
        }

        return sol;
    }
};
