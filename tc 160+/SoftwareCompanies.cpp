#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int source = 0;
int sink = 1;
int SZ;
int C[50][50], F[50][50];
inline int left(int x) {
    return 2*x + 2;
}
inline int right(int x) {
    return 2*x + 3;
}
int INF = 987654321;
int P[50];

vector<string> construct(int mask, const vector<string> &names) {
    vector<string> ret;
    for (int i=0; i<(int)names.size(); ++i) {
        if (mask & (1<<i)) {
            ret.push_back(names[i]);
        }
    }

    sort(ret.begin(), ret.end());
    return ret;
}

int augment() {
    memset(P, 0xff, sizeof P);
    P[source] = -2;
    queue<int> Q;
    Q.push(source);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int i=0; i<SZ; ++i) {
            if (P[i]==-1 && C[x][i]-F[x][i]>0) {
                P[i] = x;
                if (i == sink) {
                    goto FOUND;
                }
                Q.push(i);
            }
        }
    }
    return 0;

    FOUND: ;
    assert(P[sink] != -1);

    int x = sink;
    int ret = INF;
    while (P[x] != -2) {
        const int y = P[x];
        ret = min(ret, C[y][x]-F[y][x]);
        x = y;
    }
    x = sink;
    while (P[x] != -2) {
        const int y = P[x];
        F[y][x] += ret;
        F[x][y] -= ret;
        x = y;
    }

    return ret;
}

int max_flow() {
    int ret = 0;

    int t = 0;
    while ((t = augment()) > 0) {
        ret += t;
    }

    return ret;
}

string to_str(const vector<string> &v) {
    ostringstream os;
    os << v[0];
    for (int i=1; i<(int)v.size(); ++i) {
        os << ", " << v[i];
    }

    return os.str();
}

class SoftwareCompanies {
	public:
	vector <string> produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2) {
		int N = names.size();
        SZ = 2*N + 2;
        map<string, int> ind;
        for (int i=0; i<(int)names.size(); ++i) {
            ind[names[i]] = i;
        }

        vector< vector<int> > P(N, vector<int>());
        for (int i=0; i<N; ++i) {
            istringstream is(process[i]);
            string t;
            while (is >> t) {
                P[i].push_back(ind[t]);
            }
        }
        int C1 = ind[company1];
        int C2 = ind[company2];

        int bestval = 0;
        int best_cost = 123456789;
        vector<int> win_masks;

        for (int m=1; m<(1<<names.size()); ++m) {
            memset(C, 0, sizeof C);
            memset(F, 0, sizeof F);
            C[source][left(C1)] = INF;
            C[right(C2)][sink] = INF;
            int ncost = 0;
            for (int i=0; i<N; ++i) {
                if (m & (1<<i)) {
                    ncost += cost[i];

                    C[left(i)][right(i)] = amount[i];
                    for (int j=0; j<(int)P[i].size(); ++j) {
                        int x = P[i][j];
                        if (m & (1<<x)) {
                            C[right(i)][left(x)] = INF;
                        }
                    }
                }
            }

            int nval = max_flow();
            if (nval > bestval) {
                bestval = nval;
                best_cost = ncost;
                win_masks.assign(1, m);
            } else if (nval == bestval) {
                if (ncost < best_cost) {
                    best_cost = ncost;
                    win_masks.assign(1, m);
                } else if (ncost == best_cost) {
                    win_masks.push_back(m);
                }
            }
        }
        if (bestval == 0) {
            return vector<string>();
        }

        assert(win_masks.size() > 0);
        vector<string> sol = construct(win_masks[0], names);
        for (int i=1; i<(int)win_masks.size(); ++i) {
            sol = min(sol, construct(win_masks[i], names));
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"topcoder", "doodle", "nasa", "ninny", "idm", "noname", "kintel"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"doodle nasa noname", "idm ninny noname", "idm ninny noname", "kintel", "kintel", "", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 7, 4, 6, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50, 10, 11, 9, 14, 11, 23}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "topcoder"; string Arg5 = "kintel"; string Arr6[] = {"doodle", "idm", "kintel", "nasa", "ninny", "topcoder" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, produceData(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 5, 10, 6, 6, 3, 0, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 7, 10, 9, 6, 9, 23, 13, 11}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "b"; string Arg5 = "d"; string Arr6[] = {"a", "b", "ba", "d" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, produceData(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 5, 10, 6, 6, 3, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 7, 10, 9, 6, 9, 23, 13, 11}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "b"; string Arg5 = "d"; string Arr6[] = {"b", "ba", "d" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, produceData(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"coma", "comb", "comc", "comd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"comb", "coma", "comd", "comc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 54, 18, 93}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 10, 10, 10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "comb"; string Arg5 = "comc"; string Arr6[] = { }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, produceData(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {"c", "b", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"b", "c", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 1, 22}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "c"; string Arg5 = "b"; string Arr6[] = {"a", "b", "c" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(4, Arg6, produceData(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SoftwareCompanies ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
