#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Choice {
	/* u a stavi pocetne vrijednosti i
	  napravi interno niz dovoljno velik da spremi n itema */
	public:
	void init(vector<int> &a, int n) {
		assert(n >= (int)a.size());
		for (int i=0; i<(int)a.size(); ++i)
			a[i] = i;
		niz.assign(n, 0);
		for (int i=0; i<(int)a.size(); ++i)
			niz[i] = 1;
	}
	bool next(vector<int> &a) {
		int passed = 0;
		for (int i=0; i<(int)niz.size(); ++i) {
			if (niz[i] == 1) {
				if (i == (int)niz.size()-1)
					return false;
				if (niz[i+1] == 1) {
					++passed;
					continue;
				} else {
					niz[i] = 0;
					niz[i+1] = 1;
					++a[passed];
					break;
				}
			}
		}
		for (int i=0; i<passed; ++i)
			a[i] = i;
		int t = passed;
		for (int i=0; passed>0 && i<(int)niz.size(); ++i)
			if (niz[i]==1) {
				--passed;
				niz[i] = 0;
			}
		for (int i=0; i<t; ++i)
			niz[i] = 1;
		return true;
	}
	void ispis() {
		for (int i=0; i<(int)niz.size(); ++i)
			cerr << int(niz[i]) << ' ';
		cerr << '\n';
	}
	private:
	vector<char> niz;
};

long long sqr(long long x) {
	return x*x;
}
class FindTriangle {
	public:
	double largestArea(vector <string> points) {
		const int n = points.size();
		vector<int> x(n), y(n), z(n);
		vector<char> c(n);
		for (int i=0; i<n; ++i) {
			istringstream is(points[i]);
			is >> c[i] >> x[i] >> y[i] >> z[i];
		}

		double best = -1.0;
		vector<int> a(3);
		Choice X;
		X.init(a, n);
		do {
			if (c[a[0]]==c[a[1]] && c[a[1]]==c[a[2]] && c[a[2]]==c[a[0]] ||
					c[a[0]]!=c[a[1]] && c[a[1]]!=c[a[2]] && c[a[2]]!=c[a[0]]) {
					  int A, B, C, D, E, F;
						A = x[a[1]] - x[a[0]]; B = y[a[1]] - y[a[0]]; C = z[a[1]] - z[a[0]];
						D = x[a[2]] - x[a[0]]; E = y[a[2]] - y[a[0]]; F = z[a[2]] - z[a[0]];
					best = max(best, 0.5 * sqrt(sqr(B*F-C*E) + sqr(C*D-A*F) + sqr(A*E - B*D)));
			}
		} while (X.next(a));

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "G 92 14 7",
 "G 12 16 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 6.0; verify_case(0, Arg1, largestArea(Arg0)); }
	void test_case_1() { string Arr0[] = {"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "G 0 5 0",
 "B 0 0 12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 30.0; verify_case(1, Arg1, largestArea(Arg0)); }
	void test_case_2() { string Arr0[] = {"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "R 90 0 3",
 "G 2 14 7",
 "G 2 18 7",
 "G 29 14 3",
 "B 12 16 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 225.0; verify_case(2, Arg1, largestArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"R 0 0 0",
 "R 1 1 0",
 "R 4 4 0",
 "G 10 10 10",
 "G 0 1 2"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, largestArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FindTriangle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
