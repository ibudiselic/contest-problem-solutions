#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cost(vector<int> &cur, int x) {
    int a = 0;
    while (cur[a] != x) {
        ++a;
    }

    int b = (int)cur.size() - 1;
    while (cur[b] != x) {
        --b;
    }

    if (a <= b) {
        while (cur[0] != x) {
            cur.push_back(cur[0]);
            cur.erase(cur.begin());
        }
        cur.erase(cur.begin());
    } else {
        while (cur[0] != x) {
            cur.insert(cur.begin(), cur.back());
            cur.pop_back();
        }
        cur.erase(cur.begin());
    }

    return min(a, (int)cur.size()-b+1);
}
        
class BidirectionalQueue {
	public:
	int extractElements(int N, vector <int> indices) {
	    vector<int> cur(N);
        for (int i=0; i<N; ++i) {
            cur[i] = i + 1;
        }

        int sol = 0;
        for (int i=0; i<(int)indices.size(); ++i) {
            sol += cost(cur, indices[i]);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {2, 9, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(1, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 32; int Arr1[] = {27, 16, 30, 11, 6, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(2, Arg2, extractElements(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {1, 6, 3, 2, 7, 9, 8, 4, 10, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(3, Arg2, extractElements(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BidirectionalQueue ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
