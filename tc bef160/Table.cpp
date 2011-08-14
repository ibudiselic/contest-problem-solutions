#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Table {
	public:
	vector <string> layout(vector <string> tbl) {
		vector<string> a(50, string(50, 0));

		for (vector<string>::size_type i=0; i<tbl.size(); ++i) {
			string::size_type k = 0;
			string::size_type t = 0;
			for (string::size_type j=0; j<tbl[i].size(); ++j) {
				if (tbl[i][j] == ')') {
					int r, c;
					char d;
					sscanf(tbl[i].substr(t, j-t+1).c_str(), "(%d,%d,%c)", &c, &r, &d);
					t = j+1;
					while (a[i][k])
						++k;
					assert(k+c<=50);
					for (int x=0; x<r; ++x)
						for (int y=0; y<c; ++y)
							a[i+x][k+y] = d;
				}
			}
		}
		vector<string> sol;
		for (vector<string>::size_type i=0; i<tbl.size(); ++i)
			sol.push_back(a[i].substr(0, a[i].find((char)0)));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"(1,1,A)(2,1,B)(1,1,C)(1,1,D)",
 "(1,1,E)(1,1,F)(1,1,G)(1,1,H)(1,1,I)",
 "(1,3,J)(1,1,K)(3,2,L)",
 "(1,1,M)",
 "(1,1,N)(1,1,O)(1,1,P)(1,1,Q)",
 "(1,1,R)(1,1,S)(1,1,T)(1,1,U)(1,1,V)"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ABBCD",  "EFGHI",  "JKLLL",  "JMLLL",  "JNOPQ",  "RSTUV" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, layout(Arg0)); }
	void test_case_1() { string Arr0[] = {"(1,3,N)(3,2,E)(3,1,M)(1,1,Q)",
 "(1,1,T)(3,1,U)",
 "(1,1,Y)(4,5,A)(1,2,V)(1,2,W)",
 "(1,3,G)(1,3,Z)",
 "(1,2,S)(1,3,D)",
 "",
 "(1,2,P)(1,2,F)(1,3,J)",
 "(1,1,L)(3,3,K)(1,1,R)",
 "(3,2,B)(1,1,D)",
 "(2,1,A)",
 "(2,3,O)(4,1,X)(1,1,I)(1,1,B)",
 "(3,2,H)(3,2,C)",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "NEEEMMMQ",  "NEEETUUU",  "NYAAAAVW",  "GZAAAAVW",  "GZAAAASD",  "GZAAAASD",  "PFAAAAJD",  "PFLKKKJR",  "BBBKKKJD",  "BBBKKKAA",  "OOXXXXIB",  "OOHHHCCC",  "OOHHHCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, layout(Arg0)); }
	void test_case_2() { string Arr0[] = {"(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,5,G)(9,5,H)(9,5,I)(9,5,J)(9,5,K)(5,5,L)",
 "","","",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, layout(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Table ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
