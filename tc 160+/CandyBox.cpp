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

int N;
vector<int> score;
int C;
double c;

bool done[101][10001];
double dp[101][10001];
double go(int have, int moves) {
    if (done[have][moves]) {
        return dp[have][moves];
    }
    double &ret = dp[have][moves];
    done[have][moves] = 1;
    if (moves == 0) {
        return (ret = (have==C ? 1.0 : 0.0));
    }
    
    double h = have;
    double t = 2*h/N*(N-c-(c-h))/(N-1) + 2*(c-h)/N*(c-h)/(N-1);
    ret = (1-t)*go(have, moves-1);
    if (have < C) {
        h = have + 1.0;
        ret += 2*h/N*(N-c-(c-h))/(N-1) * go(have+1, moves-1); // same kind in my box <-> other kind outside my box
    }
    if (have > 0) {
        h = have - 1.0;
        ret += 2*(c-h)/N*(c-h)/(N-1) * go(have-1, moves-1); // other kind in my box <-> same kind outside my box
    }
    
    return ret;
}

class CandyBox {
	public:
	vector <double> expectedScore(int C_, vector <int> score_, int S) {
		C = C_;
        c = C;
        score = score_;
        int n = score.size();
        N = C * n;
        if (n == 1) {
            return vector<double> (1, score[0]);
        }
        
        double total = accumulate(score.begin(), score.end(), 0.0);
        memset(done, 0, sizeof done);
        vector<double> sol(n, 0.0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=C; ++j) {
                sol[i] += go(j, S) * (j*score[i] + (C-j)*(total-score[i])/(n-1.0)) / C;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; double Arr3[] = {1.0, 10.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, expectedScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; double Arr3[] = {4.0, 7.000000000000001 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, expectedScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1, 4, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; double Arr3[] = {5.0, 5.0, 5.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, expectedScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98; int Arr1[] = {13, 82, 74, 78, 12, 71, 81, 80, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 154; double Arr3[] = {26.25622829378155, 74.87969915903301, 69.24219529059805, 72.06094722481552, 25.551540310227182, 67.12813133993495, 74.17501117547864, 73.47032319192427, 38.23592401420582 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, expectedScore(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CandyBox ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
