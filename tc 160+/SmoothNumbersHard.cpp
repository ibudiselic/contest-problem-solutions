#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int G[5000001];
bool P[1001];
class SmoothNumbersHard {
	public:
	int countSmoothNumbers(int N, int k) {
		G[0] = 0;
		G[1] = 1;
		G[2] = 2;
		int sol = 0;
		if (N >= 1) {
			sol += (k>=1);
		}
		if (N >= 2) {
			sol += (k>=2);
		}

		memset(P, 1, sizeof P);
		P[0] = P[1] = 0;
		for (int x=4; x<=1000; x+=2) {
			P[x] = 0;
		}
		for (int x=3; x<=1000; x+=2) {
			if (P[x]) {
				for (int y=3*x; y<=1000; y+=2*x) {
					P[y] = 0;
				}
			}
		}

		vector<int> p;
		for (int i=0; i<1000; ++i) {
			if (P[i]) {
				p.push_back(i);
			}
		}

		for (int x=3; x<=N; ++x) {
			for (int i=0; i<(int)p.size(); ++i) {
				if (x%p[i] == 0) {
					G[x] = max(p[i], G[x/p[i]]);
					goto DONE;
				}
			}
			G[x] = x;
			DONE: ;
			sol += (G[x] <= k);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7; verify_case(0, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 7; verify_case(1, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 3; int Arg2 = 8; verify_case(2, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 5; verify_case(3, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 123456; int Arg1 = 123; int Arg2 = 23855; verify_case(4, Arg2, countSmoothNumbers(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SmoothNumbersHard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
