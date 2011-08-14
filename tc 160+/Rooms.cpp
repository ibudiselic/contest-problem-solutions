#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}

struct Entry {
	int pos;
	int move_count;
	Entry(int p, int m): pos(p), move_count(m) {}
};

class Rooms {
	public:
	vector <int> finalRooms(vector <string> rooms, string doors, int start) {
		vector<vector<vector<bool> > > a(26, vector<vector<bool> >(rooms.size(), vector<bool>(rooms.size(), false)));

		for (int i=0; i<(int)rooms.size(); ++i) {
			vector<string> t = tokenize<string>(rooms[i]);
			for (int j=0; j<(int)t.size(); ++j) {
				char c = t[j][0];
				vector<int> tt = tokenize<int>(t[j].substr(2), ",");
				for (int k=0; k<(int)tt.size(); ++k)
					a[c-'A'][i][tt[k]] = true;
			}
		}

		int m_cnt = 0;
		vector<bool> used(rooms.size(), false);
		queue<Entry> q;
		q.push(Entry(start, 0));

		while (!q.empty()) {
			Entry t = q.front();
			q.pop();
			if (t.move_count == (int)doors.size()) {
				m_cnt = t.move_count;
				break;
			}
			if (t.move_count > m_cnt) {
				assert(m_cnt == t.move_count-1);
				fill(used.begin(), used.end(), false);
				m_cnt = t.move_count;
			}
			const vector<vector<bool> > &allowed = a[doors[t.move_count]-'A'];

			for (int i=0; i<(int)allowed.size(); ++i)
				if (!used[i] && allowed[t.pos][i]) {
					used[i] = true;
					q.push(Entry(i, t.move_count+1));
				}
		}

		vector<int> sol;
		if (m_cnt == (int)doors.size())
			for (int i=0; i<(int)used.size(); ++i)
				if (used[i])
					sol.push_back(i);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A:0 B:1","A:1 B:0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB"; int Arg2 = 0; int Arr3[] = { 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, finalRooms(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"A:1 B:0","A:0 B:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AABAAB"; int Arg2 = 1; int Arr3[] = { 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, finalRooms(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"B:1 Z:0","B:0 Z:2","B:2 Z:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBZZB"; int Arg2 = 0; int Arr3[] = { 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, finalRooms(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"A:0,1,2,3","A:0,1,2,3","A:0,1,2,3","A:0,1,2,3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; int Arg2 = 2; int Arr3[] = { 0,  1,  2,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, finalRooms(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"D:0","D:0","D:0","D:0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "GDDDDD"; int Arg2 = 3; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, finalRooms(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Rooms ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
