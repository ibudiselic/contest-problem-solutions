#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool can1(int i, int j, const vector<string> &A) {
    if (i+1 >= (int)A.size() || j+3>=(int)A[0].size()) {
        return false;
    }
    if (A[i][j+3] != 'X') {
        return false;
    }
    ++i;
    for (int dj=0; dj<4; ++dj) {
        if (A[i][j+dj] != 'X') {
            return false;
        }
    }
    
    return true;
}
void put1(int i, int j, vector<string> &A) {
    A[i][j] = 'A';
    A[i][j+3] = 'A';
    ++i;
    for (int dj=0; dj<4; ++dj) {
        A[i][j+dj] = 'A';
    }
}
void unput1(int i, int j, vector<string> &A) {
    A[i][j] = 'X';
    A[i][j+3] = 'X';
    ++i;
    for (int dj=0; dj<4; ++dj) {
        A[i][j+dj] = 'X';
    }
}

bool can2(int i, int j, const vector<string> &A) {
    return j+1<(int)A[0].size() && A[i][j+1]=='X';
}
void put2(int i, int j, vector<string> &A) {
    A[i][j] = 'B';
    A[i][j+1] = 'B';
}
void unput2(int i, int j, vector<string> &A) {
    A[i][j] = 'X';
    A[i][j+1] = 'X';
}

bool valid(vector<string> A) {
    int m = A.size();
    int n = A[0].size();
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == 'X') {
                if (can2(i, j, A)) {
                    put2(i, j, A);
                } else if (can1(i, j, A)) {
                    put1(i, j, A);
                } else {
                    return false;
                }
            }
        }
    }
    
    return true;
}
    
class SpecificPolyominoCovering {
	public:
	vector <string> findCovering(vector <string> region) {
		int m = region.size();
        int n = region[0].size();
        
        if (!valid(region)) {
            return vector<string>();
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (region[i][j] == 'X') {
                    if (can1(i, j, region)) {
                        put1(i, j, region);
                        if (!valid(region)) {
                            unput1(i, j, region);
                            if (can2(i, j, region)) {
                                put2(i, j, region);
                                if (!valid(region)) {
                                    return vector<string>();
                                }
                            } else {
                                return vector<string>();
                            }
                        }
                    } else if (can2(i, j, region)) {
                        put2(i, j, region);
                        if (!valid(region)) {
                            return vector<string>();
                        }
                    } else {
                        return vector<string>();
                    }
                }
            }
        }
        
        return region;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"XXXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABBA", "AAAA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findCovering(Arg0)); }
	void test_case_1() { string Arr0[] = {"X..XXXX..X",
 "XXXX..XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A..ABBA..A", "AAAA..AAAA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findCovering(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXX",
 "XXXXXX",
 "XXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABBABB", "AAAABB", "BBBBBB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findCovering(Arg0)); }
	void test_case_3() { string Arr0[] = {"X..XX",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findCovering(Arg0)); }
	void test_case_4() { string Arr0[] = {"XXXXXXXXXX",
 "XXXXXXXXXX",
 "XXXXXXXXXX",
 "XXXXX..XXX",
 "XXXXXXXXXX",
 "XXXXXXXXXX",
 "XXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABBAABBABB", "AAAAAAAABB", "ABBABBBBBB", "AAAAA..ABB", "ABBAAAAABB", "AAAAABBABB", "BBBBAAAABB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findCovering(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SpecificPolyominoCovering ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
