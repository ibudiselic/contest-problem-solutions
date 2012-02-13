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

struct Seq {
    int lind, rind;
    long long cnt, len;
    string src;
    
    Seq(): lind(-1), rind(-1), cnt(0), len(0) {}
    Seq(const string &s): lind(-1), rind(-1), len(s.size()), src(s) {
        cnt = count(s.begin(), s.end(), '1');
    }
};

vector<Seq> V;

Seq join(const Seq &a, const Seq &b) {
    Seq ret;
    ret.len = a.len + b.len;
    ret.cnt = a.cnt + b.cnt;
    
    return ret;
}
Seq join(int i, int j) {
    Seq ret = join(V[i], V[j]);
    ret.lind = i;
    ret.rind = j;
    return ret;
}

Seq longest(int n, long long lo, long long hi) {
    assert(n < (int)V.size());
    Seq &seq = V[n];
    lo = max(lo, 0ll);
    hi = min(hi, seq.len);
    
    if (lo >= hi) {
        return Seq();
    }
    if (lo==0 && hi==seq.len) {
        return seq;
    }
    if (seq.src.size() > 0) {
        return Seq(seq.src.substr(lo, hi-lo));
    }
    assert(seq.lind!=-1 && seq.rind!=-1);
    return join(longest(seq.lind, lo, hi), longest(seq.rind, lo-V[seq.lind].len, hi-V[seq.lind].len));
}
class MagicalGirlLevelThreeDivTwo {
	public:
	int theCount(vector <string> first, int n, long long lo, long long hi) {
	    V.clear();
        int K = first.size();
        for (int i=0; i<K; ++i) {
            V.push_back(Seq(first[i]));
        }
        V.push_back(V.back());
        int i = K + 1;
        while (hi >= V.back().len) {
            if (i < 2*K) {
                V.push_back(join(i-1, i-1-K));
            } else {
                V.push_back(join(i-1, i-K));
            }
            ++i;
        }
        
        return longest(min(n, i-1), lo, hi+1).cnt;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101", "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 5LL; int Arg4 = 2; verify_case(0, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 4LL; long long Arg3 = 5LL; int Arg4 = 1; verify_case(1, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 1001; verify_case(2, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 0; verify_case(3, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"00110110101101001111101101001011010011111011010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 999999999999915LL; long long Arg3 = 1000000000000000LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; long long Arg2 = 123456LL; long long Arg3 = 123654LL; int Arg4 = 76; verify_case(5, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicalGirlLevelThreeDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
