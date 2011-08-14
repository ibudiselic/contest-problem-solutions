#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char S[10000101];
int ind[10000000];
int T[50];
class EasySequence {
	public:
	int find(vector <int> A, vector <int> B) {
	    int state = 0;
        int cnt = 0;
        int mask = 1;
        int cur = 0;
        memset(ind, 0xff, sizeof ind);
        deque<int> Q;
        for (int i=0; i<(int)A.size(); ++i) {
            S[cnt++] = A[i];
            state = state*10 + A[i];
            mask *= 10;
            cur += A[i];
            Q.push_back(A[i]);
        }
        while (1) {
            const int next = cur % 10;
            Q.push_back(next);
            cur -= Q.front() - next;
            Q.pop_front();
            state = (state*10 + next) % mask;
            if (ind[state] == -1) {
                ind[state] = cnt;
                S[cnt++] = next;
            } else {
                const int len = cnt - ind[state];
                for (int i=0; i<100; ++i) {
                    S[cnt] = S[cnt-len];
                    ++cnt;
                }
                break;
            }
        }
        
        T[0] = -1;
        T[1] = 0;
        int len = 0;
        int i = 2;
        while (i < (int)B.size()) {
            if (B[i-1] == B[len]) {
                T[i++] = ++len;
            } else if (len > 0) {
                len = T[len];
            } else {
                T[i++] = 0;
            }
        }
        
        int m = 0;
        i = 0;
        while (i+m < cnt) {
            if (S[i+m] == B[m]) {
                if (++m == (int)B.size()) {
                    return i;
                }
            } else {
                i += m - T[m];
                if (m != 0) {
                    m = T[m];
                }
            }
        }
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,7,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,4,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EasySequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
