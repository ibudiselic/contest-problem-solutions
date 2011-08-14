#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

const int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
class GeneralChess {
	public:
	vector <string> attackPositions(vector <string> pieces) {
		map< pair<int, int>, int > M;

		for (int i=0; i<(int)pieces.size(); ++i) {
			int r, c;
			sscanf(pieces[i].c_str(), "%d,%d", &r, &c);

			for (int d=0; d<8; ++d)
				++M[make_pair(r+di[d], c+dj[d])];
		}

		vector<string> sol;
		for (map< pair<int, int>, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
			if (it->second == (int)pieces.size()) {
				ostringstream os;
				os << it->first.first << ',' << it->first.second;
				sol.push_back(os.str());
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-2,-1",  "-2,1",  "-1,-2",  "-1,2",  "1,-2",  "1,2",  "2,-1",  "2,1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, attackPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"2,1", "-1,-2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0,0",  "1,-1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, attackPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"0,0", "2,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, attackPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"-1000,1000", "-999,999", "-999,997"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-1001,998" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, attackPositions(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GeneralChess ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
