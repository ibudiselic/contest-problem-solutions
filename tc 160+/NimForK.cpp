#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool s_done[51][20], ns_done[51][20][20], ns_dp[51][20][20];
vector<long double> s_dp[51][20];
vector< vector<int> > M;
const long double eps = 1e-17;
int K;

void strategy(int, int);
bool no_strategy(int n, int p, int who) {
    if (ns_done[n][p][who]) {
        return ns_dp[n][p][who];
    }
    ns_done[n][p][who] = 1;
    bool &ret = ns_dp[n][p][who];
    if (n == 0) {
        return (ret = ((p+K-1)%K == who));
    }

    const int np = (p + 1) % K;
    bool move_possible = false;
    for (int i=0; i<(int)M[n].size(); ++i) {
        const int t = M[n][i];
        if (t <= n) {
            move_possible = true;
            if (np == who) {
                strategy(n-t, who);
                if (s_dp[n-t][who][who]+eps < 1.0) {
                    return (ret = false);
                }
            } else if (!no_strategy(n-t, np, who)) {
                return (ret = false);
            }
        }
    }

    return (ret = move_possible);
}

void strategy(int n, int p) {
    if (s_done[n][p]) {
        return;
    }
    s_done[n][p] = 1;
    vector<long double> &ret = s_dp[n][p];
    ret.assign(K, 0.0);

    if (n == 0) {
        ret[(p+K-1)%K] = 1.0;
        return;
    }

    vector<int> m;
    for (int i=0; i<(int)M[n].size(); ++i) {
        const int t = M[n][i];
        if (t<=n && no_strategy(n-t, (p+1)%K, p)) {
            m.push_back(t);
        }
    }
    if (m.size() > 0) {
        const long double P = 1.0/m.size();
        for (int i=0; i<(int)m.size(); ++i) {
            const int t = m[i];
            strategy(n-t, (p+1)%K);
            const vector<long double> &next = s_dp[n-t][(p+1)%K];
            for (int j=0; j<K; ++j) {
                ret[j] += P*next[j];
            }
        }
    } else {
        for (int i=0; i<(int)M[n].size(); ++i) {
            const int t = M[n][i];
            if (t <= n) {
                strategy(n-t, (p+1)%K);
                const vector<long double> &next = s_dp[n-t][(p+1)%K];
                if (next[p] > eps) {
                    m.push_back(t);
                }
            }
        }
        if (m.size() > 0) {
            const long double P = 1.0/m.size();
            for (int i=0; i<(int)m.size(); ++i) {
                const int t = m[i];
                strategy(n-t, (p+1)%K);
                const vector<long double> &next = s_dp[n-t][(p+1)%K];
                for (int j=0; j<K; ++j) {
                    ret[j] += P*next[j];
                }
            }
        } else {
            for (int i=0; i<(int)M[n].size(); ++i) {
                const int t = M[n][i];
                if (t <= n) {
                    m.push_back(t);
                }
            }
            if (m.size() > 0) {
                const long double P = 1.0/m.size();
                for (int i=0; i<(int)m.size(); ++i) {
                    const int t = m[i];
                    strategy(n-t, (p+1)%K);
                    const vector<long double> &next = s_dp[n-t][(p+1)%K];
                    for (int j=0; j<K; ++j) {
                        ret[j] += P*next[j];
                    }
                }
            }
        }
    }
   /* cerr << n << ' ' << p << ":: ";
    for (int i=0; i<K; ++i) {
        cerr << ret[i] << ' ';
    }
    cerr << " (";
    for (int i=0; i<(int)m.size(); ++i) {
        cerr << m[i] << ' ';
    }
    cerr << ")";
    for (int i=0; i<(int)M[n].size(); ++i) {
        cerr << M[n][i] << ' ';
    }
    cerr << '\n';*/
}

class NimForK {
	public:
	vector <int> winners(int n, int k, vector <string> moves) {
        K = k;
        M.assign(moves.size()+1, vector<int>());
        for (int i=0; i<(int)moves.size(); ++i) {
            istringstream is(moves[i]);
            int x;
            while (is >> x) {
                M[i+1].push_back(x);
            }
        }

        memset(s_done, 0, sizeof s_done);
        memset(ns_done, 0, sizeof ns_done);

        strategy(n, 0);
        const vector<long double> &t = s_dp[n][0];

        vector<int> sol;
        for (int i=0; i<(int)t.size(); ++i) {
            cerr << i << ' ' << t[i] << '\n';
            if (t[i] > eps) {
                sol.push_back(i+1);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 2; string Arr2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, winners(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 2; string Arr2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, winners(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; string Arr2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, winners(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; string Arr2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, winners(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 20; string Arr2[] = {""}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, winners(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NimForK ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

