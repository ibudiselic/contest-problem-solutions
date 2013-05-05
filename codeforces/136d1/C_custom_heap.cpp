#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 100000;

int now;
struct Inc {
    int k, v, t;
    Inc(int k_=0, int v_=0, int t_=0): k(k_), v(v_), t(t_) {}
    int value() const { return v + (now-t); }
    int key() const { return k; }
};
bool operator<(const Inc &a, const Inc &b) {
    return a.value() < b.value();
}
bool operator>=(const Inc &a, const Inc &b) {
    return a.value() >= b.value();
}
struct Dec {
    int k, v, t;
    Dec(int k_=0, int v_=0, int t_=0): k(k_), v(v_), t(t_) {}
    int value() const { return v - (now-t); }
    int key() const { return k; }
};
bool operator<(const Dec &a, const Dec &b) {
    return a.value() < b.value();
}
bool operator>=(const Dec &a, const Dec &b) {
    return a.value() >= b.value();
}

template<typename T>
class Heap {
public:
    Heap(): n(0), A(MAXN+1), at(MAXN+1) {}
    void insert(const T &item) {
        A[++n] = item;
        assert(at[item.key()] == 0);
        at[item.key()] = n;
        fix_up(n);
        check(2);
        check(3);
    }
    void remove(int key) {
        assert(1<=at[key] && at[key]<=n);
        int orig = at[key];
        exch(orig, n);
        assert(at[key] == n);
        at[key] = 0;
        --n;
        fix_down(orig);
        fix_up(orig);
        check(2);
        check(3);
    }
    T min_peek() {
        assert(n > 0);
        return A[1];
    }
    int size() {
        return n;
    }
private:
    int n;
    vector<T> A;
    vector<int> at;
    
    void check(int node) {
        if (node <= n) {
            assert(!(A[node] < A[node/2]));
            assert(at[A[node].key()] == node);
            check(2*n);
            check(2*n+1);
        }
    }
    void exch(int pos1, int pos2) {
        at[A[pos1].key()] = pos2;
        at[A[pos2].key()] = pos1;
        swap(A[pos1], A[pos2]);
    }
    void fix_up(int pos) {
        while (pos/2>0 && A[pos]<A[pos/2]) {
            exch(pos, pos/2);
            pos /= 2;
        }
    }
    void fix_down(int pos) {
        while (true) {
            int l = 2*pos;
            int r = l + 1;
            int chosen = -1;
            if (r<=n && A[r]<A[l]) {
                chosen = r;
            } else if (l <= n) {
                chosen = l;
            }
            if (chosen==-1 || A[chosen]>=A[pos]) {
                break;
            }
            exch(pos, chosen);
            pos = chosen;
        }
    }
};

struct Event {
    int t, num, type;
    Event(int t_, int num_, int type_): t(t_), num(num_), type(type_) {};
};
bool operator<(const Event &a, const Event &b) {
    if (a.t != b.t) {
        return a.t > b.t;
    } else if (a.num != b.num) {
        return a.num < b.num;
    } else {
        return a.type > b.type;
    }
}
#define ins(A, B, C) PQ.push(Event((A), (B), (C)))
int revA[MAXN];
int revB[MAXN];
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        revA[x-1] = i;
    }
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        revB[x-1] = i;
    }

    now = 0;
    Heap<Inc> inc;
    Heap<Dec> dec;
    priority_queue< Event > PQ;
    for (int i=0; i<n; ++i) {
        if (revB[i] <= revA[i]) {
            inc.insert(Inc(i, revA[i]-revB[i], 0));
            ins(revB[i]+1, i, 0);
            ins(revB[i]+n-revA[i], i, 1);
        } else {
            dec.insert(Dec(i, revB[i]-revA[i], 0));
            ins(revB[i]-revA[i], i, 1);
            ins(revB[i]+1, i, 0);
        }
    }

    while (now < n) {
        while (PQ.size()>0 && PQ.top().t==now) {
            Event e = PQ.top();
            PQ.pop();
            if (e.type == 0) {
                inc.remove(e.num);
                dec.insert(Dec(e.num, n-1-revA[e.num], now));
            } else if (e.type == 1) {
                dec.remove(e.num);
                inc.insert(Inc(e.num, 0, now));
            } else {
                assert(0);
            }
        }
        int sol = 123456789;
        if (inc.size()) {
            sol = min(sol, inc.min_peek().value());
        }
        if (dec.size()) {
            sol = min(sol, dec.min_peek().value());
        }
        assert(sol < 123456789);
        printf("%d\n", sol);
        ++now;
    }
    return 0;
}
