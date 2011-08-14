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

class Mailbox {
    public:
    int impossible(string collection, vector <string> address) {
        int sol = 0;
        bool used[50];
        
        for (int i=0; i<(int)address.size(); ++i) {
        	memset(used, false, sizeof used);
        	for (int j=0; j<(int)address[i].size(); ++j) {
        		if (address[i][j] == ' ') continue;
        		for (int k=0; k<(int)collection.size(); ++k)
        			if (!used[k] && address[i][j] == collection[k]) {
        				used[k] = true;
        				goto success;
        			}
        		++sol;
        		break;
        		success: ;
        	}
        }
        return sol;
        			
        
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAABBCCCCCDDDEEE123456789"; string Arr1[] = {"123C","123A","123 ADA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, impossible(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPRSTUVWXYZ1234567890"; string Arr1[] = {"2 FIRST ST"," 31 QUINCE ST", "606 BAKER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, impossible(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABCDAAST"; string Arr1[] = {"111 A ST", "A BAD ST", "B BAD ST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, impossible(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Mailbox ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
