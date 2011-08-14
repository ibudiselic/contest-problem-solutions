#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 1000000007;
long long dp[128][128][128];
int max_root;
long long go(int root, int d, int moves) {
    long long &ret = dp[root][d][moves];
    if (ret != -1) {
        return ret;
    }
    if (moves == 0) {
        return (ret = (root==0 && d==0));
    }
    if (root+d>moves || root>max_root) {
        return (ret = 0);
    }
    
    if (d == 0) {
        if (root == 0) {
            ret = 2*go(0, 1, moves-1) + go(1, 0, moves-1);
        } else {
            ret = go(root-1, 0, moves-1) +
                  go(root+1, 0, moves-1) + 
                  go(root  , 1, moves-1);
        }
    } else {
        ret = 2*go(root, d+1, moves-1) + go(root, d-1, moves-1);
    }
    ret %= mod;
    return ret;
}

bool to_parent(vector< long long > &v) {
    long long a = v[1] - v[0];
    long long b = v[2] - v[1];
    if (a == b) {
        return false;
    } else {
        if (a < b) {
            swap(v[0], v[1]);
            v[1] = v[0] + a;
        } else {
            swap(v[1], v[2]);
            v[1] = v[2] - b;
        }
        return true;
    }
}
class RabbitPuzzle {
	public:
	int theCount(vector<long long> rabbits, vector<long long> nests, int K) {
		vector< vector<long long> > roots;
        do {
            roots.push_back(nests);
        } while ((int)roots.size()<=K && to_parent(nests));
        max_root = (int)roots.size() - 1;
        
        int rabbit_root = -1;
        int rabbit_dist = 0;
        do {
            int p = find(roots.begin(), roots.end(), rabbits) - roots.begin();
            if (p < (int)roots.size()) {
                rabbit_root = p;
                break;
            }
            ++rabbit_dist;
        } while (rabbit_dist<=K && to_parent(rabbits));
        
        if (rabbit_root == -1) {
            return 0;
        }
        
        memset(dp, 0xff, sizeof dp);
        return int(go(rabbit_root, rabbit_dist, K));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arr0[] = {0, 5, 8}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 8, 11}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arr0[] = {0, 5, 8}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 8, 11}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 5; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arr0[] = {0, 5, 8}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 8, 11}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 0; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arr0[] = {5, 8, 58}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {13, 22, 64}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; int Arg3 = 0; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arr0[] = {0, 1, 2}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {1, 2, 3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 0; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arr0[] = {5, 8, 58}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {20, 26, 61}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; int Arg3 = 537851168; verify_case(5, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_6() { long long Arr0[] = {67, 281, 2348}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {235, 1394, 3293}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 83; int Arg3 = 167142023; verify_case(6, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_7() { long long Arr0[] = {-1000000000000000000LL, 999999999999999998LL, 999999999999999999LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arr1[] = {-1000000000000000000LL, 999999999999999999LL, 1000000000000000000LL}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 29; verify_case(7, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitPuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
