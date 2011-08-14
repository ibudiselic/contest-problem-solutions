#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const char dig[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int val[256];

struct Num {
    string repr;
    Num(const string &repr_="0"): repr(repr_) {}
    int size() const { return repr.size(); }
};
bool operator<(const Num &a, const Num &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a.repr < b.repr;
    }
}
const Num operator+(const Num &a, const Num &b) {
    string res;
    int len = max(a.size(), b.size());
    string x = a.repr;
    string y = b.repr;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    x += string(len-x.size(), '0');
    y += string(len-y.size(), '0');
    
    int c = 0;
    for (int i=0; i<len; ++i) {
        int d = val[x[i]] + val[y[i]] + c;
        res += dig[d%36];
        c = (d>=36);
    }
    if (c) {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return Num(res);
}

class HexatridecimalSum {
	public:
	string maximizeSum(vector <string> numbers, int k) {
        for (int i=0; i<36; ++i) {
            val[dig[i]] = i;
        }
        
        vector<Num> contrib(36);
        for (int i=0; i<(int)numbers.size(); ++i) {
            for (int j=0; j<(int)numbers[i].size(); ++j) {
                contrib[val[numbers[i][j]]] = contrib[val[numbers[i][j]]] + Num(string(1, dig[35-val[numbers[i][j]]]) + string(numbers[i].size()-1-j, '0'));
            }
        }
        
        vector< pair<Num, int> > v;
        for (int i=0; i<35; ++i) {
            v.push_back(make_pair(contrib[i], i));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        char ndig[256];
        for (int i=0; i<36; ++i) {
            ndig[dig[i]] = dig[i];
        }
        for (int i=0; i<min(k, 35); ++i) {
            ndig[dig[v[i].second]] = 'Z';
        }
        
        Num sol;
        random_shuffle(numbers.begin(), numbers.end());
        for (int i=0; i<(int)numbers.size(); ++i) {
            for (int j=0; j<(int)numbers[i].size(); ++j) {
                numbers[i][j] = ndig[numbers[i][j]];
            }
            sol = sol + numbers[i];
        }
        
        return sol.repr;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"HELLO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "ZZLLO"; verify_case(0, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arg2 = "1100TC85"; verify_case(1, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TO", "BE", "OR", "NOT", "TO", "BE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; string Arg2 = "QNO"; verify_case(2, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"KEQUALS36"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "ZZZZZZZZZ"; verify_case(3, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arg2 = "31YUB"; verify_case(4, Arg2, maximizeSum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HexatridecimalSum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
