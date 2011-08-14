#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

string to_str(int x) {
    ostringstream os;
    os << ' ' << x;
    return os.str();
}
class ErdosNumber {
	public:
	vector <string> calculateNumbers(vector <string> publications) {
        vector< vector<string> > S(publications.size(), vector<string>());
        map<string, int> M;
        
        for (int i=0; i<(int)publications.size(); ++i) {
            string s;
            istringstream is(publications[i]);
            while (is >> s) {
                S[i].push_back(s);
            }
        }
        
        M["ERDOS"] = 0;
        bool change = true;
        while (change) {
            change = false;
            map<string, int> mt = M;
            for (int i=0; i<(int)S.size(); ++i) {
                int val = 123456789;
                for (int j=0; j<(int)S[i].size(); ++j) {
                    if (mt.count(S[i][j])) {
                        val = min(val, mt[S[i][j]]);
                    }
                }
                if (val < 123456789) {
                    for (int j=0; j<(int)S[i].size(); ++j) {
                        if (!M.count(S[i][j])) {
                            M[S[i][j]] = val + 1;
                            change = true;
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<(int)S.size(); ++i) {
            for (int j=0; j<(int)S[i].size(); ++j) {
                if (!M.count(S[i][j])) {
                    M[S[i][j]] = -1;
                }
            }
        }
        
        vector<string> sol;
        for (map<string, int>::const_iterator it=M.begin(); it!=M.end(); ++it) {
            sol.push_back(it->first + (it->second>=0 ? to_str(it->second) : ""));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ERDOS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calculateNumbers(Arg0)); }
	void test_case_1() { string Arr0[] = {"KLEITMAN LANDER", "ERDOS KLEITMAN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calculateNumbers(Arg0)); }
	void test_case_2() { string Arr0[] = {"ERDOS A", "A B", "B AA C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calculateNumbers(Arg0)); }
	void test_case_3() { string Arr0[] = {"ERDOS B", "A B C", "B A E", "D F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calculateNumbers(Arg0)); }
	void test_case_4() { string Arr0[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, calculateNumbers(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ErdosNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
