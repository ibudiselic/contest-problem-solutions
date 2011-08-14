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

vector<string> friends, O;
vector<int> bdays, D;
struct Occ {
    int d, oi, fi;
    Occ(int d_, int oi_, int fi_): d(d_), oi(oi_), fi(fi_) {}
    string to_str() const {
        ostringstream os;
        os << d << ". " << friends[fi] << ' ' << O[oi] << " (" << (d - bdays[fi])/D[oi] << ')';
        return os.str();
    }

    Occ next() const {
        return Occ(d + D[oi], oi, fi);
    }
};
bool operator<(const Occ &a, const Occ &b) {
    if (a.d != b.d) {
        return a.d > b.d;
    } else if (a.oi != b.oi) {
        return a.oi > b.oi;
    } else {
        return a.fi > b.fi;
    }
}
class BirthdayReminders {
	public:
	vector <string> remind(vector <string> friends_, vector <int> bdays_, int cur, vector <string> O_, vector <int> D_, int k) {
		friends = friends_;
        bdays = bdays_;
        O = O_;
        D = D_;
        
        priority_queue<Occ> PQ;
        for (int i=0; i<(int)friends.size(); ++i) {
            for (int j=0; j<(int)O.size(); ++j) {
                int n = (cur-bdays[i] + D[j]-1)/D[j];
                assert(n >= 1);
                PQ.push(Occ(bdays[i] + n*D[j], j, i));
            }
        }

        vector<string> sol;
        while (sol.size() < k) {
            Occ t = PQ.top();
            PQ.pop();

            sol.push_back(t.to_str());
            PQ.push(t.next());
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"John", "Jack", "Bill"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 100, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 500; string Arr3[] = {"birthday", "decimal birthday", "binary birthday"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {365, 1000, 512}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; string Arr6[] = {"515. Bill birthday (1)", "562. John binary birthday (1)", "612. Jack binary birthday (1)", "662. Bill binary birthday (1)", "780. John birthday (2)", "830. Jack birthday (2)", "880. Bill birthday (2)", "1050. John decimal birthday (1)", "1074. John binary birthday (2)", "1100. Jack decimal birthday (1)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"Zero", "Two", "Three"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; string Arr3[] = {"threeday", "twoday"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; string Arr6[] = {"24. Zero threeday (8)", "24. Three threeday (7)", "24. Zero twoday (12)", "24. Two twoday (11)", "25. Three twoday (11)", "26. Two threeday (8)", "26. Zero twoday (13)", "26. Two twoday (12)", "27. Zero threeday (9)", "27. Three threeday (8)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"Jessica Alba", "Angelina Jolie", "Paris Hilton", "Britney Spears"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4135, 1980, 4065, 4353}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14091; string Arr3[] = {"Venus year", "Earth year", "Mars year", "Jupiter year", "Saturn year"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {225, 365, 687, 4332, 10760}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 20; string Arr6[] = {"14130. Angelina Jolie Venus year (54)", "14190. Paris Hilton Venus year (45)", "14208. Britney Spears Earth year (27)", "14253. Britney Spears Venus year (44)", "14260. Jessica Alba Venus year (45)", "14285. Paris Hilton Earth year (28)", "14346. Angelina Jolie Mars year (18)", "14355. Angelina Jolie Venus year (55)", "14355. Jessica Alba Earth year (28)", "14370. Paris Hilton Mars year (15)", "14390. Angelina Jolie Earth year (34)", "14415. Paris Hilton Venus year (46)", "14440. Jessica Alba Mars year (15)", "14478. Britney Spears Venus year (45)", "14485. Jessica Alba Venus year (46)", "14573. Britney Spears Earth year (28)", "14580. Angelina Jolie Venus year (56)", "14640. Paris Hilton Venus year (47)", "14650. Paris Hilton Earth year (29)", "14658. Britney Spears Mars year (15)" }; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, remind(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BirthdayReminders ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
