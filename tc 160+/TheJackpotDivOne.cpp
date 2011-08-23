#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long get_target(const vector<long long> &A) {
    long long a = 0, b = 0;
    const long long n = A.size();
    for (int i=0; i<n; ++i) {
        a += A[i]/n;
        b += A[i]%n;
    }
    return a + b/n + 1;
}
class TheJackpotDivOne {
	public:
	vector<long long> find(vector<long long> money, long long jackpot) {
        sort(money.begin(), money.end());
        long long diff = money.back() - money[0];
        while (diff > 0) {
            long long target = get_target(money);
            long long x = target - money[0];
            if (x >= jackpot) {
                money[0] += jackpot;
                sort(money.begin(), money.end());
                return money;
            }
            money[0] = target;
            jackpot -= x;
            for (int i=1; i<(int)money.size() && money[i]<money[0]; ++i) {
                target = get_target(money);
                x = target - money[i];
                if (x >= jackpot) {
                    money[i] += jackpot;
                    sort(money.begin(), money.end());
                    return money;
                }
                money[i] = target;
                jackpot -= x;
            }
            sort(money.begin(), money.end());
            diff = money.back() - money[0];
        }
        
        if (jackpot > 0) {
            int n = money.size();
            long long x = jackpot/n;
            for (int i=0; i<n; ++i) {
                money[i] += x;
            }
            for (int i=0; i<jackpot%n; ++i) {
                ++money[n-1-i];
            }
        }
        return money;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long Arr0[] = {1, 2, 3, 4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long Arr2[] = {2, 3, 3, 4 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; long Arr2[] = {11 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {4, 44, 7, 77}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long Arr2[] = {24, 34, 44, 77 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {4, 10, 8, 3, 6, 5, 8, 3, 7, 5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000LL; long Arr2[] = {105, 106, 106, 106, 106, 106, 106, 106, 106, 106 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheJackpotDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
