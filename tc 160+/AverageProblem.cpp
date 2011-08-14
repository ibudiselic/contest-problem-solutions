#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> V;
bool test(long long cnt, long long p) {
	long long S = cnt*p;

	if (S%1000 != 0)
		S += (1000-S%1000);

	return (S/cnt==p && S<=cnt*10000);
}
bool ok(long long cnt) {
	for (int i=0; i<(int)V.size(); ++i)
		if (!test(cnt, V[i]))
			return false;
	return true;
}
class AverageProblem {
	public:
	int numberOfParticipants(vector <string> marks) {
		V.clear();
		for (int i=0; i<(int)marks.size(); ++i) {
			istringstream is(marks[i]);
			string w;
			while (is >> w) {
				int a, b;
				sscanf(w.c_str(), "%d.%d", &a, &b);
				V.push_back(a*1000+b);
			}
		}

		for (int i=1; ; ++i)
			if (ok(i))
				return i;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0.000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numberOfParticipants(Arg0)); }
	void test_case_1() { string Arr0[] = {"0.500 0.250", "0.125"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, numberOfParticipants(Arg0)); }
	void test_case_2() { string Arr0[] = {"0.500","0.300"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfParticipants(Arg0)); }
	void test_case_3() { string Arr0[] = {"0.500","0.301"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 106; verify_case(3, Arg1, numberOfParticipants(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AverageProblem ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
