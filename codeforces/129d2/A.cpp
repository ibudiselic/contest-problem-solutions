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

int main() {
    int n;
    int cnt = 0;
    int val = 1234567890;
    int idx;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int x;
        scanf("%d", &x);
        if (x < val) {
            val = x;
            cnt = 1;
            idx = i+1;
        } else if (x == val) {
            ++cnt;
        }
    }
    if (cnt > 1) {
        puts("Still Rozdil");
    } else {
        printf("%d\n", idx);
    }
    return 0;
}
