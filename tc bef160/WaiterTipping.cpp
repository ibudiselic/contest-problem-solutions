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

class WaiterTipping {
    public:
    int maxPercent(int total, int taxPercent, int money) {
       	int tip = 100*(money-total-total*taxPercent/100)/total;
       	
       	if (total + total*taxPercent/100 + (tip+1)*total/100 <= money) return tip+1;
       	return (tip < 0) ? -1 : tip;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 500; int Arg1 = 10; int Arg2 = 600; int Arg3 = 10; verify_case(0, Arg3, maxPercent(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 500; int Arg1 = 10; int Arg2 = 604; int Arg3 = 10; verify_case(1, Arg3, maxPercent(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 850; int Arg1 = 8; int Arg2 = 870; int Arg3 = -1; verify_case(2, Arg3, maxPercent(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 226; int Arg1 = 48; int Arg2 = 584; int Arg3 = 111; verify_case(3, Arg3, maxPercent(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123; int Arg1 = 52; int Arg2 = 696; int Arg3 = 415; verify_case(4, Arg3, maxPercent(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 500; int Arg1 = 10; int Arg2 = 550; int Arg3 = 0; verify_case(5, Arg3, maxPercent(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WaiterTipping ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
