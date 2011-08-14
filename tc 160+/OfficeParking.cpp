#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class OfficeParking {
	public:
	int spacesUsed(vector <string> events) {
		int sol = 0;
		int cur = 0;
		for (int i=0; i<(int)events.size(); ++i) {
			istringstream is(events[i]);
			string s;
			is >> s;
			is >> s;
			cur += (s=="arrives");
			cur -= (s=="departs");
			sol = max(sol, cur);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Alice arrives","bob arrives","Alice departs",
 "Charles arrives","bob departs","Charles departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, spacesUsed(Arg0)); }
	void test_case_1() { string Arr0[] = {"AdminBrett arrives","lbackstrom arrives","AdminBrett departs","mike arrives",
 "TheFaxman arrives","AdminBrett arrives","lbackstrom departs","dok arrives",
 "AdminBrett departs","gt arrives","AdminBrett arrives","lbackstrom arrives",
 "AdminBrett departs","jhughes arrives","jhughes departs","TheFaxman departs",
 "MaryJoe arrives","AdminBrett arrives","AdminBrett departs","AdminBrett arrives"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, spacesUsed(Arg0)); }
	void test_case_2() { string Arr0[] = {"SnapDragon arrives","tomek arrives","JohnDethridge arrives","ZorbaTHut arrives",
 "snewman arrives","reid arrives","NGBronson arrives","Yarin arrives",
 "bstanescu arrives","mathijs arrives","radeye arrives","bladerunner arrives",
 "dgarthur arrives","venco arrives","dmwright arrives","WishingBone arrives",
 "Eryx arrives","antimatter arrives","ChristopherH arrives","lars arrives",
 "biggnate arrives","JanKuipers arrives","dary arrives","haha arrives","grotmol arrives",
 "XuChuan arrives","Ryan arrives","LunaticFrindge arrives","Wasteland arrives",
 "RunningWild arrives","hampster arrives","RalphFurmaniak arrives",
 "kyky arrives","qubits arrives","Rustyoldman arrives","turuthok arrives",
 "Vulpecular arrives","Eeyore arrives","wackes arrives","Ishan arrives",
 "dimkadimon arrives","dplass arrives","Olorin arrives","TangentZ arrives",
 "NeverMore arrives","Pops arrives","srowan arrives","tjq arrives",
 "vorthys arrives","schveiguy arrives"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, spacesUsed(Arg0)); }
	void test_case_3() { string Arr0[] = {"AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, spacesUsed(Arg0)); }
	void test_case_4() { string Arr0[] = {"snapdragon arrives","SnapDragon arrives",
 "AdminBrett arrives","AdminBrett departs",
 "SnapDragon departs","snapdragon departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, spacesUsed(Arg0)); }
	void test_case_5() { string Arr0[] = {"departs arrives","arrives arrives","arrives departs","departs departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, spacesUsed(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OfficeParking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
