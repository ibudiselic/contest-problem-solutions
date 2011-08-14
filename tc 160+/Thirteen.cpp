#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int n;
int G[50][50];
const int INF = 987654321;
int get_val(char c) {
    if (c == '#') {
        return INF;
    } else if (c <= 'Z') {
        return c - 'A' + 1;
    } else {
        return c - 'a' + 27;
    }
}

int best[50][13];
int done[50][13];
class Thirteen {
	public:
	int calcTime(vector <string> city) {
		n = city.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = get_val(city[i][j]);
            }
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<13; ++j) {
                best[i][j] = INF;
            }
        }
        best[0][0] = 0;
        memset(done, 0, sizeof done);
        priority_queue< pair<int, int> > PQ;
        PQ.push(make_pair(0, 0));
        while (!PQ.empty()) {
            int t = -PQ.top().first;
            int p = PQ.top().second;
            PQ.pop();
            
            if (done[p][t%13]) {
                continue;
            }
            done[p][t%13] = true;

            if (p == n-1) {
                return t;
            }
            
            for (int q=0; q<n; ++q) {
                int nt = t+G[p][q];
                if (nt>=INF || nt%13==0) {
                    continue;
                }
                if (best[q][nt%13] > nt) {
                    best[q][nt%13] = nt;
                    PQ.push(make_pair(-nt, q));
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, calcTime(Arg0)); }
	void test_case_1() { string Arr0[] = { "#Z",
  "Z#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, calcTime(Arg0)); }
	void test_case_2() { string Arr0[] = { "#A#C##",
  "##FA#K",
  "###D#D",
  "A###A#",
  "##C###",
  "####A#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, calcTime(Arg0)); }
	void test_case_3() { string Arr0[] = { "Good#####",
  "#Luck####",
  "##and####",
  "##Have###",
  "####Fun##",
  "#####in##",
  "#####the#",
  "CHALLENGE",
  "##PHASE##" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 137; verify_case(3, Arg1, calcTime(Arg0)); }
	void test_case_4() { string Arr0[] = { "###No#####",
  "####Zaphod",
  "#####Just#",
  "######very",
  "####very##",
  "improbable",
  "##########",
  "##########",
  "##########",
  "##########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 103; verify_case(4, Arg1, calcTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Thirteen ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
