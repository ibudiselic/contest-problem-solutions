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

typedef struct {
	int x[1000];
	
	int& operator[](int i) { return x[i+3]; }
} dreq;

int sol;
dreq a;
int fab[4];

void rekurzija(int n)
{
	int sz = (n+1)/2;
	
	for (int i=0; i<4; ++i)
		if (fab[i] >= sz) {
			if (a[n-1]==i || a[n-3]==i || a[n-4]==i) continue;
			if (n==3 && a[n-2]==i) continue;
			fab[i] -= sz;
			a[n] = i;
			sol >?= n;
			rekurzija(n+1);
			a[n] = 0;
			fab[i] += sz;
		}
}

			
class LogCabin {
    public:
    int maxStrips(vector <int> fabrics) {
		
		sol = 0;
		a[-3] = a[-2] = a[-1] = a[0] = -1;
		for (int i=0; i<4; ++i)
			fab[i] = fabrics[i];
		rekurzija(1);
		
		return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxStrips(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maxStrips(Arg0)); }
	void test_case_2() { int Arr0[] = { 100, 100, 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(2, Arg1, maxStrips(Arg0)); }
	void test_case_3() { int Arr0[] = { 10, 36, 20, 38 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, maxStrips(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LogCabin ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
