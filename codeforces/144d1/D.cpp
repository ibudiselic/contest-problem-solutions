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

class SuffixArray {
public:
    SuffixArray(const string &s): n(s.size()) {
        vector<int> v;
        for (int i=0; i<(int)s.size(); ++i) {
            v.push_back(int(s[i]));
        }
        init(v);
    }
    SuffixArray(const vector<int> &v): n(v.size()) {
        init(v);
    }
    SuffixArray(const SuffixArray &other): n(other.n) {
        SA = new int[n+1];
        assert(SA);
        memcpy(SA, other.SA, (n+1)*sizeof *SA);
    }
    SuffixArray operator=(const SuffixArray &other) {
        if (this != &other) {
            if (n != other.n) {
                n = other.n;
                delete[] SA;
                SA = new int[n+1];
                assert(SA);
            }
            memcpy(SA, other.SA, (n+1)*sizeof *SA);
        }
        return *this;
    }
    
    ~SuffixArray() {
        assert(SA != 0);
        delete[] SA;
        assert(A == 0);
        assert(cnt == 0);
    }

    int size() const {
        return n;
    }

    int operator[](int i) const {
        assert(0<=i && i<=n);
        return SA[i];
    }

    vector<int> inverse() const {
        vector<int> ret(n+1);
        for (int i=0; i<=n; ++i) {
            ret[SA[i]] = i;
        }
        return ret;
    }
private:
    void init(const vector<int> &v) {
        A = new int[3*n + 9];
        cnt = new int[max(n, MIN_CNT) + 1]();
        int maxval = 0;
        for (int i=0; i<n; ++i) {
            assert(0<=v[i] && v[i]<=max(n, MIN_CNT));
            maxval = max(maxval, v[i]);
            ++cnt[v[i]];
        }
        int name = 0;
        for (int i=0; i<=maxval; ++i) {
            if (cnt[i] > 0) {
                cnt[i] = name++;
            }
        }
        for (int i=0; i<n; ++i) {
            A[i] = cnt[v[i]];
        }

        SA = new int[n + 1];
        make_sarray(A, n);

        delete[] A;
        delete[] cnt;
        A = 0;
        cnt = 0;
    }

    void make_sarray(int *A, int nA) {
        if (nA < 2) {
            if (nA == 0) {
                SA[0] = 0;
            } else {
                assert(nA == 1);
                SA[0] = 1;
                SA[1] = 0;
            }
            return;
        }

        int n1 = (nA+1)/3;

        A[nA] = A[nA+1] = A[nA+2] = -1;
        int *B = A + nA + 3;
        int *R = B + nA + 3;

        int nR = 0;
        for (int i=1; i<nA; i+=3) {
            B[nR++] = i;
        }
        for (int i=2; i<nA; i+=3) {
            B[nR++] = i;
        }
        
        if (nA%3 == 1) {
            B[nR++] = nA;
            ++n1;
        }

        counting_sort(A+2, nA, B, R, nR);
        counting_sort(A+1, nA, R, B, nR);
        counting_sort(A+0, nA, B, R, nR);
        
        int name = 0;
        for (int i=0; i<nR; ++i) {
            if (i && (A[R[i-1]+0] != A[R[i]+0]
                   || A[R[i-1]+1] != A[R[i]+1]
                   || A[R[i-1]+2] != A[R[i]+2])) {
                ++name;
            }
            B[R[i]/3 + (R[i]%3==2)*n1] = name;
        }

        if (name+1 == nR) {
            memcpy(SA+1, R, nR*sizeof *R);
        } else {
            make_sarray(B, nR);
            for (int i=1; i<=nR; ++i) {
                SA[i] = (SA[i] < n1) ? 3*SA[i] + 1 : 3*(SA[i]-n1) + 2;
            }
        }

        SA[0] = nA;
        if (SA[1] == nA) {
            assert(nA%3 == 1);
            --n1;
            --nR;
            memmove(SA+1, SA+2, nR*sizeof *R);
        }

        int nSA = nR;
        nR = 0;
        for (int i=0; i<=nSA; ++i) {
            if (SA[i]%3 == 1) {
                B[nR++] = SA[i] - 1;
            }
        }
        counting_sort(A, nA, B, R, nR);

        int *rank = B;
        for (int i=0; i<=nSA; ++i) {
            rank[SA[i]] = i;
        }
        rank[nA] = rank[nA+1] = -1;

        int i = nSA;
        int j = nR - 1;
        for (int k=nA; j>=0; --k) {
            const int x = SA[i];
            const int y = R[j];
            int diff = A[x] - A[y];
            if (diff == 0) {
                if (x%3 == 1) {
                    diff = rank[x+1] - rank[y+1];
                } else {
                    diff = A[x+1] - A[y+1];
                    if (diff == 0) {
                        diff = rank[x+2] - rank[y+2];
                    }
                }
            }
            if (diff < 0) {
                SA[k] = y;
                --j;
            } else {
                SA[k] = x;
                --i;
            }
        }
    }

    void counting_sort(int *A, int maxval, int *from, int *to, int n) {
        memset(cnt, 0, (maxval+1)*sizeof *cnt);
        int *C = cnt + 1;
        for (int i=0; i<n; ++i) {
            ++C[A[from[i]]];
        }
        int v = 0;
        for (int i=-1; i<maxval && v<n; v+=C[i++]) {
            swap(v, C[i]);
        }
        for (int i=0; i<n; ++i) {
            to[C[A[from[i]]]++] = from[i];
        }
    }

    static const int MIN_CNT = 255; // enough for ASCII strings

    int n;
    int *SA, *A;
    int *cnt;
};

vector<int> compute_lcp(const vector<int> &v, const SuffixArray &SA, const vector<int> &invSA) {
    int n = v.size();
    vector<int> LCP(n+1);
    int m = 0;
    for (int i=0; i<n; ++i) {
        int at = invSA[i];
        int j = SA[at - 1];
        while (i+m<n && j+m<n && v[i+m]==v[j+m]) {
            ++m;
        }
        LCP[i] = m;
        m = max(0, m - 1);
    }
    return LCP;
}

const int MAXN = 100000;
int H[MAXN];
int N, Q;
int L[MAXN];
int R[MAXN];
int S[MAXN];
int E[MAXN];
int sol[MAXN];

const int inf = 2000000001;
struct TournamentTree {
    TournamentTree(const vector<int> &v): actual_n(v.size()) {
        for (n=1; n<(int)v.size(); n<<=1);
        T.assign(2*n, +inf);
        for (int i=0; i<(int)v.size(); ++i) {
            set(i, v[i]);
        }
    }

    void set(int at, int val) {
        at += n;
        T[at] = val;
        while (at/2 > 0) {
            at /= 2;
            T[at] = min(T[2*at], T[2*at + 1]);
        }
    }

    int get_min(int l, int r) const {
        this->l = l;
        this->r = r;
        return get_min(1, 0, n);
    }

    int get_leftmost_lt(int l, int r, int val) {
        this->l = l;
        this->r = r;
        return get_leftmost_lt(1, 0, n, val);
    }

    int get_rightmost_lt(int l, int r, int val) {
        this->l = l;
        this->r = r;
        return get_rightmost_lt(1, 0, n, val);
    }

    private:
    int n;
    int actual_n;
    mutable int l, r;
    vector<int> T;

    int get_min(int node, int a, int b) const {
        if (l<=a && b<=r) return T[node];
        if (b<=l || r<=a) return +inf;
        int mid = a + (b-a)/2;
        return min(get_min(2*node, a, mid), get_min(2*node+1, mid, b));
    }

    int get_leftmost_lt(int node, int a, int b, int val) {
        if (a>=r || b<=l) return r;
        if (l<=a && b<=r) {
            if (T[node] >= val) return r;
            if (a+1 == b) return a;
        }
        int mid = a + (b-a)/2;
        int ret = get_leftmost_lt(2*node, a, mid, val);
        return ret!=r ? ret : get_leftmost_lt(2*node + 1, mid, b, val);
    }
    int get_rightmost_lt(int node, int a, int b, int val) {
        if (a>=r || b<=l) return l;
        if (l<=a && b<=r) {
            if (T[node] >= val) return l;
            if (a+1 == b) return a;
        }
        int mid = a + (b-a)/2;
        int ret = get_rightmost_lt(2*node + 1, mid, b, val);
        return ret!=l ? ret : get_rightmost_lt(2*node, a, mid, val);
    }
};

struct FenwickTree {
    FenwickTree(int N): n(N), T(N+1, 0) {}
    void change(int x, int by) {
        while (x <= n) {
            T[x] += by;
            x += x&-x;
        }
    }
    int sum(int l, int r) { // [l, r>
        int ret = 0;
        for (--r; r>0; r-=r&-r) ret += T[r];
        for (--l; l>0; l-=l&-l) ret -= T[l];
        return ret;
    }
    int n;
    vector<int> T;
};

struct event_t {
    int t, q, sgn;
    event_t(int t_, int q_, int sgn_): t(t_), q(q_), sgn(sgn_) {}
};
bool operator<(const event_t &a, const event_t &b) {
    if (a.t != b.t) {
        return a.t < b.t;
    } else if (a.q != b.q) {
        return a.q < b.q;
    } else {
        return a.sgn < b.sgn;
    }
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", H + i);
    }
    scanf("%d", &Q);
    for (int i=0; i<Q; ++i) {
        scanf("%d", L + i);
        scanf("%d", R + i);
    }

    if (N == 1) {
        for (int i=0; i<Q; ++i) {
            puts("0");
        }
    } else {
        vector<int> diffs;
        for (int i=1; i<N; ++i) {
            diffs.push_back(H[i-1] - H[i]);
        }
        diffs.push_back(-2000000001);
        for (int i=1; i<N; ++i) {
            diffs.push_back(-diffs[i-1]);
        }

        int n = diffs.size();
        vector< pair<int, int> > tmp;
        tmp.reserve(n);
        for (int i=0; i<n; ++i) {
            tmp.push_back(make_pair(diffs[i], i));
        }
        sort(tmp.begin(), tmp.end());

        int name = 0;
        vector<int> vals(n);
        for (int i=0; i<n; ++i) {
            if (i>0 && tmp[i].first!=tmp[i-1].first) {
                ++name;
            }
            vals[tmp[i].second] = name;
        }

        SuffixArray SA(vals);
        vector<int> invSA = SA.inverse();
        vector<int> lcp_ = compute_lcp(vals, SA, invSA);
        vector<int> lcp__ = lcp_;
        for (int i=0; i<=n; ++i) {
            lcp__[i] = lcp_[SA[i]];
        }
        /*
        for (int i=0; i<=n; ++i) {
            cerr << SA[i] << ' ' << invSA[i] << ' ' << lcp_[i] << ' ' << lcp__[i] << '\n';
        }
        */
        TournamentTree lcp(lcp__);

        vector<event_t> events;
        for (int i=0; i<Q; ++i) {
            if (L[i] == R[i]) {
                sol[i] = N - 1;
            } else {
                int pos = invSA[L[i] - 1];
                int k = R[i] - L[i];
                S[i] = lcp.get_rightmost_lt(0, pos+1, k); // start - inclusive
                E[i] = lcp.get_leftmost_lt(pos+1, n, k); // end - exclusive
                events.push_back(event_t(N-1+R[i], i, +1));
                if (L[i]-k >= 1) {
                    events.push_back(event_t(N-1+L[i]-k-1, i, -1));
                    events.push_back(event_t(N-1         , i, +1));
                }
            }
        }

        sort(events.begin(), events.end());
        FenwickTree T(n+1); // 1 if the corresponding SA entry is >curt
        int curt = n; // no SA entry is >n
        while (events.size() > 0) {
            while (curt > events.back().t) {
                T.change(invSA[curt] + 1, +1);
                --curt;
            }
            if (events.back().t == curt) {
                int q = events.back().q;
                int sgn = events.back().sgn;
                events.pop_back();

                //cerr << S[q] << ' ' << E[q] << '\n';
                //cerr << q << " + " << sgn*T.sum(S[q]+1, E[q]+1) << '\n';
                sol[q] += sgn*T.sum(S[q]+1, E[q]+1);
            }
        }

        for (int i=0; i<Q; ++i) {
            printf("%d\n", sol[i]);
        }
    }
    return 0;
}
