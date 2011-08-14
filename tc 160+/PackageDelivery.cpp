#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> P;
int WC, FC, PC, TC;
struct State {
	bool p;
	int pos, nd, nl;
	long long c;
	State(bool p_, int pos_, int nd_, int nl_, long long c_): p(p_), pos(pos_), nd(nd_), nl(nl_), c(c_) {}
};
bool operator<(const State &a, const State &b) {
	if (a.c != b.c)
		return a.c > b.c;
	else if (a.p != b.p)
		return a.p == false;
	else if (a.pos != b.pos)
		return a.pos < b.pos;
	else if (a.nd != b.nd)
		return a.nd < b.nd;
	else
		return a.nl < b.nl;
}
long long best[52][52][52][2]; // position, nextToDeliver, nextToLoad, isParked

long long pfs() {
	priority_queue<State> PQ;
	PQ.push(State(true, 0, 1, 1, 0));

	while (!PQ.empty()) {
		bool isParked = PQ.top().p;
		int pos = PQ.top().pos;
		int nextToDeliver = PQ.top().nd;
		int nextToLoad = PQ.top().nl;
		long long cost = PQ.top().c;
		PQ.pop();

		if (nextToDeliver == (int)P.size())
			return cost;

		if (best[pos][nextToDeliver][nextToLoad][isParked] < cost)
			continue;

		//cerr << pos << ' ' << nextToDeliver << ' ' << nextToLoad << ' ' << cost << ' ' << isParked << '\n';

		best[pos][nextToDeliver][nextToLoad][isParked] = cost;

		if (pos==0 && nextToLoad-nextToDeliver<TC) {
			// load up (no cost)
			int newLoad = nextToLoad + 1;
			cerr << pos << ' ' << nextToDeliver << ' ' << nextToLoad << ' ' << cost << ' ' << isParked << '\n';
			if (best[0][nextToDeliver][newLoad][true] > cost) {
				best[0][nextToDeliver][newLoad][true] = cost;
				PQ.push(State(true, 0, nextToDeliver, newLoad, cost));
			}
		}

		// go to warehouse
		if (best[0][nextToDeliver][nextToLoad][true] > cost+FC*P[pos]) {
			best[0][nextToDeliver][nextToLoad][true] = cost+FC*P[pos];
			PQ.push(State(true, 0, nextToDeliver, nextToLoad, cost+FC*P[pos]));
		}

		if (nextToDeliver == nextToLoad)
			continue; // nothing but back-to-warehouse can be done

		if (isParked) {
			//cerr << pos << ' ' << nextToDeliver << ' ' << nextToLoad << ' ' << cost << '\n';
			//cerr << best[pos][nextToDeliver+1][nextToLoad][true] << ' ' << cost + (nextToDeliver+1<(int)P.size() ? 2 : 1)*WC*abs(P[pos]-P[nextToDeliver]) << '\n';
			// maybe deliver the leftmost undelivered loaded item on foot? (and come back to the truck if it isn't the last package)
			if (best[pos][nextToDeliver+1][nextToLoad][true] > cost + (nextToDeliver+1<(int)P.size() ? 2 : 1)*WC*abs(P[pos]-P[nextToDeliver])) {
				best[pos][nextToDeliver+1][nextToLoad][true] = cost + (nextToDeliver+1<(int)P.size() ? 2 : 1)*WC*abs(P[pos]-P[nextToDeliver]);
				PQ.push(State(true, pos, nextToDeliver+1, nextToLoad, cost + (nextToDeliver+1<(int)P.size() ? 2 : 1)*WC*abs(P[pos]-P[nextToDeliver])));
			}
		}
		if (pos+1 < (int)P.size()) {
			// try to move to the right
			if (best[pos+1][nextToDeliver][nextToLoad][false] > cost + FC*(P[pos+1]-P[pos])) {
				best[pos+1][nextToDeliver][nextToLoad][false] = cost + FC*(P[pos+1]-P[pos]);
				PQ.push(State(false, pos+1, nextToDeliver, nextToLoad, cost + FC*(P[pos+1]-P[pos])));
			}
			// maybe park there?
			if (best[pos+1][nextToDeliver][nextToLoad][true] > cost + FC*(P[pos+1]-P[pos]) + PC) {
				best[pos+1][nextToDeliver][nextToLoad][true] = cost + FC*(P[pos+1]-P[pos]) + PC;
				PQ.push(State(true, pos+1, nextToDeliver, nextToLoad, cost + FC*(P[pos+1]-P[pos]) + PC));
			}
		}
	}

	return -1;
}

class PackageDelivery {
	public:
	long long minimalCost(vector <int> packages, int walkCost, int fuelCost, int parkingCost, int truckCapacity) {
		P = packages;
		P.push_back(0);
		sort(P.begin(), P.end());
		WC = walkCost;
		FC = fuelCost;
		PC = parkingCost;
		TC = truckCapacity;

		memset(best, 0x3f, sizeof best);

		return pfs();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; int Arg4 = 3; long long Arg5 = 13LL; verify_case(0, Arg5, minimalCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; int Arg4 = 5; long long Arg5 = 23LL; verify_case(1, Arg5, minimalCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 5; int Arg3 = 9; int Arg4 = 2; long long Arg5 = 91LL; verify_case(2, Arg5, minimalCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = { 5, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; long long Arg5 = 6LL; verify_case(3, Arg5, minimalCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 10; int Arg4 = 5; long long Arg5 = 53LL; verify_case(4, Arg5, minimalCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PackageDelivery ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
