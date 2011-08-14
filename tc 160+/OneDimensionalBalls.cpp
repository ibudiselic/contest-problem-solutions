#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int my_abs(int x) {
    return x<0 ? -x : x;
}
int AG[50][2];
int BG[50][2];
bool visA[50];
bool visB[50];
int M, N;
int dfsB(int, int);
int dfsA(int u, int from=-1) {
    visA[u] = true;
    if (AG[u][0] != from) {
        return 1 + dfsB(AG[u][0], u);
    } else if (AG[u][1]!=-1 && AG[u][1]!=from) {
        return 1 + dfsB(AG[u][1], u);
    } else {
        return 1;
    }
}
int dfsB(int u, int from=-1) {
    visB[u] = true;
    if (BG[u][0] != from) {
        return 1 + dfsA(BG[u][0], u);
    } else if (BG[u][1]!=-1 && BG[u][1]!=from) {
        return 1 + dfsA(BG[u][1], u);
    } else {
        return 1;
    }
}
long long dpA[101], dpB[101];
long long chainA(int sz) {
    long long &ret = dpA[sz];
    if (ret != -1) {
        return ret;
    }
    if (sz == 2) {
        ret = 1;
    } else if (sz < 2) {
        ret = 0;
    } else {
        ret = chainA(sz-2);
    }
    return ret;
}
long long chainB(int sz) {
    long long &ret = dpB[sz];
    if (ret != -1) {
        return ret;
    }
    if (sz==2 || sz==1) {
        ret = 1;
    } else if (sz < 1) {
        ret = 0;
    } else {
        ret = chainA(sz-1) + chainB(sz-2);
    }
    return ret;
}
class OneDimensionalBalls {
	public:
	long long countValidGuesses(vector <int> A, vector <int> B) {
        M = A.size();
        N = B.size();
		set<int> V;
        memset(dpA, 0xff, sizeof dpA);
        memset(dpB, 0xff, sizeof dpB);
        for (int i=0; i<(int)A.size(); ++i) {
            for (int j=0; j<(int)B.size(); ++j) {
                if (A[i] != B[j]) {
                    V.insert(my_abs(A[i] - B[j]));
                }
            }
        }
        
        long long sol = 0;
        for (set<int>::const_iterator it=V.begin(); it!=V.end(); ++it) {
            int dist = *it;
            memset(AG, 0xff, sizeof AG);
            memset(BG, 0xff, sizeof BG);
            for (int i=0; i<(int)A.size(); ++i) {
                for (int j=0; j<(int)B.size(); ++j) {
                    if (my_abs(A[i]-B[j]) == dist) {
                        if (AG[i][0] == -1) {
                            AG[i][0] = j;
                        } else {
                            AG[i][1] = j;
                        }
                        if (BG[j][0] == -1) {
                            BG[j][0] = i;
                        } else {
                            BG[j][1] = i;
                        }
                    }
                }
            }
            memset(visA, 0, sizeof visA);
            memset(visB, 0, sizeof visB);
            long long ways = 1;
            for (int i=0; i<(int)A.size(); ++i) {
                if (!visA[i] && AG[i][0]!=-1 && AG[i][1]==-1) {
                    ways *= chainA(dfsA(i));
                }
            }
            for (int i=0; i<(int)B.size(); ++i) {
                if (!visB[i] && BG[i][0]!=-1 && BG[i][1]==-1) {
                    ways *= chainB(dfsB(i));
                }
            }
            
            for (int i=0; i<(int)A.size(); ++i) {
                if (!visA[i]) {
                    ways = 0;
                    break;
                }
            }
            
            sol += ways;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,11,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(0, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(2, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7234}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6316,689156,689160,689161,800000,1000001}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6LL; verify_case(3, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7LL; verify_case(4, Arg2, countValidGuesses(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    OneDimensionalBalls ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
