#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <cmath>

using namespace std;

int m, n;
bool G[201][201];
long long sqr(long long x) {
    return x*x;
}
bool is_square(long long x) {
    long long cand = (long long)(sqrt(x) + 0.5);
    return cand*cand == x;
}
int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int v[201];
int match[201];
int rmatch[201];
bool find_match(int x) {
    v[x] = true;
    for (int y=0; y<n; ++y) {
        if (!G[x][y]) {
            continue;
        }
        if (rmatch[y]==-1 || (!v[rmatch[y]] && find_match(rmatch[y]))) {
            match[x] = y;
            rmatch[y] = x;
            return true;
        }
    }
    return false;
}
int bipartite_match_size() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    int ret = 0;
    for (int i=0; i<m; ++i) {
        if (match[i] == -1) {
            memset(v, 0, sizeof v);
            ret += find_match(i);
        }
    }
    return ret;
}
class PythTriplets {
	public:
	int findMax(vector <string> stick) {
		string s = accumulate(stick.begin(), stick.end(), string());
        int x;
        vector<int> O, E;
        istringstream is(s);
        while (is >> x) {
            if (x & 1) {
                O.push_back(x);
            } else {
                E.push_back(x);
            }
        }
        m = O.size();
        n = E.size();
        memset(G, 0, sizeof G);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (gcd(O[i], E[j])==1 && is_square(sqr(O[i]) + sqr(E[j]))) {
                    G[i][j] = true;
                }
            }
        }
        
        return bipartite_match_size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 4 4 3 11 5 12 9 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"20 21 3021 220"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, findMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"28 19", "5 1035 21412 37995"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, findMax(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PythTriplets ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
