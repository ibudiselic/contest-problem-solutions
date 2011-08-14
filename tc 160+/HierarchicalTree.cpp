#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int calc(int x, const vector< set<int> > &v, vector<int> &cnt, vector<bool> &vis) {
	if (cnt[x] != -1)
		return cnt[x];

	cnt[x] = 1;
	vis[x] = 1;
	const set<int> &s = v[x];
	for (set<int>::const_iterator it=s.begin(); it!=s.end(); ++it) {
		if (vis[*it])
			return cnt[x] = -100000;
		cnt[x] += calc(*it, v, cnt, vis);
	}
	vis[x] = 0;

	return cnt[x];
}
class HierarchicalTree {
	public:
	vector <string> countDescendants(vector <string> parentData) {
		string s;
		for (int i=0; i<(int)parentData.size(); ++i)
			s += parentData[i];

		map<string, int> ind;
		vector<string> names;
		vector<int> parent;
		vector< set<int> > children;
		names.push_back("ROOT");
		ind["ROOT"] = 0;
		parent.push_back(-2);
		children.push_back(set<int>());

		int n = 1;
		istringstream is(s);
		string w;
		while (is >> w) {
			w.replace(w.find(','), 1, 1, ' ');
			istringstream is2(w);
			string a, b;
			is2 >> a >> b;
			if (a == "ROOT")
				return vector<string>();

			if (ind.count(a) == 0) {
				ind[a] = n++;
				names.push_back(a);
				parent.push_back(-1);
				children.push_back(set<int>());
			}
			if (ind.count(b) == 0) {
				ind[b] = n++;
				names.push_back(b);
				parent.push_back(-1);
				children.push_back(set<int>());
			}

			int ai = ind[a];
			int bi = ind[b];
			if (parent[ai]!=-1 && parent[ai]!=bi)
				return vector<string>();

			parent[ai] = bi;
			children[bi].insert(ai);
		}

		vector<int> cnt(n, -1);
		for (int i=0; i<n; ++i)
			if (cnt[i] == -1) {
				vector<bool> vis(n, 0);
				cnt[i] = calc(i, children, cnt, vis);
			}

		if (cnt[0] < n)
			return vector<string>();

		vector<string> sol;
		for (map<string, int>::const_iterator it=ind.begin(); it!=ind.end(); ++it) {
			ostringstream os;
			os << (it->first) << ": " << cnt[it->second]-1;
			sol.push_back(os.str());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"bin,ROOT tty,dev dev,ROOT passwd,etc etc,ROOT lib",
",ROOT mnt,ROOT proc,ROOT tmp,ROOT usr,ROOT var,RO",
"OT libc,lib screens,tmp kernel,usr log,var tty,de",
"v"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT: 15",  "bin: 0",  "dev: 1",  "etc: 1",  "kernel: 0",  "lib: 1",  "libc: 0",  "log: 0",  "mnt: 0",  "passwd: 0",  "proc: 0",  "screens: 0",  "tmp: 1",  "tty: 0",  "usr: 1",  "var: 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, countDescendants(Arg0)); }
	void test_case_1() { string Arr0[] = {""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT: 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, countDescendants(Arg0)); }
	void test_case_2() { string Arr0[] = {"disconnectb,disconnecta cyclea,ROOT intermediatea",
",cyclea cycleb,intermediatea cyclea,cycleb ROOT,r",
"ootparent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, countDescendants(Arg0)); }
	void test_case_3() { string Arr0[] = {"sapiens,homo homo,hominidae hominidae,primates pri",
"mates,mammalia mammalia,chordata chordata,animalia",
" animalia,eukarya eukarya,ROOT ",
"protista,eukarya fungi,eukarya plantae,eukarya ",
"porifera,animalia cnidaria,animalia platyhelminthe",
"s,animalia nematoda,animalia mollusca,animalia ann",
"elida,animalia arthropoda,animalia echinodermata,a",
"nimalia ",
"agnatha,chordata chondrichthyes,chordata osteichth",
"yes,chordata amphibia,chordata reptilia,chordata a",
"ves,chordata ",
"artiodactyla,mammalia carnivora,mammalia cetacea,m",
"ammalia chiroptera,mammalia dermoptera,mammalia hy",
"racoidea,mammalia insectivora,mammalia lagomorpha,",
"mammalia macroscelidea,mammalia notoryctemorphia,m",
"ammalia perissodactyla,mammalia pholidota,mammalia",
" proboscidea,mammalia rodentia,mammalia scandentia",
",mammalia sirenia,mammalia tubulidentata,mammalia ",
"xenarthra,mammalia ",
"lemuridae,primates cheirogaleidae,primates indrida",
"e,primates daubentoniidae,primates galagonidae,pri",
"mates loridae,primates megaladapidae,primates tars",
"iidae,primates cebidae,primates cercopithecidae,pr",
"imates callitrichidae,primates hylobatidae,primate",
"s ",
"gorilla,hominidae pan,hominidae pongo,hominidae ",
"domain,ROOT kingdom,domain phylum,kingdom class,ph",
"ylum order,class family,order genus,family species",
",genus ninja,mammalia"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT: 67",  "agnatha: 0",  "amphibia: 0",  "animalia: 54",  "annelida: 0",  "arthropoda: 0",  "artiodactyla: 0",  "aves: 0",  "callitrichidae: 0",  "carnivora: 0",  "cebidae: 0",  "cercopithecidae: 0",  "cetacea: 0",  "cheirogaleidae: 0",  "chiroptera: 0",  "chondrichthyes: 0",  "chordata: 45",  "class: 4",  "cnidaria: 0",  "daubentoniidae: 0",  "dermoptera: 0",  "domain: 7",  "echinodermata: 0",  "eukarya: 58",  "family: 2",  "fungi: 0",  "galagonidae: 0",  "genus: 1",  "gorilla: 0",  "hominidae: 5",  "homo: 1",  "hylobatidae: 0",  "hyracoidea: 0",  "indridae: 0",  "insectivora: 0",  "kingdom: 6",  "lagomorpha: 0",  "lemuridae: 0",  "loridae: 0",  "macroscelidea: 0",  "mammalia: 38",  "megaladapidae: 0",  "mollusca: 0",  "nematoda: 0",  "ninja: 0",  "notoryctemorphia: 0",  "order: 3",  "osteichthyes: 0",  "pan: 0",  "perissodactyla: 0",  "pholidota: 0",  "phylum: 5",  "plantae: 0",  "platyhelminthes: 0",  "pongo: 0",  "porifera: 0",  "primates: 18",  "proboscidea: 0",  "protista: 0",  "reptilia: 0",  "rodentia: 0",  "sapiens: 0",  "scandentia: 0",  "sirenia: 0",  "species: 0",  "tarsiidae: 0",  "tubulidentata: 0",  "xenarthra: 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, countDescendants(Arg0)); }
	void test_case_4() { string Arr0[] = {"duke,ROOT arizona,duke maryland,duke michiganst,a",
"rizona usc,duke stanford,maryland temple,michigan",
"st illinois,arizona ucla,duke kentucky,usc cincin",
"nati,stanford georgetown,maryland gonzaga,michiga",
"nst pennst,temple kansas,illinois mississippi,ari",
"zona missouri,duke utahst,ucla bostoncollege,usc ",
"iowa,kentucky stjosephs,stanford kentstate,cincin",
"nati georgiast,maryland hampton,georgetown fresno",
"st,michiganst indianast,gonzaga florida,temple no",
"rthcarolina,pennst charlotte,illinois syracuse,ka",
"nsas notredame,mississippi butler,arizona monmout",
"h,duke georgia,missouri ohiost,utahst hofstra,ucl",
"a oklahomast,usc southernutah,bostoncollege creig",
"hton,iowa holycross,kentucky ncgreensboro,stanfor",
"d georgiatech,stjosephs byu,cincinnati indiana,ke",
"ntstate wisconsin,georgiast georgemason,maryland ",
"arkansas,georgetown iowast,hampton alabamast,mich",
"iganst california,fresnost virginia,gonzaga oklah",
"oma,indianast texas,temple westernky,florida prov",
"idence,pennst princeton,northcarolina northwester",
"nst,illinois tennessee,charlotte hawaii,syracuse ",
"csnorthridge,kansas xavier,notredame iona,mississ",
"ippi wakeforest,butler easternill,arizona winthro",
"p,northwesternst"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT: 65",  "alabamast: 0",  "arizona: 32",  "arkansas: 0",  "bostoncollege: 1",  "butler: 1",  "byu: 0",  "california: 0",  "charlotte: 1",  "cincinnati: 3",  "creighton: 0",  "csnorthridge: 0",  "duke: 64",  "easternill: 0",  "florida: 1",  "fresnost: 1",  "georgemason: 0",  "georgetown: 3",  "georgia: 0",  "georgiast: 1",  "georgiatech: 0",  "gonzaga: 3",  "hampton: 1",  "hawaii: 0",  "hofstra: 0",  "holycross: 0",  "illinois: 8",  "indiana: 0",  "indianast: 1",  "iona: 0",  "iowa: 1",  "iowast: 0",  "kansas: 3",  "kentstate: 1",  "kentucky: 3",  "maryland: 15",  "michiganst: 15",  "mississippi: 3",  "missouri: 1",  "monmouth: 0",  "ncgreensboro: 0",  "northcarolina: 1",  "northwesternst: 1",  "notredame: 1",  "ohiost: 0",  "oklahoma: 0",  "oklahomast: 0",  "pennst: 3",  "princeton: 0",  "providence: 0",  "southernutah: 0",  "stanford: 7",  "stjosephs: 1",  "syracuse: 1",  "temple: 7",  "tennessee: 0",  "texas: 0",  "ucla: 3",  "usc: 7",  "utahst: 1",  "virginia: 0",  "wakeforest: 0",  "westernky: 0",  "winthrop: 0",  "wisconsin: 0",  "xavier: 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, countDescendants(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HierarchicalTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
