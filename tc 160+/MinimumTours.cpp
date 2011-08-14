#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MinimumTours {
	public:
	int getMinimumTours(vector <string> islandMap) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"..x..x..x..",
"..x..x..x..",
"..x..x..x..",
"..x..x..x.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumTours(Arg0)); }
	void test_case_1() { string Arr0[] = {
"x....x....x",
".....x.....",
".....x.....",
".....x.....",
"xxxxxxxxxxx",
".....x.....",
".....x.....",
".....x.....",
"x....x....x"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getMinimumTours(Arg0)); }
	void test_case_2() { string Arr0[] = {
"x....x....x",
".....x.....",
".....x.....",
"....x.x....",
"xxxx...xxxx",
"....x.x....",
".....x.....",
".....x.....",
"x....x....x"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getMinimumTours(Arg0)); }
	void test_case_3() { string Arr0[] = {
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"x............................x",
"x..xxxxxxxxxx....xxxxxxxxxx..x",
"x..x........x....x........x..x",
"x..x..xxxx..x....x.xxxxxx.x..x",
"x..x........x....x.x....x.x..x",
"x..xxxxxxxxxx....x.x.x..x.x..x",
"x................x.x....x.x..x",
"x................x.xxxxxx.x..x",
"x..xxxxxxxxxx....x........x..x",
"x..x........x....x........x..x",
"x..x..xxxx..x....x.xxxxxx.x..x",
"x..x........x....x........x..x",
"x..xxxxxxxxxx....xxxxxxxxxx..x",
"x............................x",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getMinimumTours(Arg0)); }
	void test_case_4() { string Arr0[] = {
"xxxxxxxxxxxxx....xxxxxxxxxxxxxxxxxxxxxx",
"x...........x....x.....................",
"x.xxxxxxxxx.x....x.xxxxxxxxxxxxxxxxxxx.",
"x.x.......x.x....x.x.................x.",
"x.x.xxxxx.x.x....x.x.xxxxxxxxxxx.....x.",
"x.x...x...x.x....x.x.x..........x....x.",
"x.x...x...x.x....x.x.x.xxx..xxx...x..x.",
"x.x.......x.x....x.x.x.x....x..x..x..x.",
"x.xxxxxxxxx.x....x.x.x.xxx..x..x..x..x.",
"x...........x....x.x.x.x....x..x..x..x.",
"xxxxxxxxxxxxx....x.x.x.xxx..xxx...x..x.",
"x................x.x.x......xx....x..x.",
"x................x.x.x......x.x...x..x.",
"x................x.x.x......x..x..x..x.",
"x................x.x.x...........x...x.",
"x................x.x.xxxxxxxxxxxx....x.",
"x................x.x.................x.",
"x................x.xxxxxxxxxxxxxxxxxxx.",
"x................x.....................",
"x................xxxxxxxxxxxxxxxxxxxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getMinimumTours(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MinimumTours ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
