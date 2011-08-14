#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

map< pair<int, vector<int> > , int > M;
int go(vector<int> &v, int n) {
    if (n == 0) {
        return v[0]-v.back();
    }
    if (v[0] == v.back()) {
        return 0;
    }
    if (M.count(make_pair(n, v))) {
        return M[make_pair(n, v)];
    }

    int &ret = M[make_pair(n, v)];
    ret = v[0] - v.back();
    if (n >= v.back()) {
        int t = v.back();
        v.pop_back();
        ret = min(ret, go(v, n-t));
        v.push_back(t);
    }

    if (v[0] == v[1]) {
        int i = 2;
        while (v[i] == v[0]) {
            ++i;
        }
        --v[i-1];
        assert(v[i-1] > 0);
        ret = min(ret, go(v, n-1));
        ++v[i-1];
    } else {
        int dec = min(n, v[0]-v[1]);
        v[0] -= dec;
        ret = min(ret, go(v, n-dec));
        v[0] += dec;
    }

    return ret;
}
    
class RoughStrings {
	public:
	int minRoughness(string s, int n) {
		M.clear();
        vector<int> c(26, 0);
        for (int i=0; i<(int)s.size(); ++i) {
            ++c[s[i]-'a'];
        }

        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        while (c.back() == 0) {
            c.pop_back();
        }

        return go(c, n);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaaabbc"; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, minRoughness(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aaaabbbbc"; int Arg1 = 5; int Arg2 = 0; verify_case(1, Arg2, minRoughness(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "veryeviltestcase"; int Arg1 = 1; int Arg2 = 2; verify_case(2, Arg2, minRoughness(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "gggggggooooooodddddddllllllluuuuuuuccckkk"; int Arg1 = 5; int Arg2 = 3; verify_case(3, Arg2, minRoughness(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"; int Arg1 = 17; int Arg2 = 0; verify_case(4, Arg2, minRoughness(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "bbbccca"; int Arg1 = 2; int Arg2 = 0; verify_case(5, Arg2, minRoughness(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoughStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
