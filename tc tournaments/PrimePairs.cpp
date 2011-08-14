#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool not_prime[2001];

vector<int> even, odd;
int match[50], rmatch[50];
bool used[50];

bool get_match_(int x) {
    used[x] = 1;
    for (int y=0; y<(int)odd.size(); ++y) {
        if (!not_prime[even[x] + odd[y]]) {
            if (rmatch[y]==-1 || !used[rmatch[y]] && get_match_(rmatch[y])) {
                rmatch[y] = x;
                match[x] = y;
                return true;
            }
        }
    }

    return false;
}
bool get_match(int x) {
    memset(used, 0, sizeof used);
    return get_match_(x);
}
int bi_match() {
    if (even.size() != odd.size()) {
        return 0;
    }
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);

    int ret = 0;
    for (int i=0; i<(int)odd.size(); ++i) {
        if (match[i] == -1) {
            if (get_match(i)) {
                ++ret;
            } else {
                return 0;
            }
        }
    }

    return ret;
}

class PrimePairs {
	public:
	vector <int> matches(vector <int> numbers) {
		memset(not_prime, 0, sizeof not_prime);
        not_prime[0] = not_prime[1] = 1;
        for (int x=2; x<=2000; ++x) {
            if (!not_prime[x]) {
                for (int y=2*x; y<=2000; y+=x) {
                    not_prime[y] = 1;
                }
            }
        }

        if (numbers.size() == 2) {
            if (not_prime[numbers[0] + numbers[1]]) {
                return vector<int> ();
            } else {
                return vector<int> (1, numbers[1]);
            }
        }
        
        vector<int> sol;
        for (int i=1; i<(int)numbers.size(); ++i) {
            if (not_prime[numbers[0] + numbers[i]]) {
                continue;
            }
            even.clear();
            odd.clear();
            for (int j=1; j<(int)numbers.size(); ++j) {
                if (j != i) {
                    if (numbers[j] & 1) {
                        odd.push_back(numbers[j]);
                    } else {
                        even.push_back(numbers[j]);
                    }
                }
            }
            if (2*bi_match() == (int)numbers.size()-2) {
                sol.push_back(numbers[i]);
            }
        }

        sort(sol.begin(), sol.end());
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 1, 4, 7, 10, 11, 12 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, matches(Arg0)); }
	void test_case_1() { int Arr0[] = { 11, 1, 4, 7, 10, 12 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, matches(Arg0)); }
	void test_case_2() { int Arr0[] = { 8, 9, 1, 14 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, matches(Arg0)); }
	void test_case_3() { int Arr0[] = { 34, 39, 32, 4, 9, 35, 14, 17 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 39 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, matches(Arg0)); }
	void test_case_4() { int Arr0[] = { 941, 902, 873, 841, 948, 851, 945, 854, 815, 898,
  806, 826, 976, 878, 861, 919, 926, 901, 875, 864 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {806, 926 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, matches(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrimePairs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
