#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

bool check(const string &a, const string &b) {
	if (a.size() != b.size())
		return false;

	for (int i=0; i<(int)a.size(); ++i)
		if (tolower(a[i]) != b[i])
			return false;

	return true;
}
bool isTitle(const string &s) {
	istringstream is(s);
	string t;
	vector<string> w;
	while (is >> t)
		w.push_back(t);

	if (w.size() > 3)
		return true;

	for (int i=0; i<(int)w.size(); ++i)
		if (check(w[i], "the") || check(w[i], "and") || check(w[i], "of"))
			return true;

	return false;
}
class SortBooks {
	public:
	vector <int> checkManually(vector <string> field1, vector <string> field2) {
		vector<int> sol;
		for (int i=0; i<(int)field1.size(); ++i)
			if (((int)isTitle(field1[i]) + (int)isTitle(field2[i])) != 1)
				sol.push_back(i);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "J R R Tolkien", "THE Jungle BOOK" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "THE HOBBIT", "RUDYARD KIPLING" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, checkManually(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "Scaramouche", "Dan Brown", "War and Peace" }	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Rafael Sabatini", "The Da Vinci Code", "Leo Tolstoy" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, checkManually(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "Aesop", "Little Women", "Hans Christian Anderson", "The Arabian Nights",
  "Peter Christian Asbornsen", "Mr Poppers Penguins", "Enid Bagnold", "Miss Hickory",
  "Sir James Barrie", "The Wizard of OZ", "Ludwig Bemelmans", "The Five Chinese Brothers",
  "Edith Nesbit Bland", "The Enchanted Castle", "Edith Nesbit Bland",
  "Five Children and It", "Michael Bond", "The Children of Green Knowe",
  "James Boyd", "Caddie Woodlawn", "Walter Brooks", "The Runaway Bunny",
  "Margaret Wise Brown", "Big Red Barn", "Jean De Brunhoff",
  "Old Mother West Wind", "Frances Hodgson Burnett", "A Little Princess",
  "Frances Hodgson Burnett", "Mike Mulligan and His Steam Shovel",
  "Virginia Lee Burton", "The Enormous Egg", "Eleanor Cameron",
  "The Happy Orpheline", "Natalie Savage Carlson", "Through the Looking Glass",
  "Miguel Cervantes", "Secret of the Andes", "Beverly Cleary", "Henry Huggins",
  "Elizabeth Coatsworth", "The Adventures of Pinocchio", "Barbara Cooney",
  "The Little Lame Prince", "Paul Creswick", "The Courage of Sarah Noble",
  "Alice Dagliesh" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Aesops Fables", "Louisa May Alcott", "Fairy Tales", "Hans Christian Anderson",
  "East of the Sun and West of the Moon", "Richard and Florence Atwater",
  "National Velvet", "Carolyn Bailey", "Peter Pan", "Frank L Baum", "Madeline",
  "Claire Huchet Bishop", "The Railway Children", "Edith Nesbit Bland",
  "The Story of the Treasure Seekers", "Edith Nesbit Bland", "A Bear Called Paddington",
  "Lucy Boston", "Drums", "Carol Rylie Brink", "Freddy the Detective",
  "Margaret Wise Brown", "The Little Fur Family", "Moon Goodnight", "The Story of Babar",
  "Thornton W Burgess", "Little Lord Fauntleroy", "Frances Hodgson Burnett",
  "The Secret Garden", "Virginia Lee Burton", "The Little House", "Oliver Butterworth",
  "The Wonderful Flight to the Mushroom Planet", "Natalie Savage Carlson",
  "The Family Under the Bridge", "Lewis Carroll", "Don Quixote", "Ann Nolan Clark",
  "Beezus and Ramona", "Beverly Cleary", "The Cat Who Went to Heaven", "Carlo Collodi",
  "Chanticleer and the Fox", "Dinah Mulock Craik", "Robin Hood", "Alice Dagliesh",
  "The Bears on Hemlock Mountain" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 6, 7, 8, 10, 18, 19, 23, 26, 27, 36, 39, 44 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, checkManually(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "Lost     Horizon" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "James Hilton" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, checkManually(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "andy rooney", "joe lofthouse", "Theodore Taylor" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "love of life", "the arrest", "Softly Wandering" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, checkManually(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SortBooks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
