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

long long diff[1<<18];
map<long long, vector<int> > M;
vector<long long> S1, S2;
int n;
void go(int p, long long d, int m) {
    if (p == n/2) {
        diff[m] = d;
    } else {
        go(p+1, d+S1[p], m);
        go(p+1, d-S2[p], m | (1<<(n/2-1 - p)));
    }
}
void go2(int p, long long d, int m) {
    if (p == n/2) {
        M[d].push_back(m);
    } else {
        go2(p+1, d+S1[n/2+p], m);
        go2(p+1, d-S2[n/2+p], m | (1<<(n/2-1 - p)));
    }
}
long long my_abs(long long x) { return (x<0 ? -x : x); }

int bc[1<<18];
    
class PickingUp {
	public:
	vector <int> fairPickingUp(vector<long long> score1, vector<long long> score2) {
	    M.clear();
        S1 = score1;
        S2 = score2;
        n = S1.size();
        bc[0] = 0;
        for (int i=1; i<(1<<18); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        memset(diff, 0, sizeof diff);
        go(0, 0, 0);
        go2(0, 0, 0);
        
        vector<long long> A[19];
        vector<int> B[19];
        for (map<long long, vector<int> >::const_iterator it=M.begin(); it!=M.end(); ++it) {
            const vector<int> &v = it->second;
            for (int i=0; i<(int)v.size(); ++i) {
                int b = bc[v[i]];
                if (A[b].size()==0 || A[b].back()!=(it->first)) {
                    A[b].push_back(it->first);
                    B[b].push_back(v[i]);
                }
            }
        }
        
        long long bestdiff = 923456789012345678LL;
        long long bestmask = 0;
        for (int i=0; i<(1<<(n/2)); ++i) {
            long long d = -diff[i];
            int b = n/2 - bc[i];
            int k = lower_bound(A[b].begin(), A[b].end(), d) - A[b].begin();
            if (k > 0) {
                long long d2 = A[b][k-1];
                if (my_abs(d - d2) < bestdiff) {
                    bestdiff = my_abs(d-d2);
                    bestmask = (((long long)i)<<(n/2)) | B[b][k-1];
                }
            }
            if (k < (int)A[b].size()) {
                long long d2 = A[b][k];
                if (my_abs(d - d2) < bestdiff) {
                    bestdiff = my_abs(d-d2);
                    bestmask = (((long long)i)<<(n/2)) | B[b][k];
                }
            }
        }
        
        vector<int> sol;
        for (int i=0; i<n; ++i) {
            sol.push_back((bestmask & 1) + 1);
            bestmask >>= 1;
        }
        reverse(sol.begin(), sol.end());
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long Arr0[] = {5,9}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {8,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, fairPickingUp(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {2,3,4,7}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {2,4,5,8}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, fairPickingUp(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {1,5,6,8}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {7,5,3,1}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, fairPickingUp(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {300,300,300,300}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {600,10,10,10}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, fairPickingUp(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {50,50,50,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {30,30,30,150}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, fairPickingUp(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PickingUp ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
