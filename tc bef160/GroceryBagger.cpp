#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

class GroceryBagger {
	public:
	int minimumBags(int strength, vector <string> itemType) {
		map<string, int> memo;
		
		for (int i=0; i<(int)itemType.size(); ++i)
			if (!memo.count(itemType[i])) memo[itemType[i]] = 1;
			else ++memo[itemType[i]];
		int sol = 0;
		for (map<string, int>::const_iterator i=memo.begin(); i!=memo.end(); ++i) {
			sol += i->second / strength;
			sol += (i->second % strength)!=0;
		}
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; string Arr1[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, minimumBags(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GroceryBagger ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
