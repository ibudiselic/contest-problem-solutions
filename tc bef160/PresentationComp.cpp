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

typedef pair<int, int> Pii;
class PresentationComp {
	public:
	Pii reduce(const string &s)
	{
		int x = 0;
		int y = 0;
		int p = 1;
		
		for (int i=0; i<(int)s.size(); ++i)
			if (s[i]=='y')
				y = (y+p)%6;
			else {
				x = (x+1)%8;
				p = (p*5)%6;
			}
		return make_pair(x, y);
	}
	string simplify(string expression) {
		Pii c = reduce(expression);
		for (int i=0; i<12; ++i)
			for (int j=0; j<(1<<i); ++j) {
				string s;
				for (int k=0; k<i; ++k)
					if (j&(1<<k)) s = 'y'+s;
					else s = 'x'+s;
				if (reduce(s)==c)
					return s;
			}
		return "error";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "xxxxxxxxyyyyyy"; string Arg1 = ""; verify_case(0, Arg1, simplify(Arg0)); }
	void test_case_1() { string Arg0 = "xy"; string Arg1 = "xy"; verify_case(1, Arg1, simplify(Arg0)); }
	void test_case_2() { string Arg0 = "yyxx"; string Arg1 = "xxyy"; verify_case(2, Arg1, simplify(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PresentationComp ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
