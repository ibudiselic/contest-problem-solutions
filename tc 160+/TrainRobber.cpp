#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}

struct Entry {
	long long p;
	int i;
	Entry(long long p_, int i_): p(p_), i(i_) {}
};
bool operator<(const Entry &a, const Entry &b) {
	return a.p > b.p;
}

class TrainRobber {
	public:
	double finalPosition(long long length, int nCarriages, vector <string> offset_, vector <string> period_, int trainSpeed, int robberSpeed, int nBridges) {
		string o_, p_;
		for (int i=0; i<(int)offset_.size(); ++i)
			o_ += (i!=0 ? " ":"") + offset_[i];
		for (int i=0; i<(int)period_.size(); ++i)
			p_ += (i!=0 ? " ":"") + period_[i];
		vector<int> index;
		vector<int> offset = tokenize<int>(o_);
		vector<int> period = tokenize<int>(p_);

		priority_queue<Entry> Q;
		for (int i=0; i<(int)offset.size(); ++i)
			Q.push(Entry(offset[i], i));

		long long pos = 0;
		int carr_cnt = 0; // robber on train
		int cnt_bridges = 0; // passed bridges

		while (cnt_bridges < nBridges) {
			Entry t = Q.top();
			int n_b = 0;
			while (Q.top().p == t.p) { // count all the bridges on the same position
				++n_b;
				const int i = Q.top().i;
				Q.pop();
				Q.push(Entry(t.p + period[i], i));
			}

			const int add = ((t.p-pos)*robberSpeed) / (length*(trainSpeed+robberSpeed));
			for (int i=1; i<=add; ++i) {
				++carr_cnt;
				if (carr_cnt == nCarriages)
					return pos + i*length + double(i*length)/robberSpeed * trainSpeed;
			}
			pos = t.p;
			cnt_bridges += n_b;
		}
		return pos;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4", "2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 100; double Arg7 = 14.0; verify_case(0, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; double Arg7 = 3.0; verify_case(1, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; string Arr2[] = {"8 23"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"15 13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 10; int Arg6 = 10; double Arg7 = 75.0; verify_case(2, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; string Arr2[] = {"1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; int Arg5 = 100; int Arg6 = 100; double Arg7 = 50.0; verify_case(3, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000000; string Arr2[] = {"10", "15 63"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"23 42 11"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 1000; int Arg6 = 1000; double Arg7 = 6355.0; verify_case(4, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TrainRobber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
