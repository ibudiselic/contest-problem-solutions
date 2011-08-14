#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Desertification {
	public:
	int desertArea(vector <string> island, int T) {
		bool has_desert = false;
        for (int i=0; i<(int)island.size(); ++i) {
            for (int j=0; j<(int)island[i].size(); ++j) {
                if (island[i][j] == 'D') {
                    has_desert = true;
                    goto DONE;
                }
            }
        }
        DONE:;
        if (!has_desert) {
            return 0;
        }
        if (T >= (int)island.size() + island[0].size()) {
            return island.size() * island[0].size();
        }
        vector<string> next = island;        
        while (T--) {
            for (int i=0; i<(int)island.size(); ++i) {
                for (int j=0; j<(int)island[i].size(); ++j) {
                    if (island[i][j] == 'D') {
                        for (int di=-1; di<2; ++di) {
                            for (int dj=-1; dj<2; ++dj) {
                                if (abs(di) + abs(dj) == 1) {
                                    const int r = i + di;
                                    const int c = j + dj;
                                    if (r<0 || c<0 || r>=(int)island.size() || c>=(int)island[0].size()) {
                                        continue;
                                    }
                                    next[r][c] = 'D';
                                }
                            }
                        }
                    }
                }
            }
            island.swap(next);
        }
        
        int sol = 0;
        for (int i=0; i<(int)island.size(); ++i) {
            for (int j=0; j<(int)island[i].size(); ++j) {
                sol += (island[i][j] == 'D');
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"FFF",
 "FDF",
 "FFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; verify_case(0, Arg2, desertArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"FFF",
 "FDF",
 "FFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 9; verify_case(1, Arg2, desertArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"FFFFF",
 "FFDFF",
 "FFFFD",
 "FFFFF",
 "FFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 17; verify_case(2, Arg2, desertArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"FFFFFF",
 "FFFFFF",
 "FFFFFF",
 "FFFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 0; verify_case(3, Arg2, desertArea(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF", 
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 90; verify_case(4, Arg2, desertArea(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF", 
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 98765432; int Arg2 = 100; verify_case(5, Arg2, desertArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Desertification ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
