#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

vector<int> B[1000];
int cnt_bridges(int a, int b, int idx) {
    return lower_bound(B[idx].begin(), B[idx].end(), b) - lower_bound(B[idx].begin(), B[idx].end(), a);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int k;
        scanf("%d", &k);
        B[i].reserve(k);
        for (int j=0; j<k; ++j) {
            int b;
            scanf("%d", &b);
            B[i].push_back(b);
        }
        sort(B[i].begin(), B[i].end());
    }

    int sol = 0;
    for (int i=0; i<n; ++i) {
        int prev = (i+n-1)%n;
        int next = (i+1)%n;
        for (int j=1; j<(int)B[i].size(); ++j) {
            int a = B[i][j-1];
            int b = B[i][j];
            int l = cnt_bridges(a, b, prev);
            int r = cnt_bridges(a, b, next);
            if (l != r) {
                ++sol;
            }
        }
    }
    printf("%d\n", sol);

    return 0;
}
