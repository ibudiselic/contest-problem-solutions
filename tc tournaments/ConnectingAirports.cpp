#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int cap[150][150];
int source = 100;
int sink = 101;
int offset = 50;
bool v[150];

bool dfs(int x) {
    v[x] = true;
    if (x == sink) {
        return true;
    }
    for (int y=0; y<=sink; ++y) {
        if (!v[y] && cap[x][y]>0 && dfs(y)) {
            --cap[x][y];
            ++cap[y][x];
            return true;
        }
    }
    return false;
}
bool augment() {
    memset(v, 0, sizeof v);
    return dfs(source);
}
class ConnectingAirports {
	public:
	vector <string> getSchedule(vector <int> A, vector <int> B) {
        int m = A.size();
        int n = B.size();

        memset(cap, 0, sizeof cap);
        for (int i=0; i<m; ++i) {
            cap[source][i] = A[i];
            for (int j=0; j<n; ++j) {
                cap[i][offset+j] = 1;
            }
        }
        for (int i=0; i<n; ++i) {
            cap[offset+i][sink] = B[i];
        }
        int a = 0, b = 0;
        for (int i=0; i<m; ++i) {
            a += A[i];
        }
        for (int i=0; i<n; ++i) {
            b += B[i];
        }

        if (a != b) {
            return vector<string>();
        }

        int flow = 0;
        while (augment()) {
            ++flow;
        }
        

        if (flow != a) {
            return vector<string>();
        }

        vector<string> sol(m, string(n, '0'));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (cap[i][offset+j] == 0) {
                    ++cap[source][i];
                    ++cap[offset+j][sink];
                    if (!augment()) {
                        --cap[source][i];
                        --cap[offset+j][sink];
                        sol[i][j] = '1';
                    }
                }
                cap[i][offset+j] = cap[offset+j][i] = 0;
            }
            
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"100", "101", "111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0111", "0101", "0100", "1000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {47,47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47,40,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,2,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"001001111", "111110000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"000000", "000000", "000000", "000000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, getSchedule(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConnectingAirports ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
