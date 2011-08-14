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

class RectangleGroups {
	public:
	string maximalIndexed(vector <string> rectangles) {
		map<string, int> M;
		for (int i=0; i<(int)rectangles.size(); ++i) {
			istringstream is(rectangles[i]);
			string name;
			int x, y;
			is >> name >> x >> y;
			M[name] += x*y;
		}

		map<string, int>::const_iterator best = M.begin();
		for (map<string, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
			if (best->second < it->second)
				best = it;

		ostringstream os;
		os << (best->first) << ' ' << (best->second);
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A 1 2", "A 3 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A 11"; verify_case(0, Arg1, maximalIndexed(Arg0)); }
	void test_case_1() { string Arr0[] = {"A 1 2", "B 3 3", "A 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "B 9"; verify_case(1, Arg1, maximalIndexed(Arg0)); }
	void test_case_2() { string Arr0[] = {"D 1 6", "F 2 3", "G 1 1", "G 5 1", "C 3 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C 6"; verify_case(2, Arg1, maximalIndexed(Arg0)); }
	void test_case_3() { string Arr0[] = {"S 2 54", "Y 34 65", "F 234 23", "D 84 127", "R 603 46",
"S 36 192", "Y 76 32", "T 54 28", "S 22 22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R 27738"; verify_case(3, Arg1, maximalIndexed(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RectangleGroups ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
