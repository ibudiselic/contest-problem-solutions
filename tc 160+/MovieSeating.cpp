#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long C(int n, int k) {
    long long ret = 1;
    for (int i=0; i<k; ++i) {
        ret *= (n-k+1+i);
        ret /= (i+1);
    }
    return ret;
}
class MovieSeating {
	public:
	long long getSeatings(int numFriends, vector <string> hall) {
		long long sol = 0;
        int m = hall.size();
        int n = hall[0].size();
        if (numFriends == 1) {
            int sol = 0;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    sol += (hall[i][j]=='.');
                }
            }
            return sol;
        }
        for (int i=0; i<m; ++i) {
            int cnt = count(hall[i].begin(), hall[i].end(), '.');
            if (cnt < numFriends) {
                continue;
            }
            sol += C(cnt, numFriends);
        }
        for (int j=0; j<n; ++j) {
            int cnt = 0;
            for (int i=0; i<m; ++i) {
                cnt += (hall[i][j]=='.');
            }
            if (cnt < numFriends) {
                continue;
            }
            sol += C(cnt, numFriends);
        }
        while (numFriends > 0) {
            sol *= numFriends;
            --numFriends;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = { ".#..",
  ".##.",
  "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 34LL; verify_case(0, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "..#",
  ".##",
  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(1, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = { "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 40320LL; verify_case(3, Arg2, getSeatings(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MovieSeating ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
