#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > F;
bool L[50];
int N;
enum {
    NONE, PARENT, BACK
};

long long dp[50][51][3];
int f;
long long go(int x, int k, int type, int p) {
    long long &ret = dp[x][k][type];
    if (ret != -1) {
        return ret;
    }
    
    vector<int> C;
    for (int i=0; i<(int)F[x].size(); ++i) {
        if (F[x][i] != p) {
            C.push_back(F[x][i]);
        }
    }
    
    ret = 0;
    switch (C.size()) {
        case 0:
            if (k > 1) {
                return (ret = 0);
            }
            switch (type) {
                case NONE:
                    if (k == 0) {
                        ret = 1;
                    } else {
                        assert(k == 1);
                        ret = (f!=x && L[x]);
                    }
                    break;
                case PARENT:
                    if (k == 0) {
                        ret = 1;
                    } else {
                        assert(k == 1);
                        ret = (f != x);
                    }
                    break;
                case BACK:
                    if (k == 0) {
                        ret = 0;
                    } else {
                        assert(k == 1);
                        ret = (f!=x && L[x]);
                    }
                    break;
            }
            break;
        case 1:
            switch (type) {
                case NONE:
                    ret = go(C[0], k, NONE, x);
                    if (f!=x && k>0) {
                        ret += go(C[0], k-1, L[x] ? PARENT : BACK, x);
                    }
                    break;
                case PARENT:
                    ret = go(C[0], k, NONE, x);
                    if (f!=x && k>0) {
                        ret += go(C[0], k-1, PARENT, x);
                    }
                    break;
                case BACK:
                    if (f==x || k==0) {
                        ret = 0;
                    } else {
                        ret = go(C[0], k-1, L[x] ? PARENT : BACK, x);
                    }
                    break;
            }
            break;
        case 2:
            const int a = C[0];
            const int b = C[1];
            switch (type) {
                case NONE:
                    for (int i=0; i<=k; ++i) {
                        ret += go(a, i, NONE, x) * go(b, k-i, NONE, x);
                    }
                    if (f!=x && k>0) {
                        if (L[x]) {
                            for (int i=0; i<k; ++i) {
                                ret += go(a, i, PARENT, x) * go(b, k-1-i, PARENT, x);
                            }
                        } else {
                            for (int i=0; i<k; ++i) {
                                ret += go(a, i, BACK, x)*go(b, k-1-i, PARENT, x) + go(a, i, PARENT, x)*go(b, k-1-i, BACK, x) - go(a, i, BACK, x)*go(b, k-1-i, BACK, x);
                            }
                        }
                    }
                    break;
                case PARENT:
                    for (int i=0; i<=k; ++i) {
                        ret += go(a, i, NONE, x) * go(b, k-i, NONE, x);
                    }
                    if (f!=x && k>0) {
                        for (int i=0; i<k; ++i) {
                            ret += go(a, i, PARENT, x) * go(b, k-1-i, PARENT, x);
                        }
                    }
                    break;
                case BACK:
                    if (f!=x && k>0) {
                        if (L[x]) {
                            for (int i=0; i<k; ++i) {
                                ret += go(a, i, PARENT, x) * go(b, k-1-i, PARENT, x);
                            }
                        } else {
                            for (int i=0; i<k; ++i) {
                                ret += go(a, i, BACK, x)*go(b, k-1-i, PARENT, x) + go(a, i, PARENT, x)*go(b, k-1-i, BACK, x) - go(a, i, BACK, x)*go(b, k-1-i, BACK, x);
                            }
                        }
                    }
                    break;
            }
            break;
    }
            
    return ret;
}
class TeamManagement {
	public:
	vector <double> getDistribution(int N, int K, vector <string> friends, string loyalty) {
        if (N == 1) {
            return vector<double>(1, loyalty[0]=='Y' ? 1.0 : 0.0);
        }
		F.assign(N, vector<int>());
        ::N = N;
        for (int i=0; i<(int)friends.size(); ++i) {
            int x, y;
            sscanf(friends[i].c_str(), "%d %d", &x, &y);
            F[x].push_back(y);
            F[y].push_back(x);
        }
        
        for (int i=0; i<N; ++i) {
            L[i] = (loyalty[i] == 'Y');
        }
        
        int root = -1;
        for (int i=0; i<N; ++i) {
            if (F[i].size() == 1) {
                root = i;
                break;
            }
        }
        assert(root != -1);

        memset(dp, 0xff, sizeof dp);
        f = -1;
        long long total = go(root, K, NONE, -1);
        
        vector<double> sol;
        sol.reserve(N);
        for (f=0; f<N; ++f) {
            memset(dp, 0xff, sizeof dp);
            sol.push_back(double(total - go(root, K, NONE, -1))/total);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; string Arr2[] = {"0 1", "1 2", "2 3", "3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYNN"; double Arr4[] = {0.33333333333333337, 0.6666666666666667, 1.0, 0.6666666666666667, 0.33333333333333337 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arr2[] = {"2 0", "2 1", "2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYN"; double Arr4[] = {0.6666666666666667, 0.6666666666666667, 1.0, 0.6666666666666667 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; string Arr2[] = {"4 3", "3 1", "3 0", "0 2", "0 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNNYY"; double Arr4[] = {0.8571428571428572, 0.4285714285714286, 0.4285714285714286, 0.8571428571428572, 0.7142857142857143, 0.7142857142857143 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"3 0", "0 2", "0 4", "4 1", "2 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYNNN"; double Arr4[] = {0.33333333333333337, 0.33333333333333337, 0.33333333333333337, 0.0, 0.0, 0.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 7; string Arr2[] = {"3 1", "1 5", "5 4", "4 0", "4 6", "5 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNNNNY"; double Arr4[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TeamManagement ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
