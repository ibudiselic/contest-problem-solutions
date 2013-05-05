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
    int n, m;
    scanf("%d %d", &n, &m);
    int sol = 0;
    for (int a=0; a*a<=n; ++a) {
        for (int b=0; b*b<=m; ++b) {
            sol += (a*a+b==n && b*b+a==m);
        }
    }
    printf("%d\n", sol);
    return 0;
}
