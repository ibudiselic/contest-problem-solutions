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

int n;
bool used[50];
bool can_make(int start, int K, const vector<int> &L) {
    for (int i=start; i<n; ++i) {
        if (!used[i] && L[i]==K) {
            used[i] = true;
            return true;
        }
    }
    for (int i=start; i<n; ++i) {
        if (used[i]) continue;
        for (int j=i+1; j<n; ++j) {
            if (used[j]) continue;
            if (L[i]+L[j]+1 == K) {
                used[i] = true;
                used[j] = true;
                return true;
            }
        }
    }
    return false;
}
bool can(int K, const vector<int> &L) {
    n = L.size();
    memset(used, 0, sizeof used);
    int r = 0;
    while (r<K && can_make(0, K, L)) {
        ++r;
    }
    return r==K;
}
class FoxAndKgram {
public:
    int maxK(vector <int> len) {
        for (int K=50; K>0; --K) {
            if (can(K, len)) {
                return K;
            }
        }
        return 0;
    }
};
