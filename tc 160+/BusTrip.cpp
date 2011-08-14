#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int busPos[50];
int busTime[50];
vector< vector<int> > buses;

void advance(int x, int newTime) {
	while (busTime[x] < newTime) {
		const int t = (busPos[x]+1)%buses[x].size();
		busTime[x] += abs(buses[x][t] - buses[x][busPos[x]]);
		busPos[x] = t;
	}
}
class BusTrip {
	public:
	int returnTime(int N, vector <string> buses_) {
		memset(busPos, 0, sizeof busPos);
		memset(busTime, 0, sizeof busTime);
		buses.assign(buses_.size(), vector<int> ());

		for (int i=0; i<(int)buses.size(); ++i) {
			istringstream is(buses_[i]);
			int x;
			while (is >> x)
				buses[i].push_back(x);
		}

		//for (int t=0; t<20; ++t) {
	//		advance(0, t);
	//		cerr << t << ": " << busPos[0] << ' ' << busTime[0] << '\n';
	//	}
	//	busPos[0] = busTime[0] = 0;

		bool hasMoved = false;
		int pos = 0;
		for (int time=0; time<=1001; ++time) {
			if (pos==0 && hasMoved)
				return time-1;

			for (int i=0; i<(int)buses.size(); ++i) {
				//cerr << time << ":: " << busTime[0] << ' ' << busPos[0] << '\n';
				advance(i, time);
				//cerr << time << ":: " << busTime[0] << ' ' << busPos[0] << '\n';
				if (busTime[i]==time && buses[i][busPos[i]]==pos) {
					//cerr << "take " << i << " at " << time << " from " << pos << " to ";
					const int t = (busPos[i]+1)%buses[i].size();
					time += abs(buses[i][t] - buses[i][busPos[i]]);
					busTime[i] += abs(buses[i][t] - buses[i][busPos[i]]);
					busPos[i] = t;
					pos = buses[i][t];

					//cerr << pos << '\n';
					hasMoved = true;
					break;
				}
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 51; string Arr1[] = {"0 5 10 15 20 25 30 35 40 50"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(1, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1 2", "2 1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4", "4 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 25; string Arr1[] = {"24 14 9 7 2", "21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22", "12 22 24 9 1 5 10 8 7 18 16 19 4 13 17",
 "14 5 17 9 23 7 16 22 10 4 6", "19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15",
 "2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0", "15 9 22 5 20 8 23 14 24 18 21 6 13 19",
 "2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5", "19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 157; verify_case(4, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; string Arr1[] = {"0 10 30 45 60 46 39 31 20", "9 20 0 86"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, returnTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BusTrip ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
