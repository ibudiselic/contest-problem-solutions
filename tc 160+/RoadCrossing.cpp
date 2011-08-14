#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

const double EPS = 1e-10;

set<double> state(double t, const vector< pair<int, int> > &P, int rw) {
	set<double> pos;
	for (int i=0; i<(int)P.size(); ++i) {
		if (t > P[i].first+EPS) {
			double p = (t-P[i].first) * P[i].second;
			if (p < rw-EPS) {
				pos.insert(p);
			}
		}
	}
	pos.insert(0);
	pos.insert(rw);
	return pos;
}

bool can_pass(const set<double> &s, int cw) {
	double last = -1.0;
	for (set<double>::const_iterator it=s.begin(); it!=s.end(); ++it) {
		if (last < -0.5) {
			last = *it;
			continue;
		}
		const double cur = *it;
		if (cur-last >= cw-EPS) {
			return true;
		}
		last = cur;
	}
	return false;
}

class RoadCrossing {
	public:
	double passTime(vector <string> P_, int rw, int cw, int A) {
		vector< pair<int, int> > P;
		for (int i=0; i<(int)P_.size(); ++i) {
			int t, v;
			istringstream is(P_[i]);
			is >> t >> v;
			P.push_back(make_pair(t, v));
		}

		sort(P.begin(), P.end());

		set<double> T;
		T.insert(0.0);
		T.insert(2100.0);
		for (int i=0; i<(int)P.size(); ++i) {
			T.insert(P[i].first);
			T.insert(double(rw)/P[i].second + P[i].first);
			for (int j=i+1; j<(int)P.size(); ++j) {
				if (P[i].second != P[j].second) {
					double t = double(P[i].first*P[i].second-P[j].first*P[j].second)/(P[i].second-P[j].second);
					if (t > EPS) {
						T.insert(t);
					}
				}
			}
		}

		vector<double> X(T.begin(), T.end());
		for (int i=1; i<(int)X.size(); ++i) {
			double start = max(X[i-1], double(A));
			double end = X[i];
			if (start > end+EPS) {
				continue;
			}
			const set<double> ss = state(start, P, rw);
			if (can_pass(ss, cw)) {
				return start;
			}
			const set<double> es = state(end, P, rw);
			if (can_pass(es, cw)) {
				for (int t=0; t<1000; ++t) {
					double m = start + (end-start)/2;
					if (can_pass(state(m, P, rw), cw)) {
						end = m;
					} else {
						start = m;
					}
				}
				return (start+end)/2;
			}
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 1", "2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 4; int Arg3 = 3; double Arg4 = 3.5; verify_case(0, Arg4, passTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"40 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 100; int Arg3 = 41; double Arg4 = 140.0; verify_case(1, Arg4, passTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; int Arg3 = 3; double Arg4 = 3.125; verify_case(2, Arg4, passTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 51; int Arg3 = 3; double Arg4 = 51.0; verify_case(3, Arg4, passTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"1000 1", "100 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 1000; double Arg4 = 2000.0; verify_case(4, Arg4, passTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoadCrossing ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
