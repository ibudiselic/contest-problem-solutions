#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_lucky(int x) {
    while (x > 0) {
        int d = x%10;
        if (d!=4 && d!=7) {
            return false;
        }
        x /= 10;
    }

    return true;
}

int choice[1000001];
int min_len[1000001];
class TheSumOfLuckyNumbers {
	public:
	vector <int> sum(int n) {
		vector<int> L;
        for (int i=4; i<=n; ++i) {
            if (is_lucky(i)) {
                L.push_back(i);
            }
        }

        memset(min_len, 0x3f, sizeof min_len);
        memset(choice, 0x3f, sizeof choice);
        for (int i=0; i<(int)L.size(); ++i) {
            min_len[L[i]] = 1;
            choice[L[i]] = i;
        }

        int dummy = 0x3f3f3f3f;
        for (int i=4; i<n; ++i) {
            if (min_len[i] < dummy) {
                for (int j=0; j<(int)L.size(); ++j) {
                    int next = i + L[j];
                    if (next > n) {
                        break;
                    }
                    if (min_len[next] > min_len[i] + 1) {
                        min_len[next] = min_len[i] + 1;
                        choice[next] = j;
                    } else if (min_len[next] == min_len[i] + 1) {
                        choice[next] = min(choice[next], j);
                    }
                }
            }
        }

        if (choice[n] == dummy) {
            return vector<int>();
        }

        vector<int> sol;
        while (n > 0) {
            assert(choice[n] != dummy);
            sol.push_back(L[choice[n]]);
            n -= L[choice[n]];
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 11; int Arr1[] = {4, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sum(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arr1[] = {4, 4, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sum(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sum(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {4, 4, 4, 44, 44 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSumOfLuckyNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
