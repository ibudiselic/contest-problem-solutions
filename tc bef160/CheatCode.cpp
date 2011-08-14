#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class CheatCode {
	public:
	vector <int> matches(string keys, vector <string> codes) {
		vector<int> sol;
		for (vector<string>::size_type i=0; i<codes.size(); ++i) {
			bool ok = false;
			set<int> a;
			a.insert(0);
			for (string::size_type x=0; x<keys.size(); ++x) {
				set<int> b;
				b.insert(0);
				if (x>0 && keys[x]==keys[x-1]) {
					for (set<int>::const_iterator s=a.begin(); s!=a.end(); ++s)
						b.insert(*s);
				}
				for (set<int>::const_iterator s=a.begin(); s!=a.end(); ++s) {
					if (codes[i][*s] == keys[x]) {
						b.insert(*s+1);
						if (*s+1 == (int)codes[i].size()) {
							ok = true;
							goto kraj;
						}
					}
				}
				a = b;
			}
			kraj:
			if (ok)
				sol.push_back(i);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "UUDDLRRLLRBASS"; string Arr1[] = {"UUDDLRLRBA","UUDUDLRLRABABSS","DDUURLRLAB","UUDDLRLRBASS","UDLRRLLRBASS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  3,  4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, matches(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; string Arr1[] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, matches(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "IDDQDDTSFHHALL"; string Arr1[] = {"FHHALL", "FHSHH", "IDBEHOLDA", "IDBEHOLDI", "IDBEHOLDL",
 "IDBEHOLDR", "IDBEHOLDS", "IDBEHOLDV", "IDCHOPPERS", "IDCLEV",
 "IDCLIP", "IDDQD", "IDDT", "IDFA", "IDKFA", "IDMYPOS", "IDMUS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  11 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, matches(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYY"; string Arr1[] = {"ABCDE", "BCDEF", "CDEFG", "DEFGH", "EFGHI",
 "FGHIJ", "GHIJK", "HIJKL", "IJKLM", "JKLMN",
 "KLMNO", "LMNOP", "MNOPQ", "NOPQR", "OPQRS",
 "PQRST", "QRSTU", "RSTUV", "STUVW", "TUVWX",
 "UVWXY", "VWXYZ", "WXYZA", "XYZAB", "YZABC",
 "ZABCD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, matches(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ"; string Arr1[] = {"LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSS", "LAKJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKASSJ",  "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKHHSJ",  "LAKDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",   "KJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLLSLJKAHS",    "LAKGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",
 "LAKJDGSJKGLSDKHFDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLJKAHSJ",
 "LAKJDGSJKGLSDHFKDFHDGHHSDKKSJDHFHJGKDKLSLSJKAHS",    "KGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJKDKLSLSLJKAHSJ",
 "LKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHS",    "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",
 "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFGKDKLSLSLJKAHSJ",
 "LKJDGSJKLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHHJGKDKLSLSLJKAHSJ",
 "AKJDGSJKGLSDKFKDFHDGHHSSJDHFJGKDKLSLSLJKAHS",        "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHSJ",
 "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAS",    "KJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAH",
 "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHSJ"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  3,  7,  13,  17,  27,  43 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, matches(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CheatCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
