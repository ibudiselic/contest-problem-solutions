#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Filtering {
	public:
	vector <int> designFilter(vector <int> sizes, string outcome) {
		int n = sizes.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (sizes[i] > sizes[j]) {
                    swap(sizes[i], sizes[j]);
                    swap(outcome[i], outcome[j]);
                }
            }
        }
        
        vector<int> sol;
        if (outcome == string(outcome.size(), 'R')) {
            if (sizes[0] == 1) {
                sol.push_back(sizes.back()+1);
                sol.push_back(sizes.back()+1);
            } else {
                sol.push_back(1);
                sol.push_back(1);
            }
        } else {
            int p = outcome.find('A');
            int q = p;
            while (q<n && outcome[q]=='A') {
                ++q;
            }
            if (q==n || outcome.substr(q).find('A')==string::npos) {
                sol.push_back(sizes[p]);
                sol.push_back(sizes[q-1]);
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAAA"; int Arr2[] = {3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AARAA"; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RAAAA"; int Arr2[] = {4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {68,57,7,41,76,53,43,77,84,52,34,48,27,75,36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RARRRARRRARARRR"; int Arr2[] = {48, 57 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {26,81,9,14,43,77,55,57,12,34,29,79,40,25,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ARAAARRARARARAA"; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, designFilter(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Filtering ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
