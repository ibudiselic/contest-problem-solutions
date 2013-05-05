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
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int first_resume = n + m + 1;
    if (k == 1) {
        printf("%d\n", 1 + (first_resume-n+(n-2))/(n-1));
        putchar('1');
        int at = n;
        while (at < first_resume) {
            printf(" %d", at);
            at += n - 1;
        }
    } else {
        int cnt = k;
        int at = n;
        while (at < first_resume) {
            ++cnt;
            if (at+1 == first_resume) {
                break;
            }
            cnt += k - 1;
            at += n;
        }
        printf("%d\n", cnt);

        for (int i=0; i<k; ++i) {
            if (i) putchar(' ');
            putchar('1');
        }
        at = n;
        while (at < first_resume) {
            printf(" %d", at);
            ++cnt;
            if (at+1 == first_resume) {
                break;
            }
            cnt += k - 1;
            for (int i=0; i<k-1; ++i) {
                printf(" %d", at + 1);
            }
            at += n;
        }
    }
    putchar('\n');

    return 0;
}
