#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long i64;

class bloggoHyphenate {
  public:
  vector <string> correct(vector <string> dictionary, vector <string> candidates) {
      VS sol;
      VS d, c;
      
      for (int i=0; i<(int)dictionary.size(); ++i) {
      	d.push_back(dictionary[i]);
      	int j;
      	while ((j = d[i].find(' ')) != (int)string::npos)
      		d[i].erase(j, 1);
      }
      for (int i=0; i<(int)candidates.size(); ++i) {
      	c.push_back(candidates[i]);
      	int j = c[i].find('-');
      	assert(j != (int)string::npos);
      	c[i].erase(j, 1);
      }
      
      for (int i=0; i<(int)c.size(); ++i) {
      	int j = 0;
      	while (j<(int)d.size() && d[j]!=c[i])
      		++j;
      	string tmp;
      	VS syl;
      	istringstream is(dictionary[j]);
      	while (is >> tmp)
      		syl.push_back(tmp);
      	tmp = "";
      	if (syl.size() == 1) {
      		if (syl[0].length() != candidates[i].length())
      			sol.push_back(syl[0]);
      		else
      			sol.push_back("correct");
      		continue;
      	}
      	int cut = -1;
      	int pos = 1000;
      	int len = 0;
      	int hyp = candidates[i].find('-');
      	for (int k=0; k<(int)syl.size()-1; ++k) {
      		tmp += syl[k];
      		len += syl[k].length();
      		if (abs(len-hyp) < pos) {
      			pos = abs(len-hyp);
      			cut = len;
      		}
      		if (candidates[i][len] == '-') {
      			sol.push_back("correct");
      			goto done;
      		}
      	}
      	assert(cut != -1);
      	len = 0;
      	tmp = "";
      	for (int k=0; k<(int)syl.size(); ++k) {
      		tmp += syl[k];
      		len += syl[k].length();
      		if (len==cut)
      		  tmp += '-';
      	}
      	sol.push_back(tmp);
      	done: ;
      }
      return sol;
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"syl la ble", "dic tion a ry", "mole"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"mo-le", "syl-lable"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "mole",  "correct" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, correct(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"syl la ble", "dic tion a ry", "mole"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"dictio-nary", "syll-able"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "diction-ary",  "syl-lable" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, correct(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"syl la ble", "dic tion a ry", "mole"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"dictionary-", "-syllable"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "dictiona-ry",  "syl-lable" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, correct(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"zsx kd ds jply rf", "auca wb ill", "kvqm kpd p kqi xpbk j",
 "cqf ccr ewq", "srl vu m u d b", "h qae qzge", "jdn qqjf y",
 "zpa hbr", "d uft ctsm qjg", "l hgcp ik twuy bsi nlmu iyx",
 "cjjz jn td zg", "h bd q hi", "obsr kci hjdm h yar zsq q xyr hxb",
 "izq iibd yuh tgx nkq", "cjgd wfns", "ohc bn duc",
 "pydv a geki s bo avdi wd", "zygp gqt p", "xq pqqb ufoe",
 "cvm yamq moqj vl zoig w", "ahz b lf ixjv d", "qpg ven d",
 "m cbxz yf tv djf", "kti wacd uvgb kmr ew r", "ng tfb unw ndl",
 "qruv ctw a", "d hk v pcxh zoxy", "etbo wabk", "x hxiu n",
 "wp qq u dvpi tclh ac l", "f am brs lk uss uyb pg",
 "dtfx h ict if koe jhj", "nl shp yeji b rw vrg", "bz qfnc u",
 "t ceoy eb ss myoe zaaj z jey", "j d uju mb irvu",
 "anmo emjs syam ta bfiy kk", "gl ej egla tha jbug",
 "zk u sz raij d", "kw lbya atdb pd", "no id hqum u wny qcy",
 "phv nv l f oq m", "b xup tnq fziw yth sn", "pvc hnr oky lzj",
 "ew wtwt gyty s uu pfe kif my", "t cw fsau",
 "esk gqtd o yh jbx wed fl z", "vvr hqw wo gxwm",
 "lei akz nzz bumb", "bc hlmw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-duftctsmqjg", "-leiakznzzbumb", "-xhxiun", "-zpahbr",
 "ahzbl-fixjvd", "anmo-emjssyamtabfiykk", "aucawb-ill",
 "bchlmw-", "bxuptnqfziwyth-sn", "bzq-fncu", "c-vmyamqmoqjvlzoigw",
 "cjg-dwfns", "cjjzjn-tdzg", "cqfccre-wq", "dhkvpcxhzox-y",
 "dtfx-hictifkoejhj", "eskgqtdoyhjbx-wedflz", "etbowab-k",
 "ewwtwtgytysuupfe-kifmy", "fambrslkuss-uybpg", "glejegl-athajbug",
 "hbdqhi-", "hq-aeqzge", "izqiibd-yuhtgxnkq", "jd-nqqjfy",
 "jdujumb-irvu", "ktiwacduvgbkmr-ewr", "kv-qmkpdpkqixpbkj",
 "kwlbya-atdbpd", "lhgcpiktwuybsi-nlmuiyx", "mcbx-zyftvdjf",
 "ngtf-bunwndl", "nlshpyejibrwvrg-", "no-idhqumuwnyqcy", "o-hcbnduc",
 "obsr-kcihjdmhyarzsqqxyrhxb", "ph-vnvlfoqm", "pvchnrok-ylzj",
 "pydvageki-sboavdiwd", "qpgv-end", "qruvctw-a", "srlvumu-db",
 "tceoyebssmyo-ezaajzjey", "tcwfsau-", "vvrhqwwo-gxwm",
 "wpqqudvpit-clhacl", "xqpq-qbufoe", "zku-szraijd",
 "zsxkddsjp-lyrf", "zygpgqt-p"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "d-uftctsmqjg",  "lei-akznzzbumb",  "x-hxiun",  "zpa-hbr",  "ahzb-lfixjvd",  "correct",  "correct",  "bc-hlmw",  "correct",  "bz-qfncu",  "cvm-yamqmoqjvlzoigw",  "cjgd-wfns",  "correct",  "cqfccr-ewq",  "dhkvpcxh-zoxy",  "correct",  "correct",  "etbo-wabk",  "correct",  "correct",  "glejegla-thajbug",  "hbdq-hi",  "h-qaeqzge",  "correct",  "jdn-qqjfy",  "correct",  "correct",  "kvqm-kpdpkqixpbkj",  "correct",  "correct",  "mcbxz-yftvdjf",  "ngtfb-unwndl",  "nlshpyejibrw-vrg",  "correct",  "ohc-bnduc",  "correct",  "phv-nvlfoqm",  "pvchnroky-lzj",  "correct",  "qpg-vend",  "correct",  "correct",  "tceoyebssmyoe-zaajzjey",  "tcw-fsau",  "correct",  "wpqqudvpi-tclhacl",  "xq-pqqbufoe",  "correct",  "zsxkdds-jplyrf",  "correct" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, correct(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    bloggoHyphenate ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
