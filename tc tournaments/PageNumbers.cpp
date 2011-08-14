#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long total[10][10][2];
long long T[10];
string S;
void add(int d, vector<int> &v) {
    for (int i=0; i<10; ++i) {
        v[i] += total[d][i][1];
    }
}

int to_num(int start) {
    istringstream is(S.substr(start));
    int x;
    is >> x;
    return x;
}

bool done[10][2];
vector<int> dp[10][2];
vector<int> go(int p, bool any) {
    if (p == (int)S.size()) {
        return vector<int>(10, 0);
    }
    
    if (done[p][any]) {
        return dp[p][any];
    }

    done[p][any] = 1;
    vector<int> ret(10, 0);

    for (char c=(p==0 ? '1' : '0'); c<=S[p] || (any && c<='9'); ++c) {
        vector<int> t = go(p+1, any || (c<S[p]));
        ret[c-'0'] += (any||c<S[p] ? T[(int)S.size()-1-p]/10 : to_num(p+1)+1);
        for (int i=0; i<10; ++i) {
            ret[i] += t[i];
        }
    }

    return (dp[p][any] = ret);
}
       
class PageNumbers {
	public:
	vector <int> getCounts(int N) {
		ostringstream os;
        os << N;
        S = os.str();

        memset(total, 0, sizeof total);
        for (int i=0; i<10; ++i) {
            total[0][i][1] = total[0][i][0] = 1;
        }
        total[0][0][1] = 0;

        T[0] = 10;
        for (int i=1; i<10; ++i) {
            T[i] = 10 * T[i-1];
        }

        for (int d=1; d<10; ++d) {
            for (int i=1; i<10; ++i) {
                total[d][i][0] = 10*total[d-1][i][0] + T[d-1];
                total[d][i][1] = 9*total[d-1][i][0] + T[d-1];
            }
            total[d][0][0] = 10*total[d-1][0][0] + T[d-1];
            total[d][0][1] = 9*total[d-1][0][0];
        }

        int tt = 0;
        vector<int> sol(10, 0);
        while (T[tt] <= N) {
            add(tt, sol);
            ++tt;
        }

        memset(done, 0, sizeof done);
        vector<int> t = go(0, 0);

        for (int i=0; i<10; ++i) {
            sol[i] += t[i];
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 7; int Arr1[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getCounts(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arr1[] = {1, 4, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getCounts(Arg0)); }
	void test_case_2() { int Arg0 = 19; int Arr1[] = {1, 12, 2, 2, 2, 2, 2, 2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getCounts(Arg0)); }
	void test_case_3() { int Arg0 = 999; int Arr1[] = {189, 300, 300, 300, 300, 300, 300, 300, 300, 300 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getCounts(Arg0)); }
	void test_case_4() { int Arg0 = 543212345; int Arr1[] = {429904664, 541008121, 540917467, 540117067, 533117017, 473117011, 429904664, 429904664, 429904664, 429904664 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getCounts(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PageNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
