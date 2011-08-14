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

class CultureShock {
    public:
    string translate(string text) {
        
        vector<string> tmp = tokenize<string>(text);
        for (vector<string>::iterator i=tmp.begin(); i!=tmp.end(); ++i)
        	if (*i == "ZEE")
        		*i = "ZED";
        string ret;
        for (vector<string>::const_iterator i=tmp.begin(); i!=tmp.end(); ++i)
        	ret += *i + ' ';
        return ret.erase(ret.size()-1);
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZEE"; string Arg1 = "THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZED"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "ZEE"; string Arg1 = "ZED"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "SPELLING IN ENGLISH IS EZEE"; string Arg1 = "SPELLING IN ENGLISH IS EZEE"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "ZEE ZEE ZED ZEDS ZEE ZEES"; string Arg1 = "ZED ZED ZED ZEDS ZED ZEES"; verify_case(3, Arg1, translate(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CultureShock ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
