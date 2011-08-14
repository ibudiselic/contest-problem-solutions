#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InstantRunoffVoting {
	public:
	int winner(vector <string> voters) {
        int left = voters[0].size();
        int n = voters.size();

        bool dead[10] = {0};
        while (left > 1) {
            vector<int> v(voters[0].size(), 0);
            int total = 0;
            for (int i=0; i<n; ++i) {
                for (int j=0; j<(int)voters[i].size(); ++j) {
                    if (!dead[voters[i][j]-'0']) {
                        ++v[voters[i][j]-'0'];
                        ++total;
                        break;
                    }
                }
            }

            int t = -1;
            int tt = 1234567;
            for (int i=0; i<(int)v.size(); ++i) {
                if (!dead[i]) {
                    tt = min(tt, v[i]);
                }
                if (!dead[i] && v[i]>t) {
                    t = v[i];
                }
            }

            if (t*2 > total) {
                return find(v.begin(), v.end(), t) - v.begin();
            }

            t = tt;
            for (int i=0; i<(int)v.size(); ++i) {
                if (!dead[i] && v[i]==t) {
                    dead[i] = 1;
                    --left;
                }
            }
        }

        return left==0 ? -1 : min_element(dead, dead+10)-dead;
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01","10","01","01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arr0[] = {"120","102","210","021","012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arr0[] = {"10","01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arr0[] = {"3120","3012","1032"
,"3120","2031","2103"
,"1230","1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { string Arr0[] = {"24103","30412","32014","21043","30412"
,"32401","14203","04123","30241","02413"
,"13042","01432","01342","32401","24301"
,"12430","41023","02413","42310","12043"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, winner(Arg0)); }
	void test_case_5() { string Arr0[] = {"0649853172","2146875039","2671548309"
,"5897216403","4719823056","7945213860"
,"9021538647","9286145307","9176403528"
,"3709486152"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, winner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InstantRunoffVoting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
