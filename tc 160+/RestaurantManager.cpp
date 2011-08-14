#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class RestaurantManager {
	public:
	int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures) {
		sort(tables.begin(), tables.end());
        int used[50];
        memset(used, 0xff, sizeof used);
        int assigned[50];
        memset(assigned, 0xff, sizeof assigned);

        vector< pair<int, int> > v;
        for (int i=0; i<(int)departures.size(); ++i) {
            v.push_back(make_pair(departures[i], i));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int sol = 0;
        for (int i=0; i<(int)arrivals.size(); ++i) {
            while (v.size()>0 && v.back().first<=arrivals[i]) {
                int j = v.back().second;
                v.pop_back();
                used[assigned[j]] = -1;
                assigned[j] = -1;
            }
            int j = lower_bound(tables.begin(), tables.end(), groupSizes[i]) - tables.begin();
            while (j<(int)tables.size() && used[j]!=-1) {
                ++j;
            }
            if (j == (int)tables.size()) {
                sol += groupSizes[i];
                continue;
            }
            used[j] = i;
            assigned[i] = j;
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 14; verify_case(0, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 8; verify_case(1, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,8,11,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14,1,15,1,19,15,9,15,20,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,7,18,21,25,29,31,46,49}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,37,11,36,36,46,40,42,47,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 69; verify_case(3, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {18,15,2,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,9,16,3,10,3,2,10,16,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,15,19,20,21,22,27,35,37,43}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13,24,22,32,32,32,35,48,41,44}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(4, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {13,9,6,1,9,8,6,2,8,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,10,11,10,1,5,16,2,9,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,14,64,78,100,121,151,155,162,164}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {19,26,159,96,155,134,169,199,169,174}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 17; verify_case(5, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RestaurantManager ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
