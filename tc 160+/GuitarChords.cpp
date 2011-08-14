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

string note[] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };

vector<int> S, C;

bool done[6];
int sol;
int f[6];

int calc(const vector<int> &v) {
    bool zero = true;
    for (int i=0; i<(int)v.size(); ++i) {
        if (S[i] != C[v[i]]) {
            zero = false;
            break;
        }
    }
    if (zero) {
        return 0;
    }

    for (int i=0; i<(int)v.size(); ++i) {
        f[i] = (C[v[i]]-S[i] + 12) % 12;
    }

    int ret = 123456789;
    for (int m=0; m<(1<<(int)v.size()); ++m) {
        int a = 123456;
        int b = -123456;
        for (int i=0; i<(int)v.size(); ++i) {
            int t = f[i] + ((m >> i) & 1)*12;
            if (t == 0) {
                continue;
            }
            a = min(a, t);
            b = max(b, t);
        }
        ret = min(ret, b-a+1);
    }

    return ret;
}
    
void go(int s, vector<int> &v, int cmask) {
    if (s == (int)S.size()) {
        if (cmask+1 == (1<<C.size())) {
            sol = min(sol, calc(v));
        }
        return;
    }

    for (int i=0; i<(int)C.size(); ++i) {
        v[s] = i;
        go(s+1, v, cmask | (1<<i));
    }
}
class GuitarChords {
	public:
	int stretch(vector <string> strings, vector <string> chord) {
		map<string, int> M;
        for (int i=0; i<12; ++i) {
            M[note[i]] = i;
        }
        S.clear();
        C.clear();
        for (int i=0; i<(int)strings.size(); ++i) {
            S.push_back(M[strings[i]]);
        }
        for (int i=0; i<(int)chord.size(); ++i) {
            C.push_back(M[chord[i]]);
        }

        sol = 123456789;
        vector<int> v(S.size(), -1);
        go(0, v, 0);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "A", "C", "F" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "C#", "F#", "A#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, stretch(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "E", "A", "D", "G", "B", "E" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "E", "G#", "B" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, stretch(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "D#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "D#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, stretch(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "E", "F" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "F#", "D#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, stretch(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "C", "C", "C" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "C", "E", "G" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, stretch(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GuitarChords ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
