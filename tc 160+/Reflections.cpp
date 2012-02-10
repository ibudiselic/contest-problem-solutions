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

int bc[1<<20];

// calculate all possible sums into V[p][m] such that there are p additions and m subtractions
void precalc(vector<int>::const_iterator l, vector<int>::const_iterator r, vector<long long> V[11][11]) {
    int n = r - l;
    V[0][0].push_back(0);
    for (int mask=1; mask<(1<<n); ++mask) {
        int sz = bc[mask];
        for (int sub=mask; sub; sub=(sub-1)&mask) {
            if (2*bc[sub] < sz) continue;
            int p = 0;
            long long s = 0;
            long long t = 0;
            for (int i=0; i<n; ++i) {
                if (sub & (1<<i)) {
                    ++p;
                    s += *(l+i);
                } else if (mask & (1<<i)) {
                    t += *(l+i);
                }
            }
            V[p][sz-p].push_back(2*(s - t));
            V[sz-p][p].push_back(2*(t - s));
        }
    }
}
long long my_abs(long long x) {
    return x<0 ? -x : x;
}
long long steps1(int X, const vector<int> &M) { // ~340ms
    vector<long long> A[11][11], B[11][11];
    const int n = M.size();
    precalc(M.begin(), M.begin()+n/2, A);
    precalc(M.begin()+n/2, M.end(), B);
    const int n1 = n/2;
    const int n2 = n - n1;
    for (int i=0; i<=n1; ++i) {
        for (int j=0; j<=n1; ++j) {
            sort(A[i][j].begin(), A[i][j].end());
        }
    }
    
    long long sol = X<0 ? -X : X;
    for (int i=0; i<=n2; ++i) {
        for (int j=0; j<=n2; ++j) {
            for (int k=0; k<=n1; ++k) {
                for (int l=0; l<=n1; ++l) {
                    if (i+k==j+l || i+k==j+l+1) {
                        for (int u=0; u<(int)B[i][j].size(); ++u) {
                            long long v = B[i][j][u];
                            int p = lower_bound(A[k][l].begin(), A[k][l].end(), X - v) - A[k][l].begin();
                            if (p < (int)A[k][l].size()) {
                                sol = min(sol, my_abs(v + A[k][l][p] - X) + i+k+j+l);
                            }
                            if (p > 0) {
                                sol = min(sol, my_abs(v + A[k][l][p-1] - X) + i+k+j+l);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return sol;
}

// with both A and B sorted, find smallest |elem(A)+elem(B)-X| in O(|A| + |B|)
long long join(const vector<long long> &A, const vector<long long> &B, long long X) {
    int i = 0;
    int j = (int)B.size() - 1;
    long long ret = my_abs(X); // this is "infinity"
    while (i<(int)A.size() && j>=0) {
        ret = min(ret, my_abs(A[i]+B[j]-X));
        if (A[i]+B[j] >= X) {
            --j;
        } else {
            ++i;
        }
    }
    return ret;
}
long long steps2(int X, const vector<int> &M) { // alt solution without BS ~137ms
    vector<long long> A[11][11], B[11][11];
    const int n = M.size();
    precalc(M.begin(), M.begin()+n/2, A);
    precalc(M.begin()+n/2, M.end(), B);
    const int n1 = n/2;
    const int n2 = n - n1;
    for (int i=0; i<=n1; ++i) {
        for (int j=0; j<=n1; ++j) {
            sort(A[i][j].begin(), A[i][j].end());
        }
    }
    for (int i=0; i<=n2; ++i) {
        for (int j=0; j<=n2; ++j) {
            sort(B[i][j].begin(), B[i][j].end());
        }
    }
    
    long long sol = X<0 ? -X : X;
    for (int i=0; i<=n2; ++i) {
        for (int j=0; j<=n2; ++j) {
            for (int k=0; k<=n1; ++k) {
                for (int l=0; l<=n1; ++l) {
                    if (i+k==j+l || i+k==j+l+1) {
                        sol = min(sol, join(B[i][j], A[k][l], X) + i+j+k+l);
                    }
                }
            }
        }
    }
    
    return sol;
}

void gen(int i, int mask, long long cur, const vector<int> &M, vector<long long> sums[11]) {
    if (2*bc[mask]-1 > (int)M.size()) {
        return;
    }
    if (i == (int)M.size()) {
        sums[bc[mask]].push_back(2*cur);
    } else {
        gen(i+1, mask         , cur     , M, sums);
        gen(i+1, mask | (1<<i), cur+M[i], M, sums);
    }
}
// this solution allows overlap between the + and - sets of mirrors but this kind of combination is never optimal so it's not a problem
// ~1.2s
long long steps3(int X, const vector<int> &M) {
    vector<long long> sums[11];
    gen(0, 0, 0, M, sums);
    const int n = M.size();
    for (int i=0; i<=(n+1)/2; ++i) {
        sort(sums[i].begin(), sums[i].end());
    }
    long long sol = my_abs(X);
    for (int i=0; i<=(n+1)/2; ++i) {
        for (int j=0; j<(int)sums[i].size(); ++j) {
            long long v = sums[i][j];

            for (int other=i; other>=0 && other>=i-1; --other) {
                vector<long long>::const_iterator p = lower_bound(sums[other].begin(), sums[other].end(), v - X);
                if (p != sums[other].end()) {
                    sol = min(sol, my_abs(v - *p - X) + i+other);
                }
                if (p > sums[other].begin()) {
                    sol = min(sol, my_abs(v - *(p-1) - X) + i+other);
                }
            }
        }
    }
    return sol;
}

// with both A and B sorted, find smallest |elem(A)-elem(B)-X| in O(|A| + |B|)
long long join2(const vector<long long> &A, const vector<long long> &B, long long X) {
    int i = 0;
    int j = 0;
    long long ret = my_abs(X); // this is "infinity"
    while (i<(int)A.size() && j<(int)B.size()) {
        ret = min(ret, my_abs(A[i]-B[j]-X));
        if (A[i]-B[j] >= X) {
            ++j;
        } else {
            ++i;
        }
    }
    return ret;
}

// like steps3 without BS ~712ms
long long steps(int X, const vector<int> &M) {
    vector<long long> sums[11];
    gen(0, 0, 0, M, sums);
    const int n = M.size();
    for (int i=0; i<=(n+1)/2; ++i) {
        sort(sums[i].begin(), sums[i].end());
    }
    long long sol = my_abs(X);
    for (int i=0; i<=(n+1)/2; ++i) {
        for (int other=i; other>=0 && other>=i-1; --other) {
            sol = min(sol, join2(sums[i], sums[other], X) + i+other);
        }
    }
    return sol;
}

class Reflections {
	public:
	long long minimumMoves(vector <int> mirrorX, vector <int> mirrorY, vector <int> mirrorZ, vector <int> finalPosition) {
        for (int i=1; i<(1<<20); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
		return steps(finalPosition[0], mirrorX) + steps(finalPosition[1], mirrorY) + steps(finalPosition[2], mirrorZ);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3LL; verify_case(0, Arg4, minimumMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {-5, 1, 4, 2, 3, 6, -6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 2LL; verify_case(1, Arg4, minimumMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 4LL; verify_case(2, Arg4, minimumMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 12, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(3, Arg4, minimumMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {8, -3, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-7, -2, -1, 7, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40, -4, 31}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 10LL; verify_case(4, Arg4, minimumMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Reflections ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
