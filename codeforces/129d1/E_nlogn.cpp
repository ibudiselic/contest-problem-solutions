#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <utility>

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
        for (int k=nA; k>0; --k) {
            if (i>0 && j>=0) {
                const int x = SA[i];
                const int y = R[j];
                int diff = A[x] - A[y];
                if (diff == 0) {
                    if (x%3 == 1) {
                        diff = rank[x+1] - rank[y+1];
                    } else {
                        assert(x%3 == 2);
                        diff = A[x+1] - A[y+1];
                        if (diff == 0) {
                            diff = rank[x+2] - rank[y+2];
                        }
                    }
                }
                assert(diff != 0);
                if (diff < 0) {
                    SA[k] = y;
                    --j;
                } else {
                    SA[k] = x;
                    --i;
                }
            } else if (i > 0) {
                SA[k] = SA[i--];
            } else {
                assert(j >= 0);
                SA[k] = R[j--];
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

vector<int> compute_lcp(const string &s, const SuffixArray &SA, const vector<int> &invSA) {
    int n = s.size();
    vector<int> LCP(n+1);
    int m = 0;
    for (int i=0; i<n; ++i) {
        int at = invSA[i];
        int j = SA[at - 1];
        while (i+m<n && j+m<n && s[i+m]!=' ' && s[i+m]==s[j+m]) { // stop at delimiters
            ++m;
        }
        LCP[i] = m;
        m = max(0, m - 1);
    }
    return LCP;
}

const int inf = 123456789;
struct TournamentTree {
    int n;
    vector<int> T;
    mutable int l, r;

    TournamentTree(int N) {
        n = 1;
        while (n <= N) {
            n <<= 1;
        }
        T.assign(2*n, inf);
    }

    void set(int i, int val) {
        i += n;
        T[i] = val;
        for (i/=2; i>0; i/=2) {
            T[i] = min(T[2*i], T[2*i+1]);
        }
    }

    int get_min(int l, int r) const {
        this->l = l;
        this->r = r;
        return get_min(1, 0, n);
    }

    int get_min(int node, int a, int b) const {
        if (b<=l || a>=r) return inf;
        if (l<=a && b<=r) return T[node];
        const int mid = a + (b-a)/2;
        return min(get_min(2*node, a, mid), get_min(2*node+1, mid, b));
    }
};

const int MAXN = 100000;
int idx[2*MAXN];
int main() {
    int n, k;
    cin >> n >> k;
    string S;
    vector<int> starts_at;
    for (int i=0; i<n; ++i) {
        if (i > 0) {
            S += ' '; // separator
        }
        starts_at.push_back(int(S.size()));
        string tmp;
        cin >> tmp;
        if (k == 1) {
            if (i) cout << ' ';
            cout << (long long)tmp.size()*(tmp.size()+1)/2;
        }
        for (int j=0; j<(int)tmp.size(); ++j) {
            idx[int(S.size()) + j] = i;
        }
        S += tmp;
    }
    starts_at.push_back(int(S.size()) + 1); // dummy

    if (k == 1) {
        cout << '\n';
        return 0;
    }

    SuffixArray SA(S);
    vector<int> invSA = SA.inverse();
    vector<int> LCP = compute_lcp(S, SA, invSA);

    n = SA.size();
    TournamentTree T(n+1);
    for (int i=1; i<=n; ++i) {
        T.set(i, LCP[SA[i]]);
    }
    typedef pair<int, int> pii;
    set<pii> what;
    map<int, int> where;
    vector<pii> ranges;
    vector<int> range_maxlen;
    for (int i=1; i<=n; ++i) {
        if (S[SA[i]] == ' ') continue;
        int str_idx = idx[SA[i]];
        map<int, int>::iterator it=where.find(str_idx);
        if (it != where.end()) {
            what.erase(pii(it->second, it->first));
        }
        where[str_idx] = i;
        what.insert(pii(i, str_idx));
        while ((int)what.size() > k) {
            const pii tmp = *what.begin();
            where.erase(tmp.second);
            what.erase(what.begin());
        }
        if ((int)what.size() == k) {
            ranges.push_back(pii(what.begin()->first, i));
            range_maxlen.push_back(T.get_min(ranges.back().first+1, ranges.back().second+1));
        }
    }
    vector<int> maxlen(n, 0);
    int l = 0;
    int len = 0;
    for (int i=1; i<=n; ++i) {
        len = min(len, LCP[SA[i]]);
        while (l<(int)ranges.size() && i==ranges[l].first) {
            len = max(len, range_maxlen[l++]);
        }
        maxlen[SA[i]] = len;
    }
    len = 0;
    int r = int(ranges.size()) - 1;
    for (int i=n; i>0; --i) {
        if (r>=0 && i==ranges[r].second) {
            len = max(len, range_maxlen[r--]);
        }
        maxlen[SA[i]] = max(maxlen[SA[i]], len);
        len = min(len, LCP[SA[i]]);
    }

    long long sol = 0;
    int at = 0;
    for (int i=0; i<(int)S.size(); ++i) {
        if (S[i] == ' ') {
            if (++at > 1) cout << ' ';
            cout << sol;
            sol = 0;
            continue;
        }
        sol += maxlen[i];
    }
    if (at) cout << ' ';
    cout << sol << '\n';
    return 0;
}
