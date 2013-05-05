#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const long double pi = acos(-1.0);
const long double alpha = 3*pi/5;
const long double beta = alpha/3;
const long double a = 10;
const long double b = 2*a*sin(alpha/2);
const long double cosbeta = cos(beta);
const long double sinbeta = sin(beta);
void output(long double x, long double y) {
    printf("%.12f %.12f\n", double(x), double(y));
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", 5 + (n-1)*4);
    output(0.0l, 0.0l);
    for (int i=0; i<n; ++i) {
        const long double x = i*b;
        output(x + a*cosbeta, a*sinbeta);
        output(x + b, 0.0l);
        output(x + b*cosbeta, -b*sinbeta);
        output(x + b*cosbeta - a, -b*sinbeta);
    }
    puts("1 2 3 4 5");
    for (int i=1; i<n; ++i) {
        printf("%d", 3 + (i-1)*4);
        for (int j=2+i*4, pt=4; pt>0; ++j, --pt) {
            printf(" %d", j);
        }
        putchar('\n');
    }
    putchar('1');
    for (int i=1; i<=n; ++i) {
        printf(" %d", 3 + (i-1)*4);
    }
    for (int i=n-1; i>0; --i) {
        int base = 2 + i*4;
        printf(" %d %d %d %d", base+3, base, base+2, 3 + (i-1)*4);
    }
    puts(" 5 2 4 1");
    return 0;
} 
