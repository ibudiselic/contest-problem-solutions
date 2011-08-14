#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long best[51];
class TeleportAndLoader {
	public:
	int cheapTransportation(vector <int> boxes, int teleport_cost, int loader_cost) {
		boxes.push_back(0);
		sort(boxes.begin(), boxes.end());

		best[0] = 0;
		for (int i=0; i<(int)boxes.size(); ++i)
			best[0] += loader_cost*boxes[i];

		for (int topTel=1; topTel<(int)boxes.size(); ++topTel) {
			best[topTel] = 1234567890123456789LL;
			for (int lastTel=0; lastTel<topTel; ++lastTel) {
				long long cost = best[lastTel] + teleport_cost;
				for (int i=lastTel+1; i<(int)boxes.size(); ++i) {
					long long lastDist = boxes[i]-boxes[lastTel];
					long long topDist = abs(boxes[i]-boxes[topTel]);

					cost -= lastDist*loader_cost;
					cost += min(lastDist, topDist) * loader_cost;
				}
				best[topTel] = min(best[topTel], cost);
			}
		}

		return *min_element(best, best+(int)boxes.size());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; int Arg2 = 1; int Arg3 = 15; verify_case(0, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1000, 40, 50, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 10; int Arg3 = 600; verify_case(1, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 10, 254, 987, 1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1000; int Arg3 = 5; verify_case(2, Arg3, cheapTransportation(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TeleportAndLoader ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
