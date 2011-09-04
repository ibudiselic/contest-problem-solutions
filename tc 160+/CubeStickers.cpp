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

class CubeStickers {
	public:
	string isPossible(vector <string> stickers) {
		sort(stickers.begin(), stickers.end());
        vector<int> cnt;
        stickers.push_back("ZZZZZ");
        int cur = 0;
        for (int i=0; i+1<(int)stickers.size(); ++i) {
            if (stickers[i] != stickers[i+1]) {
                cnt.push_back(cur + 1);
                cur = 0;
            } else {
                ++cur;
            }
        }
        sort(cnt.begin(), cnt.end());
        if (cnt.size() < 3) {
            return "NO";
        }
        reverse(cnt.begin(), cnt.end());
        int got = 0;
        for (int i=0; i<(int)cnt.size(); ++i) {
            if (cnt[i] >= 2) {
                got += 2;
            } else {
                got += 1;
            }           
        }
        
        return got >= 6 ? "YES" : "NO";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"purple","orange","orange","purple","black","orange","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { string Arr0[] = {"white","gray","green","blue","yellow","red","target","admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, isPossible(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeStickers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
