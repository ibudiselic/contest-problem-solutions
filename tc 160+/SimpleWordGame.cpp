#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SimpleWordGame {
	public:
	int points(vector <string> player, vector <string> dictionary) {
		sort(player.begin(), player.end());
        player.resize(unique(player.begin(), player.end()) - player.begin());
        
        int sol = 0;
        for (int i=0; i<(int)player.size(); ++i) {
            if (find(dictionary.begin(), dictionary.end(), player[i]) != dictionary.end()) {
                sol += player[i].size()*player[i].size();
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "apple", "orange", "strawberry" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 136; verify_case(0, Arg2, points(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "apple" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, points(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "orange", "orange" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry", "orange", "grapefruit", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(2, Arg2, points(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "lidi", "o", "lidi", "gnbewjzb", "kten",
  "ebnelff", "gptsvqx", "rkauxq", "rkauxq", "kfkcdn"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "nava", "wk", "kfkcdn", "lidi", "gptsvqx",
  "ebnelff", "hgsppdezet", "ulf", "rkauxq", "wcicx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 186; verify_case(3, Arg2, points(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SimpleWordGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
