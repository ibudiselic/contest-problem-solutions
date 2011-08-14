#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string encode(int row, int n) {
    string ret(n, 'B');
    for (int i=0; i<n; ++i) {
        if (row & (1<<i)) {
            ret[i] = 'W';
        }
    }
    return ret;
}

bool can_do(const vector<string> &output, int m, int n, int mm, int row) {
    assert(mm > 0);
    string t = encode(row, n);
    for (int j=0; j<n-1; ++j) {
        bool Aw = (output[mm-1][j]=='W');
        bool Bw = (output[mm-1][j+1]=='W');
        if (Aw && Bw) {
            ;
        } else if (!Aw && Bw) {
            t[j] = t[j+1] = 'B';
        } else if (Aw && !Bw) {
            t[j] = t[j+1] = 'W';
        } else {
            swap(t[j], t[j+1]);
        }
    }
    return t == output[mm];
}
class Algrid {
	public:
	vector <string> makeProgram(vector <string> output) {
		int m = output.size();
        int n = output[0].size();
        if (m == 1) {
            return output;
        }
        
        vector<string> sol(m, string());
        sol[0] = output[0];
        for (int i=1; i<m; ++i) {
            int row = 0;
            bool ok = false;
            while (!ok && row<(1<<n)) {
                if (can_do(output, m, n, i, row)) {
                    ok = true;
                    break;
                }
                ++row;
            }
            if (!ok) {
                return vector<string>();
            }
            sol[i] = encode(row, n);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"WWWWWWW",
 "WWWWWWB",
 "BBBBBWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WWWWWWW", "WWWWWWB", "BBBBBBB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBB",
 "WBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BBBBB", "WWBWB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBWB",
 "WWBB",
 "BWBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBBBBW",
 "BWBBWBB",
 "BWBBWBW",
 "BWWBWBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeProgram(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Algrid ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
