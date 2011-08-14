#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

vector<string> W;
struct Part {
    int a, b;
    Part(int a_, int b_): a(a_), b(b_) {}
};
bool operator<(const Part &x, const Part &y) {
    if (x.a==y.a && x.b==y.b) {
        return false;
    }
    const int len = x.b-x.a+1;
    for (int i=0; i<len; ++i) {
        if (W[x.a+i] != W[y.a+i]) {
            return W[x.a+i] < W[y.a+i];
        }
    }
    return false;
}

int cnt(int K) {
    set<Part> S;
    for (int i=0; i+K<=(int)W.size(); ++i) {
        S.insert(Part(i, i+K-1));
    }
    return S.size();
}
    
class BoredPhilosophers {
	public:
	vector <int> simulate(vector <string> text, int N) {
		vector<int> sol;
        sol.reserve(N);
        
        string s = text[0];
        for (int i=1; i<(int)text.size(); ++i) {
            s += text[i];
        }
        W = cutUp(s);
        for (int i=0; i<N; ++i) {
            sol.push_back(cnt(i+1));
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"hello world"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, simulate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"aaa bbb aaa bbb aaa aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {2, 3, 3, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, simulate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"remember"," t","o concatenate ","the"," ","text"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, simulate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a a a a a a a b a a b a a a b b a b a a a b a b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {2, 4, 7, 11, 14, 17 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, simulate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"aa ababaa c cbbcbc cabcbcb ba bccc ababb",
 "c cabcba caa ababaa c cbbcbc cabcbcb ba ",
 "bccc ababbc cabcba c bbcbab",
 "b aaaa cbccaaa bccc ababbc cabcba c bbcb",
 "ab cbcaca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {15, 17, 18, 19, 20, 20, 20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BoredPhilosophers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
