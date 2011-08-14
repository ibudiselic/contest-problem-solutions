#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> A;
long long dp[1<<15][100];
string to_str(long long x) {
    ostringstream os;
    os << x;
    return os.str();
}

int next[100][15];
int K;
long long go(int mask, int rem) {
    long long &ret = dp[mask][rem];
    if (ret != -1) {
        return ret;
    }
    if (mask == 0) {
        return ret = (rem == 0);
    }
    
    ret = 0;
    for (int i=0; i<(int)A.size(); ++i) {
        if ((mask>>i) & 1) {
            ret += go(mask ^ (1<<i), next[rem][i]);
        }
    }
    
    return ret;
}
class WickedTeacher {
	public:
	string cheatProbability(vector <string> numbers, int K) {
		memset(dp, 0xff, sizeof dp);
        A = numbers;
        ::K = K;
        
        for (int i=0; i<(int)numbers.size(); ++i) {
            for (int old=0; old<K; ++old) {
                int t = old;
                for (int j=0; j<(int)numbers[i].size(); ++j) {
                    t = (t*10 + numbers[i][j]-'0')%K;
                }
                next[old][i] = t;
            }
        }
        long long t = go((1<<(int)numbers.size())-1, 0);
        long long p = 1;
        for (int i=0; i<(int)numbers.size(); ++i) {
            p *= i + 1;
        }
        
        long long d = __gcd(t, p);
        t /= d;
        p /= d;
        
        return to_str(t) + "/" + to_str(p);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3","2","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "1/3"; verify_case(0, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"10","100","1000","10000","100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "1/1"; verify_case(1, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"11","101","1001","10001","100001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "0/1"; verify_case(2, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"13","10129414190271203","102","102666818896","1216","1217","1218","101278001","1000021412678412681"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arg2 = "5183/36288"; verify_case(3, Arg2, cheatProbability(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WickedTeacher ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
