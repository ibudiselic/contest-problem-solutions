#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class LargestCountry {
	public:
	string getLargest(vector <string> worldMap) {
		map<char, int> m;

		for (int i=0; i<(int)worldMap.size(); ++i)
			for (int j=0; j<(int)worldMap[i].size(); ++j)
				++m[worldMap[i][j]];

		int best = 0;
		char bestc = '-';

		for (map<char, int>::const_iterator it=m.begin(); it!=m.end(); ++it)
			if (it->first!=' ' && it->second>best) {
				best = it->second;
				bestc = it->first;
			}

		return string(1, bestc);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AAA","CA "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arr0[] = {"ACA","CAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABZ","CXC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C"; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAA","CA "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(3, Arg1, getLargest(Arg0)); }
	void test_case_4() { string Arr0[] = {" A "," B "," X "," B "," X "," X "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "X"; verify_case(4, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LargestCountry ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
