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

const int INPUT_MAXCHARS = 1<<16;
char buffer[INPUT_MAXCHARS];
struct FastReader {
    char *p;

    FastReader(): p(buffer) {
        fread(buffer, 1, sizeof buffer, stdin);
    }
    int next_int() {
        return int(next_ll());
    }
    long long next_ll() {
        upd();
        long long sgn = 1;
        while (*p < '0') {
            if (*p++ == '-') {
                sgn = -1;
                break;
            }
        }
        long long val = 0;
        while (*p >= '0') {
            val = val*10 + (*p - '0');
            ++p;
        }
        return sgn*val;
    }

    private:
    void upd() {
        int remchars = INPUT_MAXCHARS - (p-buffer);
        if (remchars < 25) {
            memcpy(buffer, p, remchars);
            size_t cnt = fread(buffer+remchars, 1, sizeof buffer - remchars, stdin);
            if (remchars + cnt < sizeof buffer) { // assume EOF
                buffer[remchars + cnt] = 0; // make the value determinate
            }
            p = buffer;
        }
    }
};

const int MAXK = 80;
long long N[MAXK + 1];
long long l_to_r[MAXK + 1];
long long inf = 100000000000000000LL;
pair<long long, pair<long long, long long> > memo[MAXK + 1][5];
int memo_cnt[MAXK + 1];

pair<long long, long long> go_lr(long long a, int k) {
    for (int i=0; i<memo_cnt[k]; ++i) {
        if (memo[k][i].first == a) {
            return memo[k][i].second;
        }
    }

    pair<long long, long long> ret;
    if (k == 0) {
        ret = make_pair(0ll, 0ll);
    } else if (k == 1) {
        ret = make_pair(a==0 ? 0ll : 1ll, a==0 ? 1ll : 0ll);
    } else {
        long long n = N[k-1];
        if (a >= n) {
            ret = go_lr(a - n, k - 2);
            ++ret.first;
        } else {
            ret = go_lr(a, k - 1);
            ret.first = min(ret.first, ret.second + 2);
            ret.second = min(ret.first, ret.second) + 1 + l_to_r[k - 2];
        }
    }

    memo[k][memo_cnt[k]++] = make_pair(a, ret);
    return ret;
}
inline long long go_left(long long a, int k) {
    return go_lr(a, k).first;
}
inline long long go_right(long long a, int k) {
    return go_lr(a, k).second;
}
inline long long minlr(long long a, int k) {
    pair<long long, long long> tmp = go_lr(a, k);
    return min(tmp.first, tmp.second);
}
long long dist(long long a, long long b, int k) {
    if (a == b) {
        return 0;
    }
    assert(k >= 1);
    assert(a < b);
    if (k == 1) {
        assert(a==0 && b==1);
        return 1;
    }
    if (a == 0) {
        return go_left(b, k);
    }
    if (b == N[k]-1) {
        return go_right(a, k);
    }
    long long ret = inf;
    long long n = N[k-1];
    if (n <= a) {
        ret = dist(a-n, b-n, k-2);
    } else if (b < n) {
        ret = min(dist(a, b, k-1),
                  minlr(a, k-1) + minlr(b, k-1) + 2);
    } else {
        ret = 1 + go_left(b-n, k-2) + minlr(a, k-1);
    }
    return ret;
}
int main() {
    FastReader reader;
    int Q = reader.next_int();
    int K = reader.next_int();
    K = min(K, MAXK);
    N[0] = 1;
    N[1] = 2;
    l_to_r[0] = 0;
    l_to_r[1] = 1;
    for (int i=2; i<=MAXK; ++i) {
        N[i] = min(inf, N[i-1] + N[i-2]);
        l_to_r[i] = l_to_r[i-2] + 1;
    }
    while (Q--) {
        long long a = reader.next_ll() - 1;
        long long b = reader.next_ll() - 1;
        if (a > b) {
            swap(a, b);
        }
        memset(memo_cnt, 0, sizeof memo_cnt);
        printf("%I64d\n", dist(a, b, K));
    }
    return 0;
}
