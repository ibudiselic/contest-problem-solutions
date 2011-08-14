#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
class Provinces {
	public:
	int maximalNumber(int n, vector <string> roads) {
		string s;
		for (int i=0; i<(int)roads.size(); ++i)
			s += roads[i];

		vector< vector<int> > backEdges(n, vector<int> ());
		vector<string> E = cutUp(s, ",");

		for (int i=0; i<(int)E.size(); ++i) {
			int x, y;
			istringstream is(E[i]);
			is >> x >> y;

			if (x > y)
				backEdges[x-1].push_back(y-1);
		}

		for (int sz=1; sz<n; ++sz)
			if (n%sz == 0) {
				for (int first=0; first<n; first+=sz)
					for (int i=first; i<first+sz; ++i)
						for (int j=0; j<(int)backEdges[i].size(); ++j)
							if (backEdges[i][j] < first)
								goto fail;

				return n/sz;
				fail:
				;
			}

		return 1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; string Arr1[] = {"2 1,3 2,6 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, maximalNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, maximalNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, maximalNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, maximalNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; string Arr1[] = {"3 1,", "7 6,", "1 1", "0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maximalNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Provinces ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
