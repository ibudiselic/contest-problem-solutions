#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int N, K, L;
int P[200];
int rightmost_child[200];
int left_sibling[200];
int G[200][200];
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
void init(int u, int p, int ls) {
    P[u] = p;
    left_sibling[u] = ls;
    
    ls = -1;
    for (int v=0; v<N; ++v) {
        if (v!=p && G[u][v]!=-1) {
            init(v, u, ls);
            ls = v;
        }
    }
    rightmost_child[u] = ls;
}
const int INF = 987654321;
int leftt[200][201], sub[200][201];
int calc_sub(int, int);
int calc_left(int u, int endpoints) {
    int &ret = leftt[u][endpoints];
    if (ret != -1) {
        return ret;
    }
    
    ret = INF;
    for (int i=0; i<=endpoints; ++i) {
        int tmp = calc_sub(u, i);
        if (left_sibling[u] != -1) {
            tmp += calc_left(left_sibling[u], endpoints-i);
        }
        ret = min(ret, tmp);
    }
    return ret;
}
int calc_sub(int u, int endpoints) {
    int &ret = sub[u][endpoints];
    if (ret != -1) {
        return ret;
    }
    if (rightmost_child[u] == -1) { // leaf
        assert(P[u] != -1);
        return (ret = G[P[u]][u] * (2-endpoints%2));
    }
    ret = calc_left(rightmost_child[u], endpoints);
    for (int i=1; i<=endpoints; ++i) {
        ret = min(ret, calc_left(rightmost_child[u], endpoints-i));
    }
    if (P[u] != -1) {
        ret += G[P[u]][u] * (2 - endpoints%2);
    }
    return ret;
}
class KingdomTour {
	public:
	int minTime(int n, vector <string> roads, int k, int l) {
		N = n;
        K = k;
        L = l;
        string s = accumulate(roads.begin(), roads.end(), string());
        vector<string> v = cutUp(s, ",");
        memset(G, 0xff, sizeof G);
        for (int i=0; i<(int)v.size(); ++i) {
            istringstream is(v[i]);
            int a, b, c;
            is >> a >> b >> c;
            
            G[a][b] = G[b][a] = c;
        }
        
        memset(P, 0xff, sizeof P);
        memset(rightmost_child, 0xff, sizeof rightmost_child);
        memset(left_sibling, 0xff, sizeof left_sibling);
        memset(sub, 0xff, sizeof sub);
        memset(leftt, 0xff, sizeof leftt);
        
        init(0, -1, -1);
        int sol = INF;
        for (int i=0; i<=K; ++i) {
            sol = min(sol, calc_sub(0, 2*i) + i*L);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"2 1 9,0 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; int Arg4 = 16; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"0 1 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; int Arg4 = 7; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"4 0 4,2 0 4,2 5 4,4 3 1",
 "0,1 2 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; int Arg4 = 41; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"1 2 2,4 1 9,2 5 5,6 5 4,", "1 7 7,7 3 1,2 0 2", ",5 8 5,9 5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 59; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KingdomTour ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
