#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FloorLayout {
	public:
	int countBoards(vector <string> layout) {
		int sol = 0;
		for (int i=0; i<(int)layout.size(); ++i) {
			for (int j=0; j<(int)layout[0].size(); ++j) {
				if (layout[i][j] != '.') {
					++sol;
					char init = layout[i][j];
					int di, dj;
					if (init == '-') {
						di = 0;
						dj = 1;
					} else {
						di = 1;
						dj = 0;
					}
					int r = i;
					int c = j;
					while (r<(int)layout.size() && c<(int)layout[0].size() && layout[r][c]==init) {
						layout[r][c] = '.';
						r += di;
						c += dj;
					}
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"----"
,"----"
,"----"
,"----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countBoards(Arg0)); }
	void test_case_1() { string Arr0[] = {"-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(1, Arg1, countBoards(Arg0)); }
	void test_case_2() { string Arr0[] = {"--------"
,"|------|"
,"||----||"
,"|||--|||"
,"||----||"
,"|------|"
,"--------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, countBoards(Arg0)); }
	void test_case_3() { string Arr0[] = {"||-||-|||-"
,"||--||||||"
,"-|-|||||||"
,"-|-||-||-|"
,"||--|-||||"
,"||||||-||-"
,"|-||||||||"
,"||||||||||"
,"||---|--||"
,"-||-||||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 41; verify_case(3, Arg1, countBoards(Arg0)); }
	void test_case_4() { string Arr0[] = {"-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, countBoards(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FloorLayout ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
