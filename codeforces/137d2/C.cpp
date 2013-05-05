#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int INPUT_MAXCHARS = 1<<16;
char buffer[INPUT_MAXCHARS];
struct FastReader {
    char *p;

    FastReader() {
        fread(buffer, 1, sizeof buffer, stdin);
        p = buffer;
    }
    int next() {
        int remchars = INPUT_MAXCHARS - (p-buffer);
        if (remchars < 25) {
            memcpy(buffer, p, remchars);
            buffer[remchars] = 0;
            fread(buffer+remchars, 1, sizeof buffer - remchars, stdin);
            p = buffer;
        }
        while (*p < '0') {
            ++p;
        }
        int val = 0;
        while (*p >= '0') {
            val = val*10 + (*p - '0');
            ++p;
        }
        return val;
    }
};

const int MAXN = 100000;
const int MAXVAL = 10000000;
int D[MAXVAL+1];
int cntA[MAXVAL+1], cntB[MAXVAL+1];
void upd(int x, int *cnt) {
    while (x > 1) {
        const int d = D[x];
        ++cnt[d];
        x /= d;
    }
}
vector<int> gen(int n, int *A, int *cnt) {
    vector<int> ret;
    for (int i=0; i<n; ++i) {
        int val = 1;
        int x = A[i];
        while (x > 1) {
            const int d = D[x];
            if (cnt[d]) {
                val *= d;
                --cnt[d];
            }
            x /= d;
        }
        ret.push_back(val);
    }
    return ret;
}

int A[MAXN];
int B[MAXN];
int main() {
    for (int i=3; i<=MAXVAL; i+=2) {
        D[i-1] = 2;
        if (D[i] == 0) { // prime
            D[i] = i;
            if (i <= MAXVAL/i) {
                for (int j=i*i; j<=MAXVAL; j+=2*i) {
                    if (D[j] == 0) {
                        D[j] = i;
                    }
                }
            }
        }
    }
    D[MAXVAL] = 2;
    FastReader reader;
    int m = reader.next();
    int n = reader.next();
    for (int i=0; i<m; ++i) {
        A[i] = reader.next();
        upd(A[i], cntA);
    }
    for (int i=0; i<n; ++i) {
        B[i] = reader.next();
        upd(B[i], cntB);
    }

    for (int i=2; i<=MAXVAL; ++i) {
        if (cntA[i] >= cntB[i]) {
            cntA[i] -= cntB[i];
            cntB[i] = 0;
        } else {
            cntB[i] -= cntA[i];
            cntA[i] = 0;
        }
    }

    vector<int> AA = gen(m, A, cntA);
    vector<int> BB = gen(n, B, cntB);
    
    printf("%d %d\n", int(AA.size()), int(BB.size()));
    for (int i=0; i<(int)AA.size(); ++i) {
        if (i) putchar(' ');
        printf("%d", AA[i]);
    }
    putchar('\n');
    for (int i=0; i<(int)BB.size(); ++i) {
        if (i) putchar(' ');
        printf("%d", BB[i]);
    }
    putchar('\n');
    return 0;
}
