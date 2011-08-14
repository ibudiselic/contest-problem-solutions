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

map<pair<int, int>, int> memo;
bool fav[15][15];
int n;

#undef min
int min(int a, int b)
{
	return a<b ? a:b;
}
class TurntableService {
    public:
    int rek(int served, int pos1)
    {
    	if (served == (1<<n)-1) return 0;
    	pair<int, int> state(served, pos1);
    	if (memo.count(state)) return memo[state];
    	
    	int res = 2000000000;
    	for (int pos2=0; pos2 < n; ++pos2) {
    		int cost = 0;
    		if (pos1 != pos2) cost = min((pos1-pos2+n)%n, (pos2-pos1+n)%n) + 1;
    		int temp = served;
    		for (int i=0; i<n; ++i)
    			if (fav[i][(pos2+i)%n]) temp |= (1<<i);
    		if (temp == served) continue;
    		res = min(res, cost + 15 + rek(temp, pos2));
    	}
    	return memo[state] = res;
    }
    int calculateTime(vector <string> favorites) {
    	n = (int)favorites.size();
    	memo.clear();
    	
        for (int i=0; i<n; ++i) {
        	for (int j=0; j<n; ++j)
        		fav[i][j] = false;
        	istringstream is(favorites[i]);
        	for (int j; is >> j; )
        		fav[i][j] = true;
        }
        return rek(0, 0);
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 2", "1", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, calculateTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"0", "0", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(1, Arg1, calculateTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"4", "1", "2", "3", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, calculateTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(3, Arg1, calculateTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TurntableService ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
