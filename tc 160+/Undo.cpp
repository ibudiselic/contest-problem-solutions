#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Undo {
	public:
	string getText(vector <string> commands, vector <int> time) {
		string s;

        vector<string> bef(commands.size(), string());
        for (int i=0; i<(int)commands.size(); ++i) {
            bef[i] = s;
            if (commands[i][0] == 't') {
                s += commands[i][(int)commands[i].size()-1];
            } else {
                istringstream is(commands[i]);
                string t;
                int x;
                is >> t >> x;
                int j = i - 1;
                while (j>=0 && time[j]>=time[i]-x) {
                    --j;
                }
                s = bef[j+1];
            }
        }

        return s;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"type a", "type b", "type c", "undo 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(0, Arg2, getText(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"type a", "type b", "undo 2", "undo 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(1, Arg2, getText(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"type a", "undo 1", "undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(2, Arg2, getText(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"type a", "type b", "type c", "undo 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abc"; verify_case(3, Arg2, getText(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Undo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
