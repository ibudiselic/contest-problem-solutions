#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ConsecutiveNumbers {
	public:
	vector <int> missingNumber(vector <int> numbers) {
		sort(numbers.begin(), numbers.end());
        bool seq = true;
        for (int i=1; i<(int)numbers.size(); ++i) {
            if (numbers[i] == numbers[i-1]) {
                return vector<int>();
            }
            if (numbers[i]-1 != numbers[i-1]) {
                seq = false;
            }
        }

        if (seq) {
            vector<int> sol;
            if (numbers[0] > 1) {
                sol.push_back(numbers[0]-1);
            }
            sol.push_back(numbers.back()+1);
            return sol;
        }

        int cnt_holes = 0;
        for (int i=1; i<(int)numbers.size(); ++i) {
            if (numbers[i]-numbers[i-1] > 2) {
                return vector<int>();
            }
            cnt_holes += (numbers[i]-numbers[i-1] == 2);
        }

        if (cnt_holes > 1) {
            return vector<int>();
        }

        for (int i=1; i<(int)numbers.size(); ++i) {
            if (numbers[i]-numbers[i-1] == 2) {
                return vector<int> (1, numbers[i-1]+1);
            }
        }

        return vector<int>();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10,7,12,8,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, missingNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, missingNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, missingNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999999999, 1000000001 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, missingNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {1,6,9,3,8,12,7,4,11,5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, missingNumber(Arg0)); }
	void test_case_5() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, missingNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConsecutiveNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
