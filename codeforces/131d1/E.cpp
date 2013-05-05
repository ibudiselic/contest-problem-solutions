#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// codeforces 131d1 problem E - Two Permutations
// Given two permutations A and B of length n and m respectively, 
// find how many different integers d exist such that
// A[0]+d, A[1]+d, ..., A[n-1]+d is a subsequence of B.
//
// The idea is to test different values of d, starting from 0
// upwards. We hash the value of the (A, d) sequence and use a 
// tournament tree to update and query the information 
// about the indices of A[i]+d values into B. The hash value
// encodes the order (i.e. the permutation) of values in (A, d).
//
// Since with hashing we can get collisions, the calc function can 
// overestimate the actual solution, so we try several different 
// hashing functions at random and return the smallest answer
// we get.
const int MAXN = 2000000;
int n, m;
int A[MAXN], B[MAXN];
int revB[MAXN]; // the reverse perm of B, i.e. revB[i] == position of number i in B

unsigned long long mod;
unsigned long long mul;
bool isprime(unsigned long long n) {
    for (unsigned long long d=2; d*d<=n; ++d) {
        if (n%d == 0) {
            return false;
        }
    }
    return true;
}
unsigned long long myrand(unsigned long long n) {
    return (unsigned long long)(rand()/(RAND_MAX+1.0)*double(n));
}

unsigned long long mulpow[MAXN+1];

struct Node {
    int sz;
    unsigned long long hash;
    Node(): sz(0), hash(0) {}
};
Node operator+(const Node &a, const Node &b) {
    Node ret;
    ret.sz = a.sz + b.sz;
    ret.hash = (a.hash*mulpow[b.sz] + b.hash)%mod;
    return ret;
}

class TournamentTree {
    public:
    TournamentTree(int N) {
        ++N;
        n = 1;
        while (n < N) {
            n *= 2;
        }
        T.assign(2*n-1, Node());
    }
    void set(int at, unsigned long long val) {
        at += n - 1;
        T[at].sz = 1;
        T[at].hash = val;
        update_parents(at);
    }
    void clear(int at) {
        at += n - 1;
        T[at].sz = 0;
        T[at].hash = 0;
        update_parents(at);
    }
    Node get(int from, int to) { // [from, to>
        this->from = from;
        this->to = to;
        return get(0, 0, n);
    }
    private:
    Node get(int node, int l, int r) {
        if (r<=from || l>=to) {
            return Node();
        } else if (from<=l && r<=to) {
            return T[node];
        } else {
            const int mid = l + (r-l)/2;
            return get(2*node+1, l, mid) + get(2*node+2, mid, r);
        }
    }

    void update_parents(int at) {
        while (at > 0) {
            at = (at-1)/2;
            T[at] = T[2*at+1] + T[2*at+2];
        }
    }
    int n, from, to;
    vector<Node> T;
};
int calc() {
    mod = (unsigned long long)MAXN + myrand(123456); // make it large and prime
    while (!isprime(mod)) {
        ++mod;
    }
    mul = myrand(mod-2) + 2; // make the multiplier some number smaller than mod, but at least 2
    mulpow[0] = 1;
    for (int i=1; i<=n; ++i) {
        mulpow[i] = mulpow[i-1]*mul%mod;
    }
    unsigned long long target_hash = 0;
    unsigned long long ones_hash = 0;
    for (int i=0; i<n; ++i) {
        target_hash = (target_hash*mul + A[i])%mod;
        ones_hash = (ones_hash*mul + 1)%mod;
    }

    TournamentTree T(m-1);
    for (int i=0; i<n-1; ++i) {
        T.set(revB[i], i);
    }

    int sol = 0;
    for (int i=n-1; i<m; ++i) {
        T.set(revB[i], i);
        sol += (T.get(0, m).hash == target_hash);
        target_hash += ones_hash; // search for the next d value in the next iteration
        if (target_hash >= mod) {
            target_hash -= mod;
        }
        T.clear(revB[i-n+1]);
    }

    return sol;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
        --A[i];
    }
    for (int i=0; i<m; ++i) {
        scanf("%d", B + i);
        --B[i];
        revB[B[i]] = i;
    }

    int sol = m-n+1;
    srand(unsigned(time(0)));
    for (int iter=0; iter<5; ++iter) {
        sol = min(sol, calc());
    }
    printf("%d\n", sol);
    return 0;
}
