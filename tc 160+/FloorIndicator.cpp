#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string D[10][5] = { 
    {"###", "#.#", "#.#", "#.#", "###"},
    {"..#", "..#", "..#", "..#", "..#"},
    {"###", "..#", "###", "#..", "###"},
    {"###", "..#", "###", "..#", "###"},
    {"#.#", "#.#", "###", "..#", "..#"},
    {"###", "#..", "###", "..#", "###"},
    {"###", "#..", "###", "#.#", "###"},
    {"###", "..#", "..#", "..#", "..#"},
    {"###", "#.#", "###", "#.#", "###"},
    {"###", "#.#", "###", "..#", "###"},
};

vector<string> A;
int N;
bool done[10][10];
bool poss[10][10];
bool possible(int pos, int d) {
    if (pos == N) {
        return true;
    }
    if (done[pos][d]) {
        return poss[pos][d];
    }
    done[pos][d] = 1;
    int start = pos*4;
    for (int i=0; i<5; ++i) {
        for (int j=0; j<3; ++j) {
            if (A[i][start+j]=='#' && D[d][i][j]=='.') {
                return (poss[pos][d] = false);
            }
        }
    }
    
    return (poss[pos][d] = true);
}

long long C[10][10];
long long S[10][10];

long long cnt(int pos, int d) {
    long long &ret = C[pos][d];
    if (ret != -1) {
        return ret;
    }
    if (pos == N) {
        return (ret = 1);
    }
    ret = 0;
    for (int d2=0; d2<10; ++d2) {
        if (possible(pos+1, d2)) {
            ret += cnt(pos+1, d2);
        }
    }
    return ret;
}

long long digval(int n) {
    long long ret = 1;
    while (n--) {
        ret *= 10;
    }
    return ret;
}
long long sum(int pos, int d) {
    long long &ret = S[pos][d];
    if (ret != -1) {
        return ret;
    }
    if (pos == N) {
        return (ret = 0);
    }
    ret = 0;
    long long sub_cnt = 0;
    for (int d2=0; d2<10; ++d2) {
        if (possible(pos+1, d2)) {
            sub_cnt += cnt(pos+1, d2);
            ret += sum(pos+1, d2);
        }
    }
    
    ret += d * sub_cnt * digval(N-pos-1);
    return ret;
}
        
class FloorIndicator {
	public:
	double averageFloor(int N, vector <string> indicator) {
        A = indicator;
        ::N = N;
        memset(done, 0, sizeof done);
        memset(C, 0xff, sizeof C);
        memset(S, 0xff, sizeof S);
        
        long long tot = 0;
        long long t_cnt = 0;
        for (int i=0; i<10; ++i) {
            if (possible(0, i)) {
                tot += sum(0, i);
                t_cnt += cnt(0, i);
            }
        }
        
        return (t_cnt ? double(tot)/t_cnt : -1);
	}

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = {"###",
 "#.#",
 "###",
 "#.#",
 "###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(0, Arg2, averageFloor(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"###.###",
 "#.#.#.#",
 "#.#.###",
 "#.#...#",
 "###.###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 48.5; verify_case(1, Arg2, averageFloor(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = {".......",
 ".......",
 ".......",
 ".......",
 "......."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 49.5; verify_case(2, Arg2, averageFloor(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; string Arr1[] = {"...",
 ".#.",
 "...",
 "...",
 "..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(3, Arg2, averageFloor(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FloorIndicator ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
