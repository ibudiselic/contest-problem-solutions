#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


vector<string> do_draw(vector<string> &sol, int xCount) {
    while (xCount > 0) {
        sol.push_back(sol.back() + "XX");
        xCount -= (int)sol.back().size();
    }
    if (xCount < 0) {
        return vector<string>();
    }
    
    int t = 1;
    for (int i=(int)sol.size()-2; i>=0; --i) {
        sol[i] = string(t, '.') + sol[i] + string(t, '.');
        ++t;
    }
    return sol;
}
class Xosceles {
	public:
	vector <string> draw(int xCount) {
	    vector<string> sol;
        sol.push_back("X");
        --xCount;
        
        sol = do_draw(sol, xCount);
        if (sol.size()) {
            return sol;
        } else {
            sol.push_back("XX");
            --xCount;
            return do_draw(sol, xCount);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = {".X.", "XXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = {".XX.", "XXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { int Arg0 = 16; string Arr1[] = {"...X...", "..XXX..", ".XXXXX.", "XXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }
	void test_case_3() { int Arg0 = 18; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, draw(Arg0)); }
	void test_case_4() { int Arg0 = 100; string Arr1[] = {".........X.........", "........XXX........", ".......XXXXX.......", "......XXXXXXX......", ".....XXXXXXXXX.....", "....XXXXXXXXXXX....", "...XXXXXXXXXXXXX...", "..XXXXXXXXXXXXXXX..", ".XXXXXXXXXXXXXXXXX.", "XXXXXXXXXXXXXXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, draw(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Xosceles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
