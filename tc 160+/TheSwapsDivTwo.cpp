//# swaps, implementation
//# => trivial
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

class TheSwapsDivTwo {
public:
    int find(vector <int> sequence) {
        set<vector<int>> S;
        for (int i=0; i<(int)sequence.size(); ++i) {
            for (int j=i+1; j<(int)sequence.size(); ++j) {
                swap(sequence[i], sequence[j]);
                S.insert(sequence);
                swap(sequence[i], sequence[j]);
            }
        }
        return S.size();
    }
};
