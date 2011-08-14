#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TheCoffeeTimeDivTwo {
	public:
	int find(int n, vector <int> tea) {
		sort(tea.begin(), tea.end());
        int sol = 0;
        int p = tea.size()-1;
        while (p >= 0) {
            int t = max(p-6, 0);
            sol += 47 + 2*tea[p] + (p-t+1)*4;
            p = t-1;
        }
        p = n;
        int rem = 0;
        int t = tea.size()-1;
        while (p > 0) {
            while (t>=0 && tea[t]>p) {
                --t;
            }
            
            if (t == -1) {
                if (rem > 0) {
                    sol += 4;
                    --p;
                    --rem;
                } else {
                    int full = p/7;
                    sol += full*47 + 2*(full*p - 7*full*(full-1)/2) + 7*full*4;
                    int tmp = p % 7;
                    p -= full * 7;
                    if (tmp > 0) {
                        rem = 7;
                        sol += 47 + 2*p;
                    }
                }
            } else if (tea[t] == p) {
                --p;
                --t;
            } else if (rem > 0) {
                sol += 4;
                --rem;
                --p;
            } else {
                int free_to = tea[t]+1;
                int full = (p-free_to+1)/7;
                sol += full*47 + 2*(full*p - 7*full*(full-1)/2) + 7*full*4;
                int tmp = (p-free_to+1) % 7;
                p -= full * 7;
                if (tmp > 0) {
                    rem = 7;
                    sol += 47 + 2*p;
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 108; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 261; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {1, 10, 6, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 891; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCoffeeTimeDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
