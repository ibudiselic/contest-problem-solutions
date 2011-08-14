#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

struct State {
    int p, g;
    bool no_smaller;
    vector<int> v;
    State(int p_, int g_, bool no_smaller_, const vector<int> &v_): p(p_), g(g_), no_smaller(no_smaller_), v(v_) {}
};

bool operator<(const State &a, const State &b) {
    if (a.p != b.p) {
        return a.p < b.p;
    } else if (a.g != b.g) {
        return a.g < b.g;
    } else if (a.no_smaller != b.no_smaller) {
        return (a.no_smaller == false);
    } else {
        return a.v < b.v;
    }
}

map<State, int> M;
int D;
string N;

bool pred(const vector<int> &v) {
    for (int i=0; i<10; ++i) {
        assert(v[i]==0 || v[i]==D);
    }

    return true;
}
bool go(int p, int g, int gu, bool no_smaller, vector<int> &v) {
    if (p == (int)N.size()) {
        assert(pred(v));
        return true;
    }
    State s(p, g, no_smaller, v);
    if (M.count(s)) {
        return (M[s] != -1);
    }

    int dig = -1;
    int start = no_smaller ? N[p]-'0' : 0;
    for (int i=start; i<10; ++i) {
        if (v[i]==0 && gu==g || v[i]==D) {
            continue;
        }
        ++v[i];
        bool ok = go(p+1, g, gu+(v[i]==1), no_smaller && (i==start), v);
        --v[i];
        if (ok) {
            dig = i;
            break;
        }
    }

    M[s] = dig;
    return (dig != -1);
}

bool calc(int p, bool no_smaller, vector<int> &v) {
    bool ret = false;
    for (int i=1; i<=10; ++i) {
        if ((int)N.size() % i == 0) {
            D = N.size()/i;
            ret |= go(p, i, 0, no_smaller, v);
            assert(v == vector<int> (10, 0));
        }
    }

    return ret;
}

long long to_ll(const string &s) {
    long long x = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        x = 10*x + s[i]-'0';
    }

    return x;
}
long long reconstruct(long long x, int p, int g, int gu, bool no_smaller, vector<int> &v) {
    if (p == (int)N.size()) {
        return x;
    }

    int dig = M[State(p, g, no_smaller, v)];
    assert(dig != -1);
    
    ++v[dig];
    long long ret = reconstruct(x*10 + dig, p+1, g, gu+(v[dig]==1), no_smaller && (dig==N[p]-'0'), v);
    --v[dig];

    return ret;
}
    
long long reconstruct(int p, bool no_smaller, vector<int> &v) {
    set<long long> S;
    for (int i=1; i<=10; ++i) {
        if ((int)N.size() % i == 0) {
            D = N.size()/i;
            if (go(p, i, 0, no_smaller, v)) {
                S.insert(reconstruct(0, p, i, 0, no_smaller, v));
                assert(v == vector<int> (10, 0));
            }
        }
    }

    return *S.begin();
}
class EquiDigitNumbers {
	public:
	long long findNext(string n) {
		M.clear();
        N = n;
        vector<int> v(10, 0);
        
        if (calc(0, true, v)) {
            return reconstruct(0, true, v);
        } else {
            M.clear();
            N = string(n.size()+1, '0');
            N[0] = '1';
            calc(0, true, v);
            return reconstruct(0, true, v);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "42"; long long Arg1 = 42LL; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "2008"; long long Arg1 = 2013LL; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "987654322"; long long Arg1 = 987778899LL; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "12345678910"; long long Arg1 = 22222222222LL; verify_case(3, Arg1, findNext(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EquiDigitNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
