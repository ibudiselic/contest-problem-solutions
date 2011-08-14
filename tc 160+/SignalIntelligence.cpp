#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool can_do(const vector<int> &v, int lim, int done) {
    long long start = 1;
    int start_pot = 0;
    vector<int> t;
    for (int i=0; i<(int)v.size(); ++i) {
        if (i != done) {
            t.push_back(v[i]);
        }
    }
    sort(t.begin(), t.end());
    for (int i=0; i<(int)t.size(); ++i) {
        start += t[i]+1;
        while (start_pot<=lim && (1LL<<start_pot)<start) {
            ++start_pot;
        }
        start = (1LL<<start_pot);
        if (start_pot > lim) {
            return false;
        }
    }
    return true;
}
class SignalIntelligence {
	public:
	long long encrypt(vector <int> numbers) {
		long long sol = (1LL<<62) + 1;
        for (int i=0; i<62; ++i) {
            if (sol < (1LL<<i)) {
                break;
            }
            for (int j=0; j<(int)numbers.size(); ++j) {
                if (sol>(1LL<<i)+numbers[j]-1 && can_do(numbers, i, j)) {
                    sol = (1LL<<i) + numbers[j] - 1;
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(0, Arg1, encrypt(Arg0)); }
	void test_case_1() { int Arr0[] = {4,4,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 19LL; verify_case(1, Arg1, encrypt(Arg0)); }
	void test_case_2() { int Arr0[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 281475976710655LL; verify_case(2, Arg1, encrypt(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SignalIntelligence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
