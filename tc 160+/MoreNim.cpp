#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long to_ll(const string &s) {
    istringstream is(s);
    long long x;
    is >> x;
    return x;
}

long long lastbit(long long x) {
    return (x ^ (x-1)) & x;
}

class MoreNim {
	public:
	long long bestSet(vector <string> heaps) {
		vector<long long> v;
        int n = heaps.size();
        for (int i=0; i<n; ++i) {
            v.push_back(to_ll(heaps[i]));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<long long> t = v;
        long long sol = 0;
        for (int i=0; i<n; ++i) {
            if (t[i] == 0) {
                sol += v[i];
                continue;
            }

            long long k = lastbit(t[i]);
            for (int j=i+1; j<n; ++j) {
                if (t[j] & k) {
                    t[j] ^= t[i];
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5","5","6","6","5","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 21LL; verify_case(0, Arg1, bestSet(Arg0)); }
	void test_case_1() { string Arr0[] = {"1","2","3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, bestSet(Arg0)); }
	void test_case_2() { string Arr0[] = {"1","2","3","4","5","6","7","8","9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(2, Arg1, bestSet(Arg0)); }
	void test_case_3() { string Arr0[] = {"1","2","4","8","16","32","64","128","256"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, bestSet(Arg0)); }
	void test_case_4() { string Arr0[] = {"12","13","16","121","13","14","52","23","1","29"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 27LL; verify_case(4, Arg1, bestSet(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MoreNim ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
