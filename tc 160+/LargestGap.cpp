#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> solve(string s, int p) {
    int q = p;
    while (q<(int)s.size() && s[q]=='X') {
        s[q] = '*';
        ++q;
    }

    if (q == (int)s.size()) {
        if (s[0] == 'X') {
            return vector<int> (1, -2);
        }
        for (int i=0; i<(int)s.size() && s[i]=='X'; ++i) {
            s[i] = '*';
        }
    }

    if (p == 0) {
        for (int i=(int)s.size()-1; i>=0 && s[i]=='X'; --i) {
            s[i] = '*';
        }
    }

    vector<int> v;
    for (int i=0; i<(int)s.size(); ++i) {
        if (s[i] != 'X') {
            int sz = 0;
            if (i == 0) {
                for (int j=(int)s.size()-1; j>=0 && s[j]!='X'; --j) {
                    if (s[j] == '.') {
                        ++sz;
                        s[j] = '*';
                    }
                }
            }
            while (i<(int)s.size() && s[i]!='X') {
                if (s[i] == '.') {
                    ++sz;
                    s[i] = '*';
                }
                ++i;
            }
            v.push_back(sz);
        }
    }
    if (v.back() == 0) {
        v.pop_back();
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    return v;
}

class LargestGap {
	public:
	int getLargest(vector <string> board) {
		string s = board[0];
        for (int i=1; i<(int)board.size(); ++i) {
            s += board[i];
        }

        vector<int> best(1, -1);
        int sol = -1;
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i] == 'X') {
                vector<int> t = solve(s, i);
                if (t > best) {
                    best = t;
                    sol = i;
                }
                while (i<(int)s.size() && s[i]=='X') {
                    ++i;
                }
                --i;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....X.X......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXX","....","XXXX","....","XXXX","...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXX.........XX...........XX..X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LargestGap ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
