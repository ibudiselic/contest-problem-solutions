#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <numeric>

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

int worst[100];
const int inf = 1234567890;

int dist[100];
int min_dist(int u, const vector< vector< pair<int, int> > > &G, bool special=false) {
    for (int i=0; i<100; ++i) {
        dist[i] = inf;
    }
    dist[u] = 0;
    priority_queue< pair<int, int> > Q;
    Q.push(make_pair(0, u));
    while (!Q.empty()) {
        const pair<int, int> t = Q.top();
        Q.pop();
        u = t.second;
        int d = -t.first;
        if (d > dist[u]) {
            continue;
        }
        for (int i=0; i<(int)G[u].size(); ++i) {
            const int v = G[u][i].first;
            const int c = G[u][i].second;
            int nd = d + c;
            if (special) {
                nd = max(nd, worst[v]);
            }
            if (nd < dist[v]) {
                dist[v] = nd;
                Q.push(make_pair(-nd, v));
            }
        }
    }
    
    return special ? dist[0] : dist[1];
}
class WarTransportation {
	public:
	int messenger(int n, vector <string> highways) {
		string s = accumulate(highways.begin(), highways.end(), string());
        vector<string> t = cutUp(s, ",");
        
        vector< vector< pair<int, int> > > G(n, vector< pair<int, int> >());
        for (int i=0; i<(int)t.size(); ++i) {
            int a, b, c;
            sscanf(t[i].c_str(), "%d %d %d", &a, &b, &c);
            G[a-1].push_back(make_pair(b-1, c));
        }
        
        worst[1] = 0;
        for (int i=0; i<n; ++i) {
            if (i == 1) {
                continue;
            }
            if (G[i].size() == 0) {
                worst[i] = inf;
            } else {
                worst[i] = 0;
                for (int j=0; j<(int)G[i].size(); ++j) {
                    const int real = G[i][j].second;
                    G[i][j].second = inf;
                    worst[i] = max(worst[i], min_dist(i, G));
                    G[i][j].second = real;
                }
            }
        }
        
        vector< vector< pair<int, int> > > G2(n, vector< pair<int, int> >());
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(int)G[i].size(); ++j) {
                G2[G[i][j].first].push_back(make_pair(i, G[i][j].second));
            }
        }
        
        int sol = min_dist(1, G2, true);
        return sol<inf ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 2 1,1 3 2,3 2 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, messenger(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; string Arr1[] = {"1 3 1,1 4 1,3 5 1,4 5 1,5 6 1,6 7 1,6 8 1,7 2 1,",
 "8 2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, messenger(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"1 3 1,1 3 2,3 2 1,1 4 1,4 2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, messenger(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"1 3 1,3 2 1,1 4 1,4 2 1,3 4 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, messenger(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 20; string Arr1[] = {"1 13 3,13 4 7,4 3 4,3 10 8,10 18 9,18 12 6,12 2 3,",
 "1 17 6,17 13 6,13 9 4,9 10 8,10 7 2,7 5 5,5 19 9,1",
 "9 14 6,14 16 9,16 18 7,18 15 5,15 20 3,20 12 9,12 ",
 "8 4,8 11 3,11 4 1,4 3 7,3 2 3,20 10 2,1 18 2,16 19",
 " 9,4 15 9,13 15 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(4, Arg2, messenger(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WarTransportation ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
