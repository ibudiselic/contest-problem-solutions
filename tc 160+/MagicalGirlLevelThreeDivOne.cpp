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

struct Seq;
vector<Seq> V;

struct Seq {
    int lind, rind;
    long long left, right, any, len;
    string src;
    Seq(): lind(-1), rind(-1), left(0), right(0), any(0), len(0) {}
    Seq(const string &s): lind(-1), rind(-1), len(s.size()), src(s) {
        left = 0;
        int i = 0;
        while (i<len && s[i]=='1') {
            ++left;
            ++i;
        }
        right = 0;
        i = len-1;
        while (i>=0 && s[i]=='1') {
            ++right;
            --i;
        }
        
        any = max(left, right);
        for (i=left+1; i+any<len-right; ++i) {
            int j = i;
            while (s[j] == '1') {
                ++j;
            }
            any = max<long long>(any, j - i);
        }
    }
    
};

Seq join(const Seq &a, const Seq &b) {
    Seq ret;

    ret.len = a.len + b.len;
    ret.left = (a.left < a.len) ? a.left : a.len + b.left;
    ret.right = (b.right < b.len) ? b.right : b.len + a.right;
    ret.any = max(ret.left, ret.right);
    ret.any = max(ret.any, max(a.any, b.any));
    ret.any = max(ret.any, a.right + b.left);
    return ret;
}

Seq join(int l, int r) {
    Seq ret = join(V[l], V[r]);
    ret.lind = l;
    ret.rind = r;
    return ret;
}

Seq longest(int n, long long lo, long long hi) {
    assert(n < (int)V.size());
    Seq &seq = V[n];
    lo = max(lo, 0ll);
    hi = min(hi, seq.len-1);
    
    if (lo > hi) {
        return Seq();
    } else if (lo==0 && hi==seq.len-1) {
        return seq;
    } else if (seq.src.size() > 0) {
        return Seq(seq.src.substr(lo, hi-lo+1));
    } else {
        assert(seq.lind>=0 && seq.rind>=0);
        return join(longest(seq.lind, lo, hi), longest(seq.rind, lo-V[seq.lind].len, hi-V[seq.lind].len));
    }
}

class MagicalGirlLevelThreeDivOne {
	public:
	long long theMaxPower(vector <string> first, int n, long long lo, long long hi) {
		int K = first.size();
        V.clear();
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
        
        return longest(min((int)V.size()-1, n), lo, hi).any;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111", "011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 7LL; long long Arg4 = 4LL; verify_case(0, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456789; long long Arg2 = 123456789LL; long long Arg3 = 123456789012345LL; long long Arg4 = 123456665555557LL; verify_case(1, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; long long Arg2 = 987654321LL; long long Arg3 = 987654321054321LL; long long Arg4 = 0LL; verify_case(2, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1110", "11", "11111", "111", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 314159265; long long Arg2 = 271828182845904LL; long long Arg3 = 314159265358979LL; long long Arg4 = 15LL; verify_case(3, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long long Arg2 = 1000000000000000LL; long long Arg3 = 1000000000000000LL; long long Arg4 = 1LL; verify_case(4, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicalGirlLevelThreeDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
