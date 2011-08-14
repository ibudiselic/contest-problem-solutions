#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ShipLoading {
	public:
	int minimumTime(vector <int> cranes, vector <string> boxes_) {
		sort(cranes.begin(), cranes.end());
        reverse(cranes.begin(), cranes.end());
        string s = boxes_[0];
        for (int i=1; i<(int)boxes_.size(); ++i) {
            s += boxes_[i];
        }
        vector<int> boxes;
        boxes.reserve(2000);
        {
            istringstream is(s);
            int x;
            while (is >> x) {
                boxes.push_back(x);
            }
        }
        sort(boxes.begin(), boxes.end());
        if (boxes.back() > cranes[0]) {
            return -1;
        }

        bool done[2500] = { 0 };

        int sol = 0;
        int t = 0;

        while (t < (int)boxes.size()) {
            ++sol;
            for (int i=0; i<(int)cranes.size(); ++i) {
                int j = upper_bound(boxes.begin(), boxes.end(), cranes[i]) - boxes.begin();
                --j;
                while (j>=0 && done[j]) {
                    --j;
                }
                if (j < 0) {
                    continue;
                }
                done[j] = 1;
                ++t;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 5 2 4 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"14 12 16 19 16 1 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {23,32,25,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 27 10 16 24 20 2 32 18 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {11,17,5,2,20,7,5,5,20,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"18 18 15 15 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {56,114,979,120,120,87,480}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(4, Arg2, minimumTime(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ShipLoading ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
