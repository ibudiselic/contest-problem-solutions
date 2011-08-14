#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if ((n&1) == 0) {
        return false;
    } else {
        int d = 3;
        while (d*d <= n) {
            if (n%d == 0) {
                return false;
            }
            d += 2;
        }
    }
    return true;
}

bool P[1001];
int N;
bool ok(int i, int next, const string &colors) {
    while (i<(int)colors.size()) {
        if (colors[i] == 'R') {
            while (next<=N && !P[next]) {
                ++next;
            }
        } else {
            while (next<=N && P[next]) {
                ++next;
            }
        }
        if (next > N) {
            return false;
        }
        ++i;
        ++next;
    }
    return true;
}
class ColorfulCards {
	public:
	vector <int> theCards(int N_, string colors) {
        N = N_;
        for (int i=0; i<=N; ++i) {
            P[i] = is_prime(i);
        }
        
        int next = 1;
        vector<int> sol(colors.size(), -1);
        for (int i=0; i<(int)colors.size(); ++i) {
            if (colors[i] == 'R') { // there is always at least one way, so next can't "escape" out of bounds
                while (!P[next]) {
                    ++next;
                }
            } else {
                while (P[next]) {
                    ++next;
                }
            }
            sol[i] = ok(i, next+1, colors) ? -1 : next;
            ++next;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "RRR"; int Arr2[] = {2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, theCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BBB"; int Arr2[] = {1, 4, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, theCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "RBR"; int Arr2[] = {-1, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, theCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, theCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 495; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, theCards(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulCards ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
