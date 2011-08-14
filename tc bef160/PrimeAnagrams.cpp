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

int n;
class PrimeAnagrams {
	public:
	int broj(vector<int> &v) {
		int res = 0;
		for (int i=0; i<(int)v.size(); ++i)
			res = res*10 + v[i];
		return res;
	}
	vector <int> primes(string s) {
		vector<int> sol;
		long long minprod = 100000000000LL;
		vector<bool> prime(1000000, true);
		prime[1] = false;
		prime[0] = false;
		for (int i=2; i<500000; ++i)
			for (int j=2; i*j<1000000; ++j)
				prime[i*j] = false;
				
		n = s.length();
		sort(s.begin(), s.end());
		do {
			if (s[0]-'0')
			for (int x=1; x<n-1; ++x)
				if (s[x]-'0')
				for (int y=1; x+y<n; ++y)
					if (s[x+y]-'0') {
						int z = n-x-y;
						int t1, t2, t3;
						for (int i=t1=0; i<x; ++i)
							t1 = t1*10+s[i    ]-'0';
						for (int i=t2=0; i<y; ++i)
							t2 = t2*10+s[x+i  ]-'0';
						for (int i=t3=0; i<z; ++i)
							t3 = t3*10+s[x+y+i]-'0';
						if (prime[t1]&&prime[t2]&&prime[t3] && (long long)t1*t2*t3 < minprod) {
							minprod = (long long)t1*t2*t3;
							sol.clear();
							sol.push_back(t1); sol.push_back(t2); sol.push_back(t3);
						}
					}
		} while (next_permutation(s.begin(), s.end()));
		sort(sol.begin(), sol.end());
		
		return sol;
	}
									







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "39151"; int Arr1[] = { 5,  13,  19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, primes(Arg0)); }
	void test_case_1() { string Arg0 = "921179"; int Arr1[] = { 2,  17,  199 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, primes(Arg0)); }
	void test_case_2() { string Arg0 = "01123"; int Arr1[] = { 2,  3,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, primes(Arg0)); }
	void test_case_3() { string Arg0 = "0707070"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, primes(Arg0)); }
	void test_case_4() { string Arg0 = "222"; int Arr1[] = { 2,  2,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, primes(Arg0)); }
	void test_case_5() { string Arg0 = "123"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, primes(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrimeAnagrams ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
