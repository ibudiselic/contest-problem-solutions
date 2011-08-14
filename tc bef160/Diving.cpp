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

class Diving {
    public:
    string needed(string difficulty, string need, string ratings) {
        float diff;
        float nd;
        float sol = 0.0;
        const float step = 0.5;
        {
        	istringstream is(difficulty);
        	is >> diff;
        }
        {
        	istringstream is(need);
        	is >> nd;
        }
        vector<float> rts;
        {
        	istringstream is(ratings);
        	char ch;
        	while (is >> ch)
        		if (isdigit(ch)) {
        			is.putback(ch);
        			float tmp;
        			is >> tmp;
        			rts.push_back(tmp);
        		}
        }
        while (sol <= 10.0) {
        	vector<float> tmp = rts;
        	tmp.push_back(sol);
        	sort(tmp.begin(), tmp.end());
        	float sum = 0.0;
        	for (int i=1; i<4; ++i)
        		sum += tmp[i];
        	if (sum*diff >= nd)
        		break;
        	sol += step;
        }
        char buff[5];
        if (sol < 10.1)
        	sprintf(buff, "%.1f", sol);
        else sprintf(buff, "%.1f", -1.0);
        
        return buff;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3.2"; string Arg1 = "50.32"; string Arg2 = "5.5 7.5 10.0 ?.? 4.5"; string Arg3 = "0.0"; verify_case(0, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "3.2"; string Arg1 = "50.32"; string Arg2 = "5.5 5.5 10.0 ?.? 4.5"; string Arg3 = "5.0"; verify_case(1, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "4.0"; string Arg1 = "120.00"; string Arg2 = "9.5 10.0 ?.? 10.0 10.0"; string Arg3 = "10.0"; verify_case(2, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "4.0"; string Arg1 = "120.00"; string Arg2 = "9.5 10.0 ?.? 9.5 10.0"; string Arg3 = "-1.0"; verify_case(3, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "2.3"; string Arg1 = ".01"; string Arg2 = "0.0 0.0 ?.? 0.0 0.5"; string Arg3 = "0.5"; verify_case(4, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "3.3"; string Arg1 = "47.85"; string Arg2 = "0.5 5.5 3.5 7.0 ?.?"; string Arg3 = "5.5"; verify_case(5, Arg3, needed(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Diving ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
