#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

bool check(const vector<int> &a, const vector<int> &b) {
    for (int i=0; i<(int)a.size(); ++i) {
        if (b[a[i]] != i%3) {
            return false;
        }
    }
    return true;
}
class CardsCheating {
	public:
	int numberOfShuffles(vector <int> cards, vector <int> shuffle) {
		vector<int> v;
        int n = cards.size();
        v.reserve(n);
        for (int i=0; i<n; ++i) {
            v.push_back(i);
        }

        int sol = 0;
        set< vector<int> > S;
        while (!check(v, cards)) {
            if (S.find(v) != S.end()) {
                return -1;
            }
            S.insert(v);
            vector<int> vv(n, 0);
            for (int i=0; i<n; ++i) {
                vv[shuffle[i]] = v[i];
            }
            v.swap(vv);
            ++sol;
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,0,3,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,2,0,2,0,1,0,2,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,0,9,7,1,8,3,10,4,11,6,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(2, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, numberOfShuffles(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CardsCheating ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
