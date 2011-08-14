#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
int encodePerm(vector<int> order) {
	static int fact[] = { 1, 1, 2, 6, 24, 120, 720 };

	int ret = 0;
	for (int i=(int)order.size()-1; i>=0; --i) {
		int j=0;
		while (order[j] != i) {
			++j;
			assert(j<(int)order.size());
		}

		ret += j * fact[i];
		order[j] = order[i];
	}

	return ret;
}
vector<int> decodePerm(int code, int n) {
	static int fact[] = { 1, 1, 2, 6, 24, 120, 720 };

	vector<int> order(n, -1);

	for (int i=n-1; i>=0; --i) {
		int pos = code/fact[i];
		code %= fact[i];
		while (order[pos] != -1)
			pos = order[pos];
		order[pos] = i;
	}

	return order;
}

double winProb(int i, int j) {
	double p = double(A[i])/(A[i]+A[j]);
	return p*p;
}

double transitionProb[5040][7];
int transitionNextState[5040][7];
class KingOfTheCourt {
	public:
	double chancesOfWinning(vector <int> ability) {
		A = ability;
		int n = A.size();

		vector<int> order(n, 0);
		for (int i=0; i<n; ++i)
			order[i] = i;

		int startCode = encodePerm(order);
		int nPerm = 0;
		do {
			assert(decodePerm(encodePerm(order), n) == order);
			int code = encodePerm(order);
			double p = 1.0;
			for (int i=1; i<n; ++i) {
				double iWinProb = winProb(order[i], order[0]);
				transitionProb[code][i] = p*iWinProb;

				p *= (1-iWinProb);
				// permutation if king loses
				vector<int> newPerm;
				for (int j=i; j<n; ++j)
					newPerm.push_back(order[j]);
				for (int j=1; j<i; ++j)
					newPerm.push_back(order[j]);
				newPerm.push_back(order[0]);

				transitionNextState[code][i] = encodePerm(newPerm);
			}

			transitionProb[code][0] = (order[0]==0 ? p : 0.0);
			++nPerm;
		} while (next_permutation(order.begin(), order.end()));

		vector<double> fromPermWin(nPerm, 0.0);
		for (int iteration=0; iteration<2000; ++iteration)
			for (int perm=0; perm<nPerm; ++perm) {
				fromPermWin[perm] = transitionProb[perm][0];
				for (int i=1; i<n; ++i)
					fromPermWin[perm] += transitionProb[perm][i] * fromPermWin[transitionNextState[perm][i]];
			}

		return fromPermWin[startCode];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(0, Arg1, chancesOfWinning(Arg0)); }
	void test_case_1() { int Arr0[] = { 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.9350649350649349; verify_case(1, Arg1, chancesOfWinning(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5844155844155844; verify_case(2, Arg1, chancesOfWinning(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5065812082824602; verify_case(3, Arg1, chancesOfWinning(Arg0)); }
	void test_case_4() { int Arr0[] = { 47, 82, 65, 99, 2, 14, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.22734781036506918; verify_case(4, Arg1, chancesOfWinning(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KingOfTheCourt ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
