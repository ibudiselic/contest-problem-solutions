#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int bc(long long x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}

class BirthdayCake {
	public:
	int howManyFriends(vector <string> F, vector <string> D, int K) {
		vector<long long> mask(D.size(), 0);
        int n = D.size();
        map<string, int> fi;
        for (int i=0; i<(int)F.size(); ++i) {
            fi[F[i]] = i;
        }
        
        for (int i=0; i<n; ++i) {
            istringstream is(D[i]);
            string s;
            while (is >> s) {
                if (fi.count(s)) {
                    mask[i] |= (1LL<<fi[s]);
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<(1<<n); ++i) {
            long long m = 0;
            int b = bc(i);
            if (b <= sol) {
                continue;
            }
            for (int j=0; j<n; ++j) {
                if (i & (1<<j)) {
                    m |= mask[j];
                }
            }
            if ((int)F.size() - bc(m) >= K) {
                sol = max(sol, b);
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
	void test_case_0() { string Arr0[] = { "apple", "orange", "strawberry", "cherry" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "apple orange", "apple cherry", "strawberry orange", "cherry", "apple" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = { "strawberry", "orange", "apple", "lemon", "watermelon" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "orange", "apple", "lemon", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4; verify_case(1, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = { "apple", "orange" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(2, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BirthdayCake ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
