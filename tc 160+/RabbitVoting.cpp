#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

class RabbitVoting {
	public:
	string getWinner(vector <string> names, vector <string> votes) {
		map<string, int> v;
        for (int i=0; i<(int)names.size(); ++i) {
            if (names[i] != votes[i]) {
                ++v[votes[i]];
            }
        }
        vector< pair<int, string> > vv;
        for (map<string, int>::const_iterator it=v.begin(); it!=v.end(); ++it) {
            vv.push_back(make_pair(it->second, it->first));
        }
        if (vv.size() == 0) {
            return "";
        }
        sort(vv.begin(), vv.end());
        if (vv.size() == 1) {
            return vv[0].second;
        }
        if (vv.back().first != vv[vv.size()-2].first) {
            return vv.back().second;
        } else {
            return "";
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "Alice", "Bill", "Carol", "Dick" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Bill", "Dick", "Alice", "Alice" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice"; verify_case(0, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "Alice", "Bill", "Carol", "Dick" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Carol", "Carol", "Bill", "Bill" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(1, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "Alice", "Bill", "Carol", "Dick" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Alice", "Alice", "Bill", "Bill" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bill"; verify_case(2, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "Alice", "Bill" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Alice", "Bill" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(3, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "WhiteRabbit", "whiterabbit", "whiteRabbit", "Whiterabbit" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "whiteRabbit", "whiteRabbit", "whiteRabbit", "WhiteRabbit" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "whiteRabbit"; verify_case(4, Arg2, getWinner(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitVoting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
