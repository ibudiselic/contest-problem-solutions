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

#define INFTY 2000000000

inline
int min(int a, int b)
{
	return a<b ? a:b;
}
bool fav[15][30];
map<vector<int>, int> memo;

class OrderFood {
    public:
    int selectEntrees(vector <int> entrees, vector <string> favorites)
    {
    	memo.clear();
    	int n = (int)entrees.size();
    	int m = (int)favorites.size();
    	
    	for (int i=0; i<m; ++i) {
   			for (int j=0; j<n; ++j)
   				fav[i][j] = false;
   			istringstream is(favorites[i]);
   			for (int j; is >> j; fav[i][j] = true);
   		}
   		n /= 2;
   		
    	for (int mask=0; mask < (1<<n); ++mask) {
    		vector<int> got(m);
    		int cost = 0;
    		for (int i=0; i<n; ++i)
    			if (mask & (1<<i)) {
    				cost += entrees[i];
    				for (int j=0; j<m; ++j) {
    					got[j] += fav[j][i];
    					if (got[j] > 2)
    						goto FAIL;
    				}
    			}
    		if (!memo.count(got)) memo[got] = cost;
    		else memo[got] = min(memo[got], cost);
FAIL: 		;
    	}
    	int n2 = (int)entrees.size()-n;	
    	
    	int sol = INFTY;
    	for (int mask=0; mask < (1<<n2); ++mask) {
    		vector<int> got(m, 2);
    		int cost = 0;
    		for (int i=0; i<n2; ++i)
    			if (mask & (1<<i)) {
    				cost += entrees[i+n];
    				for (int j=0; j<m; ++j) {
    					got[j] -= fav[j][i+n];
    					if (got[j] > 2)
    						goto FAIL2;
    				}
    			}
    		if (!memo.count(got)) continue;
    		else sol = min(sol, cost+memo[got]);
FAIL2:		;
		}
		if (sol == INFTY) return -1;
		else return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 150, 300, 425, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 3", "0 2 3 4", "0 3 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450; verify_case(0, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1", "1 2", "0 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 40, 80, 160, 320, 640}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 2 5", "0 2 6", "0 3 5", "1 3 6", "1 4", "1 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 310; verify_case(2, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 200, 300, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000, 90, 80, 70, 60, 50, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 2", "0 00 000 3 4", "0 5 6", "0 1 4", "0 2 5", "0 3 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 390; verify_case(4, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {  10124, 540045, 236111, 977928, 199927,
  379085, 743650, 631339, 961617, 178242,
  343492, 89869,   61858, 700029, 560602,
  341127, 850320, 957934, 167013, 631513}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4 16 16 2 18 10 13 14 4 18",
 "12 4 19 1 1 12 18 7 18",
 "6 15 19 13",
 "5 10 5 16 15 14 15 8",
 "13 2 15 8 5",
 "8 2 15 3 1",
 "9 18 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1792343; verify_case(5, Arg2, selectEntrees(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    OrderFood ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
