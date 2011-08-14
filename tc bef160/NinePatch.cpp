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

class NinePatch {
    public:
    int numBlocks(vector <int> length, vector <int> width) {
        int count = 0;
        
        for (int i=0; i<(int)length.size(); ++i) {
        	int a = length[i]/2;
        	int b = width[i]/2;
        	
        	count += a*b;
        }
        return count/9;   	
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 13 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, numBlocks(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 1, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, numBlocks(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 7, 13, 192 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6, 22, 31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 168; verify_case(2, Arg2, numBlocks(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 606, 517, 358, 813, 522, 766, 795, 661, 572, 465,
  729, 290, 905,  61, 187, 147, 449, 531,  44, 969,
  337, 539, 232, 936, 117, 579, 115, 402, 486, 510,
  952, 400, 691, 287, 919, 323, 581, 943, 730, 652,
   48, 847, 490, 386,  21,  86,  70, 869, 415, 334 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {  36,  2, 35, 37,  1, 28, 11,  9,  5, 22,
    7, 12, 34,  6, 26, 29,  5, 24, 13, 36,
   21, 26, 37,  7,  9, 27, 35, 13,  9, 14,
    3,  1,  8, 18,  6,  7, 20, 26,  8, 32,
   10, 32, 20,  9, 10,  6, 19, 18, 24,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12008; verify_case(3, Arg2, numBlocks(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NinePatch ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
