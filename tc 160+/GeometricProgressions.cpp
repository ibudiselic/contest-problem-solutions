#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, int> f(int x) {
    map<int, int> ret;
    if (x == 0) {
        return ret;
    }
    ret[1] = 0;
    if (x == 1) {
        return ret;
    }
    long long d = 2;
    while (d*d <= x) {
        int cnt = 0;
        while (x%d == 0) {
            ++cnt;
            x /= d;
        }
        if (cnt > 0) {
            ret[d] = cnt;
        }
        ++d;
    }
    if (x > 1) {
        ret[x] = 1;
    }
    return ret;
}
void add(map<int, int> &a, const map<int, int> &b) {
    for (map<int, int>::const_iterator it=b.begin(); it!=b.end(); ++it) {
        a[it->first] += it->second;
    }
}
class GeometricProgressions {
	public:
	int count(int b1, int q1, int n1, int b2, int q2, int n2) {
		map<int, int> v1 = f(b1);
        map<int, int> v2 = f(b2);
        map<int, int> d1 = f(q1);
        map<int, int> d2 = f(q2);
        
        set< map<int, int> > S;
        if (b1 == 0) {
            S.insert(map<int, int>());
        } else if (q1 == 0) {
            S.insert(v1);
            if (n1 > 1) {
                S.insert(map<int, int>());
            }
        } else {
            for (int i=0; i<n1; ++i) {
                S.insert(v1);
                add(v1, d1);
            }
        }
        
        int removed = 0;
        if (b2 == 0) {
            S.insert(map<int, int>());
        } else if (q2 == 0) {
            S.insert(v2);
            if (n2 > 1) {
                S.insert(map<int, int>());
            }
        } else {
            for (int i=0; i<n2; ++i) {
                try {
                    S.insert(v2);
                } catch (...) {
                    for (int j=0; j<100; ++j) {
                        S.erase(S.begin());
                        ++removed;
                    }
                    i -= 1;
                    continue;
                }
                add(v2, d2);
            }
        }
        
        return removed + S.size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 6; int Arg4 = 2; int Arg5 = 5; int Arg6 = 6; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 5; int Arg6 = 9; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 100500; int Arg3 = 48; int Arg4 = 1024; int Arg5 = 1000; int Arg6 = 100500; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GeometricProgressions ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
