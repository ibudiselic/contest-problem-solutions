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

// based heavily on srm518 editorial
const int mod = 1000000007;

int fastexp_mod(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return int(ret);
}

int A[1<<16];
long long INV2;

void T(int l, int r) {
    if (r-l <= 1) {
        return;
    }
    int half = (r-l)/2;
    T(l, l+half);
    T(l+half, r);
    for (int i=0; i<half; ++i) {
        int x = A[l+i];
        int y = A[l+half+i];
        A[l+i] = (x-y+mod)%mod;
        A[l+half+i] = (x+y)%mod;
    }
}
void T_inverse(int l, int r) {
    if (r-l <= 1) {
        return; 
    }
    int half = (r-l)/2;
    for (int i=0; i<half; ++i) {
        int u = A[l+i];
        int v = A[l+half+i];
        A[l+i] = (u+v)*INV2%mod;
        A[l+half+i] = (v-u+mod)*INV2%mod;
    }
    T_inverse(l, l+half);
    T_inverse(l+half, r);
}
class Nim {
public:
    int count(int K, int L) {
        INV2 = fastexp_mod(2, mod-2);
        // set A[i]=1 if i<=L and i is prime
        memset(A, 0, sizeof A);
        fill(A+2, A+L+1, 1);
        for (int i=2; i*i<=L; ++i) {
            if (A[i]) {
                for (int j=i*i; j<=L; j+=i) {
                    A[j] = 0;
                }
            }
        }
        
        T(0, 1<<16); // transform A (see editorial)
        for (int i=0; i<(1<<16); ++i) {
            A[i] = fastexp_mod(A[i], K);
        }
        T_inverse(0, 1<<16); // invert back to A
        return A[0];
    }
};
