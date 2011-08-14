#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> solR, solC;
vector<string> R, C;
vector< vector<string> > T;
int M, N;
bool multiple;

bool ew(const string &s, const string &t) {
	if (t.size() > s.size())
		return false;
	for (int i=0; i<(int)t.size(); ++i)
		if (s[s.size()-1-i] != t[t.size()-1-i])
			return false;

	return true;
}
void test() {
	for (int i=1; i<M; ++i) {
		if (!ew(T[i][0], C[0]))
			return;
		R[i] = T[i][0].substr(0, T[i][0].size()-C[0].size());
		if (R[i] == "")
			return;

		for (int j=1; j<N; ++j) {
			if (!ew(T[i][j], C[j]))
				return;
			if (R[i] != T[i][j].substr(0, T[i][j].size()-C[j].size()))
				return;
		}
	}

	if (solR.size() > 0) {
		multiple = true;
		return;
	}
	solR = R;
	solC = C;
}
void go() {
	int sz = 1234567890;
	for (int j=0; j<N; ++j)
		sz = min(sz, (int)T[0][j].size());

	for (int i=0; i<sz-1; ++i) {
		char c = T[0][0][i];
		for (int j=1; j<N; ++j)
			if (T[0][j][i] != c)
				return;

		R[0] = T[0][0].substr(0, i+1);
		for (int j=0; j<N; ++j)
			C[j] = T[0][j].substr(i+1);

		test();
	}
}
class TableLabel {
	public:
	vector <string> labels(vector <string> table) {
		T.clear();

		for (int i=0; i<(int)table.size(); ++i) {
			T.push_back(vector<string>());
			string s;
			istringstream is(table[i]);
			while (is >> s)
				T.back().push_back(s);
		}

		M = T.size();
		N = T[0].size();

		R.assign(M, string());
		C.assign(N, string());

		solR.clear();
		solC.clear();
		multiple = false;

		go();

		if (solR.size() == 0)
			return vector<string> (1, "none");
		else if (multiple)
			return vector<string> (1, "multiple");

		vector<string> sol = C;
		copy(R.begin(), R.end(), back_inserter(sol));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"  ABCX ABCXX   ABCXXX  ","DX DXX DXXX    "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "XX", "XXX", "ABC", "D" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, labels(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAA AAA"," AAA   AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"multiple" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, labels(Arg0)); }
	void test_case_2() { string Arr0[] = {"AB CD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"none" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, labels(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TableLabel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
