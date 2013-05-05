#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {
    long long sol = 0;
    int sum = 0;
    int base, lucky, n;
    scanf("%d %d %d", &base, &lucky, &n);
    int x;
    map<int, int> cnt;
    cnt[0] = 1;
    int cur_zeros = 0;
    long long zero_seqs = 0;
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        if (x == 0) {
            ++cur_zeros;
        } else {
            cur_zeros = 0;
        }
        zero_seqs += cur_zeros;

        sum += x;
        if (sum >= base-1) {
            sum -= base-1;
        }
        int sub = sum - lucky;
        if (sub < 0) {
            sub += base-1;
        }
        sol += cnt[sub];
        ++cnt[sum];
    }

    if (lucky == 0) {
        sol = zero_seqs;
    } else if (lucky == base-1) {
        sol -= zero_seqs;
    }

    printf("%I64d\n", sol);
    return 0;
}
