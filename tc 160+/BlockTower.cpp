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

class BlockTower {
public:
    int getTallest(vector <int> H) {
        int sol = 0;
        int cand = 0;
        for (int i=0; i<int(H.size()); ++i) {
            if (H[i] & 1) {
                int ccand = cand;
                for (int j=i; j<(int)H.size(); ++j) {
                    if (H[j] & 1) {
                        ccand += H[j];
                    }
                }
                sol = max(sol, ccand);
            } else {
                cand += H[i];
            }
        }
        return max(sol, cand);
    }
};
