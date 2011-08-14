#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long i64;

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

class FileFilter {
    public:
    vector <string> filter(vector <string> files, vector <string> extensions) {
        VS sol;
        
        for (int i=0; i<(int)files.size(); ++i) {
        	bool allow = false;
        	VS tmp = tokenize<string>(files[i], ".");
        	for (int j=0; j<(int)extensions.size(); ++j) {
        		int k, l;
        		for (k=0, l=0; k<(int)tmp[tmp.size()-1].length() && l<(int)extensions[j].length(); ++k, ++l)
        			if (tolower(extensions[j][l]) != tolower(tmp[tmp.size()-1][k]))
        				break;
        		if (k==(int)tmp[tmp.size()-1].length() && l==(int)extensions[j].length()) {
        			allow = true;
        			break;
        		}
        	}
        	if (allow)
        		sol.push_back("ALLOW");
        	else sol.push_back("DENY");
        }
        return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"algorithm.txt","algorithms.html","wingl.exe","yourDoc.PIF","graph.gIf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"txt","html","gif","doc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "ALLOW",  "ALLOW",  "DENY",  "DENY",  "ALLOW" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, filter(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"exe","pif"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, filter(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".bashrc","bash.rc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"rc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "DENY",  "ALLOW" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, filter(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FileFilter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
