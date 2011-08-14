#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>

using namespace std;

vector< pair<int, int> > get(int A) {
    vector< pair<int, int> > v;
    for (long long x=0; x*x<=A; ++x) {
        long long y = (long long)sqrt(A - x*x);
        if (x*x + y*y == A) {
            for (int s1=-1; s1<2; s1+=2) {
                for (int s2=-1; s2<2; s2+=2) {
                    v.push_back(make_pair(s1*x, s2*y));
                }
            }
        }
    }
    return v;
}

long long my_abs(long long x) {
    return x>0 ? x : -x;
}
long long area(const pair<int, int> &a, const pair<int, int> &b, int A, int B) {
    return my_abs((long long)a.first*b.second - (long long)a.second*b.first);
}
class MaxTriangle {
	public:
	double calculateArea(int A, int B) {
		vector< pair<int, int> > la, lb;
        la = get(A);
        lb = get(B);
        
        long long best = 0;
        for (int i=0; i<(int)la.size(); ++i) {
            for (int j=0; j<(int)lb.size(); ++j) {
                best = max(best, area(la[i], lb[j], A, B));
            }
        }
        
        return best==0 ? -1.0 : best/2.0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; double Arg2 = -1.0; verify_case(1, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 41; int Arg1 = 85; double Arg2 = 29.5; verify_case(2, Arg2, calculateArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MaxTriangle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
