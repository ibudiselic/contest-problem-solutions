#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int getmax(int n) {
    int ret = 0;
    int x;
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        ret = max(ret, x);
    }
    return ret;
}
int getmin(int n) {
    int ret = 5001;
    int x;
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        ret = min(ret, x);
    }
    return ret;
}
int main() {
    int a, b, c;
    scanf("%d", &a);
    int r1 = getmax(a);
    scanf("%d", &b);
    int p1 = getmax(b);
    scanf("%d", &c);
    int p2 = getmin(c);
    int A, B;
    scanf("%d %d", &A, &B);
    double F = double(A)/B;
    
    printf("%.12f\n", r1*sqrt(p1/(F*p2 + p1)));
    return 0;
}
