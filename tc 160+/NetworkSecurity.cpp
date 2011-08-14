#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

vector<string> c2c, c2s;
bool G[50][50];
bool can_reach[50][50];
class NetworkSecurity {
	public:
	int secureNetwork(vector <string> clientCable, vector <string> serverCable) {
		c2c = clientCable;
        c2s = serverCable;
        int C = c2c.size();
        int S = c2s[0].size();
        
        for (int i=0; i<C; ++i) {
            for (int j=0; j<C; ++j) {
                G[i][j] = (c2c[i][j]=='Y');
            }
        }
        
        for (int k=0; k<C; ++k) {
            for (int i=0; i<C; ++i) {
                for (int j=0; j<C; ++j) {
                    G[i][j] |= (G[i][k] && G[k][j]);
                }
            }
        }
        memset(can_reach, 0, sizeof can_reach);
        for (int i=0; i<C; ++i) {
            for (int j=0; j<S; ++j) {
                if (c2s[i][j] == 'Y') {
                    can_reach[i][j] = true;
                } else {
                    for (int k=0; k<C; ++k) {
                        if (G[i][k] && c2s[k][j]=='Y') {
                            can_reach[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        vector<int> orig_degs(C, 0);
        for (int i=0; i<C; ++i) {
            for (int j=0; j<C; ++j) {
                orig_degs[i] += (c2c[i][j]=='Y');
            }
        }

        int sol = 0;
        for (int i=0; i<S; ++i) {
            vector<int> degs = orig_degs;
            vector<int> done(C, 0);
            priority_queue< pair<int, int> > PQ;
            for (int j=0; j<C; ++j) {
                PQ.push(make_pair(-degs[j], j));
            }
            while (!PQ.empty()) {
                pair<int, int> tmp = PQ.top();
                PQ.pop();
                int deg = -tmp.first;
                int ind = tmp.second;
                if (deg > 0) {
                    break;
                }
                if (can_reach[ind][i] && !done[ind]) {
                    ++sol;
                    done[ind] = true;
                    for (int j=0; j<C; ++j) {
                        if (G[j][ind]) {
                            done[j] = true;
                        }
                    }
                }
                for (int j=0; j<C; ++j) {
                    if (c2c[j][ind] == 'Y') {
                        --degs[j];
                        PQ.push(make_pair(-degs[j], j));
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"NNN"
,"NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN"
,"YN"
,"NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYN"
,"NNN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, secureNetwork(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NetworkSecurity ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
