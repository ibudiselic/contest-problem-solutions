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

long long INF;
map< pair<int, long long> , long long> M;
long long same[51];
string S;
int N, D;
long long encode(const string &s) {
    int used[26] = {0};
    int ind = 1;
    int start = max(0, (int)s.size()-N);
    for (int i=start; i<(int)s.size(); ++i) {
        if (!used[s[i]-'a']) {
            used[s[i]-'a'] = ind++;
        }
    }
    if (ind > D+1) {
        return -1;
    }
    memset(used, 0, sizeof used);
    ind = 1;
    if ((int)s.size() >= N) {
        ++start;
    }
    for (int i=start; i<(int)s.size(); ++i) {
        if (!used[s[i]-'a']) {
            used[s[i]-'a'] = ind++;
        }
    }
    long long code = 0;
    for (int i=(int)s.size()-1; i>=start; --i) {
        code = code*10 + used[s[i]-'a']-1;
    }
    return code;
}
long long count_with_prefix(const string &);
long long count_with_prefix(long long code, const string &s) {
    const pair<int, long long> p(int(s.size()), code);
    if (M.count(p)) {
        return M[p];
    }
    long long &ret = M[p];
    assert(s.size() < S.size());
    int used[26] = {0};
    int ind = 1;
    int start = max(0, (int)s.size()-N+1);
    for (int i=start; i<(int)s.size() && ret<INF; ++i) {
        if (!used[s[i]-'a']) {
            ret += count_with_prefix(s + string(1, s[i]));
            used[s[i]-'a'] = ind++;
        }
    }
    if (ret >= INF) {
        return (ret = INF);
    }
    int cnt = 27 - ind;
    for (int i=0; i<26; ++i) {
        if (!used[i]) {
            long long t = count_with_prefix(s + string(1, 'a' + i));
            if (t >= INF) {
                return (ret = INF);
            } else {
                ret += cnt*t;
                break;
            }
        }
    }
    
    if (ret >= INF) {
        return (ret = INF);
    }
    
    return ret;
}
long long count_with_prefix_same(int sz) {
    long long &ret = same[sz];
    if (ret != -1) {
        return ret;
    }
    assert(sz < (int)S.size());
    ret = count_with_prefix(S.substr(0, sz+1));
    for (int i=S[sz]+1; i<='z' && ret<INF; ++i) {
        ret += count_with_prefix(S.substr(0, sz) + string(1, i));
    }
    ret = min(ret, INF);
    
    return ret;
}
    
long long count_with_prefix(const string &s) {
    assert(s >= S.substr(0, s.size()));
    long long code = encode(s);
//    cerr << s << ' ' << code << '\n';
    if (code == -1) {
        return 0;
    }
    if (s.size() == S.size()) {
        return 1;
    }
    if (s == S.substr(0, s.size())) {
        return count_with_prefix_same(s.size());
    } else {
        return count_with_prefix(code, s);
    }
}
        
class NextHomogeneousStrings {
	public:
	string getNext(int d, int n, string seed, long long k) {
		INF = k + 1;
        N = n;
        D = d;
        S = seed;
        M.clear();
        memset(same, 0xff, sizeof same);
        string sol;
        bool any = false;
        for (int i=0; i<(int)seed.size(); ++i) {
            int start = any ? 0 : seed[i]-'a';
            long long t = count_with_prefix(sol + string(1, start+'a'));
//            cerr << sol + string(1, start+'a') << ' ' << t << '\n';
            if (t > k) {
                sol += char(start+'a');
            } else {
                k -= t;
                ++start;
                bool ok = false;
                for (int i=start; i<26; ++i) {
                    t = count_with_prefix(sol + string(1, i+'a'));
//                    cerr << sol + string(1, i+'a') << ' ' << t << '\n';
                    if (t > k) {
                        sol += char(i + 'a');
                        ok = true;
                        break;
                    } else {
                        k -= t;
                    }
                }
                if (!ok) {
                    return "";
                }
                any = true;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; string Arg2 = "aaa"; long long Arg3 = 3LL; string Arg4 = "ddd"; verify_case(0, Arg4, getNext(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "abc"; long long Arg3 = 0LL; string Arg4 = "aca"; verify_case(1, Arg4, getNext(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 4; string Arg2 = "ttrrzz"; long long Arg3 = 6LL; string Arg4 = "ttsssc"; verify_case(2, Arg4, getNext(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 8; string Arg2 = "txyaaxaassaaaarghjsdohasdghususdidisisdodo"; long long Arg3 = 10000000000000000LL; string Arg4 = "txyaaxaassaaaarghjsgaaaaaaaaadntffiniqrddy"; verify_case(3, Arg4, getNext(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 5; string Arg2 = "zzzzzaa"; long long Arg3 = 100LL; string Arg4 = ""; verify_case(4, Arg4, getNext(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NextHomogeneousStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
