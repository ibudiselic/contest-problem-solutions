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

class LeapAge {
    public:
    inline
    bool is_leap(int x)
    {
    	return (x%4) ? false : (x%100) ? true : !(x%400);
    }
    int getAge(int year, int born) {
     	int sol = 0;
     	while (++born <= year)
     		sol += is_leap(born);
     	return sol;   
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2004; int Arg1 = 1980; int Arg2 = 6; verify_case(0, Arg2, getAge(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 1582; int Arg2 = 2042; verify_case(1, Arg2, getAge(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2007; int Arg1 = 1981; int Arg2 = 6; verify_case(2, Arg2, getAge(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1981; int Arg1 = 1980; int Arg2 = 0; verify_case(3, Arg2, getAge(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1984; int Arg1 = 1983; int Arg2 = 1; verify_case(4, Arg2, getAge(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 9700; int Arg1 = 5795; int Arg2 = 947; verify_case(5, Arg2, getAge(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LeapAge ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
