#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int mod = 1234567891;
struct State {
    int n;
    bool l4, r4;
    State(int n_, bool l4_, bool r4_): n(n_), l4(l4_), r4(r4_) {}
};
bool operator<(const State &a, const State &b) {
    if (a.n != b.n) {
        return a.n < b.n;
    }
    if (a.l4 != b.l4) {
        return a.l4 < b.l4;
    }
    return a.r4 < b.r4;
}

map<State, int> M;
vector<int> V;
vector<int> L, R;
bool is_lucky(int x) {
    if (x == 0) {
        return false;
    }
    while (x > 0) {
        int d = x%10;
        if (d!=4 && d!=7) {
            return false;
        }
        x /= 10;
    }

    return true;
}

int go(int n, bool l4, bool r4) {
    State s(n, l4, r4);
    if (M.find(s) != M.end()) {
        return M[s];
    }

    int &ret = M[s];
    if (n == 1) {
        for (int i=0; i<(int)V.size(); ++i) {
            if ((L[i]==4 && l4 || L[i]==7 && !l4) && (R[i]==4 && r4 || R[i]==7 && !r4)) {
                ++ret;
            }
        }

        return ret;
    }

    if (n & 1) {
        for (int i=0; i<(int)V.size(); ++i) {
            ret = (ret + (long long)go(n/2, l4, L[i]==4)*go(n/2, R[i]==4, r4)) % mod;
        }
    } else {
        for (int i=0; i<2; ++i) {
            ret = (ret + (long long)go(n/2, l4, i)*go(n/2, i, r4)) % mod;
        }
    }

    return ret;
}

class TheLuckySequence {
	public:
	int count(vector <int> numbers, int length) {
		M.clear();
        sort(numbers.begin(), numbers.end());
        for (int i=0; i<(int)numbers.size(); ++i) {
            if (!is_lucky(numbers[i])) {
                numbers.erase(numbers.begin() + i);
                --i;
            }
        }
        V.clear();
        unique_copy(numbers.begin(), numbers.end(), back_inserter(V));
        
        if (V.size() == 0) {
            return 0;
        }

        R.clear();
        L.clear();
        for (int i=0; i<(int)V.size(); ++i) {
            R.push_back(V[i]%10);
            int t = V[i];
            while (t > 10) {
                t /= 10;
            }
            L.push_back(t);
        }

        long long sol = 0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                sol = (sol + go(length, i, j)) % mod;
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
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {47, 74, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 4774, 200, 747, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {44, 47, 74, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckySequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
