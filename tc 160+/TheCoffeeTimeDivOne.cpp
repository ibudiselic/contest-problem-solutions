#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TheCoffeeTimeDivOne {
	public:
	long long find(int n, vector <int> tea) {
		sort(tea.begin(), tea.end());
        long long sol = 0;
        long long p = (int)tea.size() - 1;
        while (p >= 0) {
            long long t = max(0LL, p - 6);
            int cnt = p-t+1;
            sol += 47 + 2*tea[p] + cnt*4;
            p = t - 1;
        }
        p = n;
        int tpos = (int)tea.size() - 1;
        int rem = 0;
        int cur_pos = 0;
        while (p > 0) {
            while (tpos>=0 && tea[tpos]>p) {
                --tpos;
            }
            
            if (tpos == -1) {
                if (rem > 0) {
                    sol += 4 + (cur_pos-p);
                    cur_pos = p;
                    if (--rem == 0) {
                        sol += p;
                    }
                    --p;
                } else {
                    int free_to = 1;
                    long long full = (p-free_to+1)/7;
                    sol += full*47 + 2*(full*p - 7*full*(full-1)/2) + 7*full*4;
                    int tmp = (p-free_to+1)%7;
                    p -= full*7;
                    if (tmp) {
                        sol += 47 + 2*p + tmp*4;
                    }
                    return sol;
                }
            } else if (p == tea[tpos]) {
                --p;
            } else if (rem > 0) {
                sol += 4 + (cur_pos-p);
                cur_pos = p;
                if (--rem == 0) {
                    sol += p;
                }
                --p;
            } else {
                int free_to = max(1, tea[tpos] + 1);
                long long full = (p-free_to+1)/7;
                sol += full*47 + 2*(full*p - 7*full*(full-1)/2) + 7*full*4;
                int tmp = (p-free_to+1)%7;
                p -= full*7;
                if (tmp > 0) {
                    rem = 7;
                    sol += 47 + p;
                    cur_pos = p;
                }
            }
        }
        if (rem > 0) {
            sol += cur_pos;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 108LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 59LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 261LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {1, 10, 6, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 891LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCoffeeTimeDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
