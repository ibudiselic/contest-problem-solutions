#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

bool used[50];
bool is_palin(const string &s) {
    for (int i=0; 2*i<(int)s.size(); ++i) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}
int get_max(const vector< pair< pair<string, int>, int> > &F, const vector< pair< pair<string, int>, int> > &R, const vector<int> &val) {
    int n = F.size();
    int i=0, j=0;
    int ret = 0;
    while (i<n && j<n) {
        if (F[i].first.first == R[j].first.first) {
            if (F[i].second==R[j].second || used[F[i].second]) {
                ++i;
            } else if (used[R[j].second]) {
                ++j;
            } else {
                ret -= F[i].first.second + R[j].first.second; 
                used[F[i].second] = used[R[j].second] = 1;
                ++i;
                ++j;
            }
        } else if (F[i].first.first < R[j].first.first) {
            ++i;
        } else {
            ++j;
        }
    }
    return ret;
}
class PalindromeGame {
	public:
	int getMaximum(vector <string> front, vector <int> back) {
        vector< pair< pair<string, int>, int> > F;
        for (int i=0; i<(int)front.size(); ++i) {
            F.push_back(make_pair(make_pair(front[i], -back[i]), i));
        }
        sort(F.begin(), F.end());
        vector< pair< pair<string, int>, int> > R = F;
        for (int i=0; i<(int)R.size(); ++i) {
            reverse(R[i].first.first.begin(), R[i].first.first.end());
        }
        sort(R.begin(), R.end());
        
        memset(used, 0, sizeof used);
        int sol = get_max(F, R, back);
        for (int i=0; i<(int)front.size(); ++i) {
            if (is_palin(front[i])) {
                memset(used, 0, sizeof used);
                used[i] = 1;
                sol = max(sol, get_max(F, R, back) + back[i]);
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
	void test_case_0() { string Arr0[] = { "topcoder", "redcoder", "redocpot" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 5, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "rabbit" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "abc", "abc", "def", "cba", "fed" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24, 7, 63, 222, 190 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromeGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
