#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

class LockersDivTwo {
	public:
	int lastOpened(int N) {
		list<int> L;
        for (int i=0; i<N; ++i) {
            L.push_back(i);
        }
        int step = 1;
        while (L.size() > 1) {
            list<int>::iterator it=L.begin();
            while (it != L.end()) {
                it = L.erase(it);
                int i = 0;
                while (it!=L.end() && i<step) {
                    ++it;
                    ++i;
                }
            }
            ++step;
        }
        return *L.begin()+1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 6; verify_case(0, Arg1, lastOpened(Arg0)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 42; verify_case(1, Arg1, lastOpened(Arg0)); }
	void test_case_2() { int Arg0 = 314; int Arg1 = 282; verify_case(2, Arg1, lastOpened(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LockersDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
