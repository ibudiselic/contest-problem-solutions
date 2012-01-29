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

int cost[50][50];
class MysteriousRestaurant {
	public:
	int maxDays(vector <string> prices, int budget) {
		int days = prices.size();
        int dishes = prices[0].size();
        for (int i=0; i<days; ++i) {
            for (int j=0; j<dishes; ++j) {
                if (prices[i][j] <= '9') {
                    cost[i][j] = prices[i][j] - '0';
                } else if (prices[i][j] <= 'Z') {
                    cost[i][j] = prices[i][j] - 'A' + 10;
                } else {
                    cost[i][j] = prices[i][j] - 'a' + 36;
                }
            }
        }
        
        for (int sol=days; sol>0; --sol) {
            bool ok = true;
            int have = budget;
            for (int i=0; i<7 && i<sol; ++i) {
                int best = 1234567890;
                for (int d=0; d<dishes; ++d) {
                    int price = 0;
                    int day = i;
                    while (day < sol) {
                        price += cost[day][d];
                        day += 7;
                    }
                    best = min(best, price);
                }
                if (have < best) {
                    ok = false;
                    break;
                }
                have -= best;
            }
            if (ok) {
                return sol;
            }
        }
        return 0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 5; verify_case(0, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06", "91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 8; verify_case(1, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"SRM", "512"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; int Arg2 = 10; verify_case(3, Arg2, maxDays(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MysteriousRestaurant ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
