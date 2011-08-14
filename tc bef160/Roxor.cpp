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

int n;
map<int, bool> memo;
int move(int state, int i, int j, int k)
{
	return state ^ (1<<i) ^ (1<<j) ^ (1<<k);
}
bool is_set(int state, int i)
{
	return (state>>i) & 1;
}
bool win_state(int state)
{
	if (memo.count(state)) return memo[state];
	
	for (int i=0; i<n-1; ++i)
		if (is_set(state, i))
			for (int j=i+1; j<n; ++j)
				for (int k=j; k<n; ++k)
					if (!win_state(move(state, i, j, k)))
						return memo[state] = true;
	return memo[state] = false;
}
	
class Roxor {
    public:
    vector <int> play(vector <int> piles) {
      	n = (int)piles.size();
      	int state = 0;
      	memo.clear();
      	
      	for (int i=n-1; i>=0; --i)
      		state = state*2 + piles[i]%2;
      	for (int i=0; i<n-1; ++i)
      		if (piles[i])
      			for (int j=i+1; j<n; ++j)
      				for (int k=j; k<n; ++k)
      					if (!win_state(move(state, i, j, k))) {
      						vector<int> sol(3);
      						sol[0] = i; sol[1] = j; sol[2] = k;
      						return sol;
      					}
      	return vector<int>();
    }







// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 1, 0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  4,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, play(Arg0)); }
	void test_case_1() { int Arr0[] = {1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, play(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1, 1, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, play(Arg0)); }
	void test_case_3() { int Arr0[] = {14, 301, 391, 410, 511, 681, 58, 259, 981, 81, 5, 42, 251, 401, 120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  5,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, play(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Roxor ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
