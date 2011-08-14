#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}

struct Res {
    long long a, b;
    Res(long long a_, long long b_): a(a_), b(b_) {}
    void inv() {
        swap(a, b);
    }
    void reduce() {
        long long d = gcd(a, b);
        a /= d;
        b /= d;
    }
};
bool operator<(const Res &a, const Res &b) {
    return a.a*b.b < a.b*b.a;
}
Res operator+(const Res &a, const Res &b) {
    long long x = a.b * b.b;
    Res ret(a.a*b.b + b.a*a.b, x);
    ret.reduce();
    return ret;
}
Res operator-(const Res &a, const Res &b) {
    long long x = a.b * b.b;
    Res ret(a.a*b.b - b.a*a.b, x);
    ret.reduce();
    return ret;
}

Res serial(const Res &a, const Res &b) {
    Res ret = a + b;
    ret.reduce();
    return ret;
}
Res parallel(Res a, Res b) {
    a.inv();
    b.inv();
    Res ret = a + b;
    ret.inv();

    ret.reduce();
    return ret;
}

Res unpar(Res a, Res par) {
    par.inv();
    a.inv();
    Res b = par - a;
    b.inv();
    b.reduce();

    return b;
}

vector<set<Res> > V;

bool can(int n, const Res &X) {
    if (n <= 10) {
        return V[n].find(X) != V[n].end();
    }

    for (int i=1; i<=n/2; ++i) {
        for (set<Res>::const_iterator it=V[i].begin(); it!=V[i].end(); ++it) {
            if (*it < X) {
                if (can(n-i, X-*it)) {
                    return true;
                }
            } else {
                assert(X < *it);
                if (can(n-i, unpar(*it, X))) {
                    return true;
                }
            }
        }
    }

    return false;
}

class BuildCircuit {
	public:
	int minimalCount(int a, int b) {
        V.clear();
        set<Res> S;
        V.push_back(S);
        S.insert(Res(1, 1));
        S.insert(Res(2, 1));
        set<Res> all = S;
        V.push_back(S);
        for (int i=2; i<=11; ++i) {
            S.clear();
            for (int j=1; j<=i/2; ++j) {
                int k = i - j;
                for (set<Res>::const_iterator it=V[j].begin(); it!=V[j].end(); ++it) {
                    for (set<Res>::const_iterator it2=V[k].begin(); it2!=V[k].end(); ++it2) {
                        S.insert(serial(*it, *it2));
                        S.insert(parallel(*it, *it2));
                    }
                }
            }

            set<Res> t;
            set_difference(S.begin(), S.end(), all.begin(), all.end(), inserter(t, t.end()));
            set_union(t.begin(), t.end(), all.begin(), all.end(), inserter(all, all.end()));
            V.push_back(t);
        }

        Res X(a, b);
        X.reduce();
        for (int i=1; i<11; ++i) {
            if (V[i].find(X) != V[i].end()) {
                return i;
            }
        }

        for (int i=11; i<=16; ++i) {
            if (can(i, X)) {
                return i;
            }
        }

        return -1;
    }






   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, minimalCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, minimalCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 3; verify_case(2, Arg2, minimalCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 42; int Arg1 = 47; int Arg2 = 7; verify_case(3, Arg2, minimalCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 20; int Arg2 = -1; verify_case(4, Arg2, minimalCount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 756; int Arg1 = 874; int Arg2 = 10; verify_case(5, Arg2, minimalCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BuildCircuit ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
