#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class SMBus {
	public:
	int transmitTime(vector <string> msg, vector <int> times) {
		int cnt = (int)msg.size();
		int sol = 0;

		set<int> s;

		vector<int> byte(msg.size(), 0);
		bool again = true;
		while (cnt) {
			int t = 0;
			if (again) {
				s.clear();
				for (int i=0; i<(int)msg.size(); ++i)
					if (byte[i] < (int)msg[i].size()) {
						assert(byte[i]==0);
						s.insert(i);
					}
				again = false;
			}

			for (set<int>::const_iterator it=s.begin(); it!=s.end(); ++it)
				t >?= times[*it];
			assert(!s.empty());
			int win = *(s.begin());
			for (set<int>::const_iterator it=s.begin(); it!=s.end(); ++it)
				if (msg[win][byte[win]] > msg[*it][byte[*it]])
					win = *it;

			sol += t;
			if (byte[win] == (int)msg[win].size()-1) {
				++byte[win];
				for (int i=0; i<(int)msg.size(); ++i)
					if (byte[i]<(int)msg[i].size())
						byte[i] = 0;

				s.erase(win);
				--cnt;
				again = true;
			} else {
				set<int> next;
				for (set<int>::const_iterator it=s.begin(); it!=s.end(); ++it) {
					if (*it != win && msg[*it][byte[*it]] == msg[win][byte[win]]) {
						++byte[*it];
						next.insert(*it);
					}
				}
				++byte[win];
				next.insert(win);
				assert(!next.empty());
				s = next;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123","124","134"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(0, Arg2, transmitTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"012", "1234", "1233", "1223", "1123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1,5,2,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 94; verify_case(1, Arg2, transmitTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71048; verify_case(2, Arg2, transmitTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SMBus ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
