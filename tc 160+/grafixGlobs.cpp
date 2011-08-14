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

struct Glob {
	vector<int> v;
	void inc(int i) { ++v[i]; }
	Glob() { v.assign(3, 0); }
};

/*
make OBJ
delete ID
merge ID ID
split ID

arc
circle
polygon
*/

int getLowest(const map<int, Glob> &M) {
	for (int i=0; ; ++i)
		if (M.count(i) == 0)
			return i;
	return -1;
}
class grafixGlobs {
	public:
	vector <int> execute(vector <string> commands, int sel) {
		map<int, Glob> M;

		for (int i=0; i<(int)commands.size(); ++i) {
			istringstream is(commands[i]);
			string cmd;
			is >> cmd;

			if (cmd == "make") {
				int ind = getLowest(M);

				string obj;
				is >> obj;
				if (obj == "arc")
					M[ind].inc(0);
				else if (obj == "circle")
					M[ind].inc(1);
				else
					M[ind].inc(2);
			} else if (cmd == "delete") {
				int id;
				is >> id;

				M.erase(id);
			} else if (cmd == "merge") {
				int t, s;
				is >> t >> s;
				for (int i=0; i<3; ++i)
					M[t].v[i] += M[s].v[i];
				M.erase(s);
			} else {
				int id;
				is >> id;

				Glob t = M[id];
				M.erase(id);
				for (int k=0; k<3; ++k)
				for (int i=0; i<(int)t.v[k]; ++i) {
					int ind = getLowest(M);
					M[ind].inc(k);
				}
			}
		}

		if (M.count(sel) == 0)
			return vector<int>();

		return M[sel].v;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"make polygon", "make circle", "make polygon", "merge 0 1", "merge 2 0", "split 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, execute(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, execute(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, execute(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"make arc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, execute(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"make polygon", "make polygon", "make arc", "make circle",
 "make circle", "delete 3", "make polygon", "make arc",
 "make arc", "merge 1 3", "merge 1 4", "merge 2 1", "make arc",
 "make arc", "make circle", "make circle", "merge 6 5",
 "split 6", "merge 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { 2,  1,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, execute(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    grafixGlobs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
