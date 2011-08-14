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

class DictionarySorter {
	public:
	bool lt(const string &a, const string &b)
	{
		int i = 0;
		int j = 0;
		for (; i<(int)a.size() && j<(int)b.size(); ++i, ++j)
			if (a[i]!=b[j]) {
				if (a[i]=='/')
					return a[i+1]<b[j];
				else if (b[j]=='/')
					return a[i]<=b[j+1];
				else return a[i]<b[j];
			} else {
				if (a[i]=='/') {
					if (a[i+1]!=b[j+1])
						return a[i+1]<b[j+1];
					i += 2;
					j += 2;
				}
			}
		if (i==(int)a.size()) return true;
		else return false;
	}
	vector <string> sort(vector <string> words) {
		for (int i=0; i<(int)words.size(); ++i)
			for (int j=i+1; j<(int)words.size(); ++j)
				if (!lt(words[i], words[j])) {
					string s = words[i]; words[i] = words[j]; words[j] = s;
				}
		return words;	
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a","b","/ae","t","u","/th"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "a",  "/ae",  "b",  "t",  "/th",  "u" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { string Arr0[] = {"aeleric","/aeleric","aelfred","alfred","/aelfred","/ae/th"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "aeleric",  "aelfred",  "alfred",  "/aeleric",  "/aelfred",  "/ae/th" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { string Arr0[] = {"/the","quick","brown","fox","jumps","over","/ae","lazy","dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "/ae",  "brown",  "dog",  "fox",  "jumps",  "lazy",  "over",  "quick",  "/the" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { string Arr0[] = {"/ae","/ae/ae","t","t/th"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "/ae",  "/ae/ae",  "t",  "t/th" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sort(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DictionarySorter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
