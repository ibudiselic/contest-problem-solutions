#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Perm {
	public:
		Perm(int n): repr(n, 0) {
			for (int i=0; i<n; ++i) {
				repr[i] = i;
			}
		}
		int size() const {
			return (int)repr.size();
		}
		int& operator[](int i) {
			return repr[i];
		}
		const int& operator[](int i) const {
			return repr[i];
		}
	
	private:
		vector<int> repr;
};

Perm operator*(const Perm &a, const Perm &b) {
	Perm p(a.size());
	for (int i=0; i<p.size(); ++i) {
		p[i] = a[b[i]];
	}

	return p;
}

int to_int(const string &s) {
	int x;
	sscanf(s.c_str(), "%d", &x);
	return x;
}

const int mod = 987654319;
int N, side, D;

void ccw_rot(Perm &p, int from, int to, bool twice) {
	Perm rot(side);

	for (int r=D-1; r>=0; --r) {
		int mc = 2*r;
		rot[(D-1-r)*(D-1-r) + 0] = r*r + mc;

		int c = 2*r;
		int rr = D-1;
		while (c > 0) {
			for (int t=0; t<2; ++t, --c) {
				rot[rr*rr + c] = r*r + mc - c;
			}
			--rr;
		}
	}

	if (twice) {
		rot = rot*rot;
	}

	for (int i=0; i<side; ++i) {
		p[from*side + i] = rot[i] + to*side;
	}
}

Perm minus_x(int x) {
	Perm p(N);

	int n = x*x;
	for (int i=0; i<n; ++i) {
		p[i] = 2*side + i;
		p[i + side] = i;
		p[i + 2*side] = side + i;
	}

	if (n == side) {
		ccw_rot(p, 3, 3, false);
	}

	return p;
}

Perm plus_x(int x) {
	Perm p = minus_x(x);
	return p * p;
}

Perm back() {
	Perm p(N);
	ccw_rot(p, 0, 0, false);
	ccw_rot(p, 1, 2, true);
	ccw_rot(p, 2, 3, false);
	for (int i=0; i<side; ++i) {
		p[3*side + i] = side + i;
	}

	return p;
}

Perm left() { 
	return plus_x(D)*(back()*minus_x(D));
}

Perm right() {
	return minus_x(D)*(back()*plus_x(D));
}

class PyramidPuzzle {
	public:
	int repeatCount(int d, vector <string> moves) {
		D = d;
		side = d*d;
		N = 4 * side;

		Perm P(N);

		string S;
		for (int i=0; i<(int)moves.size(); ++i) {
			S += moves[i];
		}
		string s;
		istringstream is(S);
		while (is >> s) {
			switch (s[0]) {
				case '-': 
					P = minus_x(to_int(s.substr(1))) * P;
					break;
				case '+':
					P = plus_x(to_int(s.substr(1))) * P;
					break;
				case 'B':
					P = back() * P;
					break;
				case 'L':
					P = left() * P;
					break;
				case 'R':
					P = right() * P;
					break;
				default:
					return -1;
			}
		}

		vector<int> powers(N+1, 0);
		vector<bool> done(N, false);
		for (int i=0; i<N; ++i) {
			if (!done[i]) {
				int sz = 0;
				int t = i;
				while (!done[t]) {
					done[t] = true;
					++sz;
					t = P[t];
				}

				int x = 2;
				while (sz > 1) {
					int cnt = 0;
					while (sz % x == 0) {
						sz /= x;
						++cnt;
					}
					powers[x] = max(powers[x], cnt);
					++x;
				}
			}
		}

		int sol = 1;
		for (int i=2; i<=N; ++i) {
			while (powers[i]--) {
				sol = (sol * i) % mod;
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"-2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, repeatCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"-2 +2 -2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, repeatCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"B ","B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, repeatCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; string Arr1[] = {"+2 -1 +2 -1 +3 +2 -1 -3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, repeatCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; string Arr1[] = {"-", "2 L"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 72; verify_case(4, Arg2, repeatCount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; string Arr1[] = {"B +50"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(5, Arg2, repeatCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PyramidPuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
