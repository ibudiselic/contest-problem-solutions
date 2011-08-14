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

vector<int> E;
vector< vector<int> > covers;
map<int, int> M;
int N, sol;

bool valid(int mask) {
	for (int i=0; i<N; ++i)
		if (((mask >> (2*i)) & 3) == 3)
			return false;
	return true;
}
bool covered(int mask) {
	for (int i=0; i<N; ++i)
		if (((mask >> (2*i)) & 3) != 2)
			return false;
	return true;
}
int complement(int mask) {
	int ret = mask;
	for (int i=0; i<N; ++i)
		switch ((mask >> (2*i)) & 3) {
			case 0: ret |= (2<<(2*i)); break;
			case 1: break;
			case 2: ret ^= (2<<(2*i)); break;
			default: assert(0); break;
		}

	return ret;
}
int add(int mask, int e) {
	for (int i=0; i<(int)covers[e].size(); ++i) {
		const int t = covers[e][i];
		switch ((mask >> (2*t)) & 3) {
			case 0: mask |= (1<<(2*t)); break;
			case 1: mask ^= (3<<(2*t)); break;
			case 2: mask |= (1<<(2*t)); break;
			default: assert(0); break;
		}
	}
	return mask;
}
void go(int start, int end, int mask, int cost) {
	if (!valid(mask))
		return;
	if (start == end) {
		int &item = M[mask];
		if (item==0 || cost<item)
			item = cost;
		return;
	}

	go(start+1, end, mask, cost);
	go(start+1, end, add(mask, start), cost + E[start]);
}
void go2(int start, int end, int mask, int cost) {
	if (!valid(mask))
		return;
	if (start == end) {
		int comp = complement(mask);
		if (valid(comp) && M.count(comp))
			sol = min(sol, cost + M[comp]);
		return;
	}

	go2(start+1, end, mask, cost);
	go2(start+1, end, add(mask, start), cost + E[start]);
}
class OrderFood {
	public:
	int selectEntrees(vector <int> entrees, vector <string> favorites) {
		E = entrees;
		N = favorites.size();
		M.clear();

		covers.assign(entrees.size(), vector<int> ());
		for (int i=0; i<N; ++i) {
			istringstream is(favorites[i]);
			int x;

			while (is >> x)
				if (find(covers[x].begin(), covers[x].end(), i) == covers[x].end())
					covers[x].push_back(i);
		}

		if (entrees.size() <= 15) {
			go(0, entrees.size(), 0, 0);
			int sol = 1234567890;
			for (map<int, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
				if (covered(it->first))
					sol = min(sol, it->second);

			return sol < 1234567890 ? sol : -1;
		} else {
			go(0, entrees.size()/2, 0, 0);
			sol = 1234567890;
			go2(entrees.size()/2, entrees.size(), 0, 0);

			return sol < 1234567890 ? sol : -1;
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 150, 300, 425, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 3", "0 2 3 4", "0 3 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450; verify_case(0, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1", "1 2", "0 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 40, 80, 160, 320, 640}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 2 5", "0 2 6", "0 3 5", "1 3 6", "1 4", "1 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 310; verify_case(2, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 200, 300, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000, 90, 80, 70, 60, 50, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 2", "0 00 000 3 4", "0 5 6", "0 1 4", "0 2 5", "0 3 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 390; verify_case(4, Arg2, selectEntrees(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {  10124, 540045, 236111, 977928, 199927,
  379085, 743650, 631339, 961617, 178242,
  343492, 89869,   61858, 700029, 560602,
  341127, 850320, 957934, 167013, 631513}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4 16 16 2 18 10 13 14 4 18",
 "12 4 19 1 1 12 18 7 18",
 "6 15 19 13",
 "5 10 5 16 15 14 15 8",
 "13 2 15 8 5",
 "8 2 15 3 1",
 "9 18 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1792343; verify_case(5, Arg2, selectEntrees(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OrderFood ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
