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

class TextCompressor {
	public:
	bool in_string(const string &a, const string &b)
	{
		int n = b.size()-a.size() + 1;
		for (int i=0; i<n; ++i)
			if (a==b.substr(i, a.size())) return true;
		return false;
	}	
	string longestRepeat(string source) {
		int start = 0;
		int len = 0;
		
		for (int i=0; i<(int)source.size()-2*(len+1)+1; ++i)
			for (int j=len+1; 2*j+i-1<(int)source.size(); ++j)
				if (in_string(source.substr(i, j), source.substr(i+j))) {
					len = j; start = i;
				}
		return source.substr(start, len);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDABCFG"; string Arg1 = "ABC"; verify_case(0, Arg1, longestRepeat(Arg0)); }
	void test_case_1() { string Arg0 = "ABABA"; string Arg1 = "AB"; verify_case(1, Arg1, longestRepeat(Arg0)); }
	void test_case_2() { string Arg0 = "This is a test."; string Arg1 = "is "; verify_case(2, Arg1, longestRepeat(Arg0)); }
	void test_case_3() { string Arg0 = "Testing testing 1 2 3."; string Arg1 = "esting "; verify_case(3, Arg1, longestRepeat(Arg0)); }
	void test_case_4() { string Arg0 = "The quick brown fox jumps over the lazy dog."; string Arg1 = "he "; verify_case(4, Arg1, longestRepeat(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TextCompressor ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
