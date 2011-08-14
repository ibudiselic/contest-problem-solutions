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

class EqualSubstrings {
	public:
	int chr_count(string &a, char c)
	{
		int res = 0;
		for (int i=0; i<(int)a.length(); ++i)
			res += a[i]==c;
		return res;
	}
	vector <string> getSubstrings(string str) {
		int x, y;
		int t = chr_count(str, 'a');
		int v = 0;
		
		x = str.length();
		y = 0;
		while (t != v) {
			if (str[x-1]=='a') --t;
			--x;
			if (str[str.length()-y-1]=='b') ++v;
			++y;
		}
		vector<string> sol;
		
		sol.push_back(str.substr(0, x));
		sol.push_back(str.substr(str.length()-y));
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aaabbb"; string Arr1[] = { "aaa",  "bbb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "bbbaaa"; string Arr1[] = { "bbb",  "aaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "bbbbbb"; string Arr1[] = { "bbbbbb",  "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "aaaaaa"; string Arr1[] = { "",  "aaaaaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "abjlkbjalkbjaljsbljbalb"; string Arr1[] = { "abjlkbjalkbjaljs",  "bljbalb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSubstrings(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EqualSubstrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
