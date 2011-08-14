#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int C[50];
vector<int> to_parent(const vector<int> &v) {
    vector<int> ret(v.size(), 0);
    for (int i=1; i<(int)v.size(); ++i) {
        ret[v[i-1]] = v[i];
    }
    
    return ret;
}
class PerfectPermutationHard {
	public:
	vector <int> reorder(vector <int> P) {
		memset(C, 0xff, sizeof C);
        int cyc = 0;
        vector< deque<int> > cycs;
        for (int i=0; i<(int)P.size(); ++i) {
            if (C[i] == -1) {
                int t = i;
                cycs.push_back(deque<int>());
                do {
                    if (t != 0) {
                        cycs.back().push_back(t);
                    }
                    C[t] = cyc;
                    t = P[t];
                } while (C[t] == -1);
                ++cyc;
            }
        }
        if (cyc == 1) {
            return P;
        }
        
        vector<int> child;
        child.reserve(P.size());
        child.push_back(0);
        
        while (cycs[0].size()>0 && cycs[0][0]<cycs[1][0]) {
            child.push_back(cycs[0][0]);
            cycs[0].pop_front();
        }
        for (int i=1; i<cyc; ++i) {
            for (int j=0; j<(int)cycs[i].size(); ++j) {
                child.push_back(cycs[i][j]);
            }
        }
        for (int i=0; i<(int)cycs[0].size(); ++i) {
            child.push_back(cycs[0][i]);
        }
        
        return to_parent(child);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reorder(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 0, 5, 2, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 5, 4, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reorder(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 7, 3, 0, 6, 4, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 3, 0, 6, 2, 5, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reorder(Arg0)); }
	void test_case_3() { int Arr0[] = {11, 8, 10, 1, 5, 4, 0, 7, 3, 9, 12, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 8, 10, 2, 5, 7, 0, 9, 3, 11, 12, 6, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reorder(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 4, 2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 5, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, reorder(Arg0)); }
	void test_case_5() { int Arr0[] = {0, 2, 6, 5, 7, 3, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 6, 5, 7, 4, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, reorder(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PerfectPermutationHard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
