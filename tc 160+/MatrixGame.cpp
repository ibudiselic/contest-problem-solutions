#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> T(const vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    vector<string> ret(n, string(m, ' '));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}
class MatrixGame {
	public:
	vector <string> getMinimal(vector <string> matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<string> sol = matrix;
		sort(matrix.begin(), matrix.end());
        do {
            vector<string> t = T(matrix);
            sort(t.begin(), t.end());
            sol = min(sol, T(t));
        } while (next_permutation(matrix.begin(), matrix.end()));
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000", "000", "000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinimal(Arg0)); }
	void test_case_1() { string Arr0[] = {"010",
 "000",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000", "001", "011" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinimal(Arg0)); }
	void test_case_2() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111", "111", "111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinimal(Arg0)); }
	void test_case_3() { string Arr0[] = {"01010",
 "10101",
 "01010",
 "10101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011", "00011", "11100", "11100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinimal(Arg0)); }
	void test_case_4() { string Arr0[] = {"11010100",
 "11110001",
 "00011101",
 "11111111",
 "01110100",
 "10000110",
 "00001001",
 "11010111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000011", "00001111", "00110100", "01011100", "01111101", "11001100", "11011001", "11111111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getMinimal(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MatrixGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
