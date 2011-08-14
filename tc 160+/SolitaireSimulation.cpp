#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <functional>

using namespace std;

class SolitaireSimulation {
	public:
	int periodLength(vector <int> heaps) {
	    sort(heaps.begin(), heaps.end(), greater<int>());
        map< vector<int>, int> M;
        M[heaps] = 0;

        int r = 0;
        while (1) {
            ++r;
            int nh = heaps.size();
            while (heaps.size()>0 && heaps.back()==1) {
                heaps.pop_back();
            }
            for (int i=0; i<(int)heaps.size(); ++i) {
                --heaps[i];
            }
            heaps.push_back(nh);
            int i = (int)heaps.size() - 2;

            while (i>=0 && heaps[i]<nh) {
                heaps[i+1] = heaps[i];
                --i;
            }
            heaps[i+1] = nh;

            if (M.count(heaps)) {
                return r - M[heaps];
            }
            M[heaps] = r;
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, periodLength(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, periodLength(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, periodLength(Arg0)); }
	void test_case_3() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, periodLength(Arg0)); }
	void test_case_4() { int Arr0[] = {3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, periodLength(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SolitaireSimulation ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
