#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

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

vector< vector<int> > G;
int n;
int C[200];
void dfs(int x, int comp) {
    C[x] = comp;
    for (int i=0; i<(int)G[x].size(); ++i) {
        if (C[G[x][i]] == -1) {
            dfs(G[x][i], comp);
        }
    }
}

bool v[200];
int cyc_next(int x, int start, int p) {
    v[x] = true;
    for (int i=0; i<(int)G[x].size(); ++i) {
        const int y = G[x][i];
        if (y == p) {
            continue;
        }
        if (y == start) {
            return -2;
        }
        if (!v[y]) {
            int t = cyc_next(y, start, x);
            if (t == -2) {
                if (x == start) {
                    return y;
                } else {
                    return -2;
                }
            }
        }
    }

    return -1;
}

void rem(int x, int y) {
    int i = find(G[x].begin(), G[x].end(), y) - G[x].begin();
    if (i != (int)G[x].size()-1) {
        swap(G[x][i], G[x][(int)G[x].size()-1]);
    }
    G[x].pop_back();
    i = find(G[y].begin(), G[y].end(), x) - G[y].begin();
    if (i != (int)G[y].size()-1) {
        swap(G[y][i], G[y][(int)G[y].size()-1]);
    }
    G[y].pop_back();
}

class CactusCount {
	public:
	int countCacti(int n, vector <string> edges) {
        ::n = n;
        G.assign(n, vector<int>());
        if (edges.size() > 0) {
            string e_ = edges[0];
            for (int i=1; i<(int)edges.size(); ++i) {
                e_ += edges[i];
            }

            vector<string> t = cutUp(e_, ",");
            
            for (int i=0; i<(int)t.size(); ++i) {
                int x, y;
                sscanf(t[i].c_str(), "%d %d", &x, &y);
                --x; --y;
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }

        memset(C, 0xff, sizeof C);
        int comp = 0;
        for (int i=0; i<n; ++i) {
            if (C[i] == -1) {
                dfs(i, comp++);
            }
        }

        int sol = 0;
        for (int c=0; c<comp; ++c) {
            bool ok = true;
            for (int i=0; i<n; ++i) {
                if (C[i] == c) {
                    memset(v, 0, sizeof v);
                    int j = cyc_next(i, i, -1);
                    if (j == -1) {
                        continue;
                    }
                    rem(i, j);
                    memset(v, 0, sizeof v);
                    if (cyc_next(i, i, -1) != -1) {
                        ok = false;
                    }
                    G[i].push_back(j);
                    G[j].push_back(i);
                    if (!ok) {
                        break;
                    }
                }
            }
            sol += ok;
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 2,1 3,2 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, countCacti(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, countCacti(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"1 2,3 4,4 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, countCacti(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 17; string Arr1[] = {"1 2,2 3,3 4,4 5,5 3,1 3,6 7,7 8,6 8,8 9,9 1",
 "0,10 11,11 9,12 13,14 15,15 16,16 17,14 17,14 16"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, countCacti(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CactusCount ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
