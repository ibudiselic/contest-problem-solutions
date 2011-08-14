#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class LetterFreq {
	public:
	vector <int> getFreqs(vector <string> doc) {
		vector<int> sol(26, 0);

		for (int i=0; i<(int)doc.size(); ++i)
			for (int j=0; j<(int)doc[i].size(); ++j)
				if (isalpha(doc[i][j]))
					++sol[toupper(doc[i][j])-'A'];
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "Be sure to ignore case", "and non-letter characters"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  1,  3,  1,  7,  0,  1,  1,  1,  0,  0,  1,  0,  4,  3,  0,  0,  5,  3,  4,  1,  0,  0,  0,  0,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getFreqs(Arg0)); }
	void test_case_1() { string Arr0[] = {"The following table shows letter frequences","for 3 languages.",
"Letter English French  German",
"A      7.3%    8.174%  5.997%",
"B      0.9%    0.876%  1.703%",
"C      3%      3.063%  2.697%",
"D      4.4%    4.125%  5.409%",
"E      13%     17.564% 17.949%",
"F      2.8%    0.959%  1.595%",
"G      1.6%    1.051%  3.199%",
"H      3.5%    0.721%  4.125%",
"I      7.4%    7.559%  8.125%",
"J      0.2%    0.598%  0.319%",
"K      0.3%    0.014%  1.244%",
"L      3.5%    5.783%  3.130%",
"M      2.5%    2.99%   2.264%",
"N      7.8%    7.322%  10.551",
"O      7.4%    5.289%  2.722%",
"P      2.7%    2.98%   0.831%",
"Q      0.3%    1.361%  0.009%",
"R      7.7%    6.219%  7.226%",
"S      6.3%    8.013%  6.873%",
"T      9.3%    7.353%  5.740%",
"U      2.7%    5.991%  4.584%",
"V      1.3%    1.557%  0.870%",
"W      1.6%    0.02%   1.497%",
"X      0.5%    3.5%    0.019%",
"Y      1.9%    1.16%   0.039%",
"Z      1%      0.72%   1.089%"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5,  2,  3,  1,  14,  5,  6,  5,  3,  1,  1,  8,  2,  7,  5,  1,  2,  7,  6,  7,  3,  1,  3,  1,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getFreqs(Arg0)); }
	void test_case_2() { string Arr0[] = { "Friends, Romans, countrymen, lend me your ears; ",
  "I come to bury Caesar, not to praise him.  ",
  "The evil that men do lives after them;  ",
  "The good is oft interred with their bones;  ",
  "So let it be with Caesar. The noble Brutus  ",
  "Hath told you Caesar was ambitious: ",
  "If it were so, it was a grievous fault,  ",
  "And grievously hath Caesar answer'd it.  ",
  "Here, under leave of Brutus and the rest--  ",
  "For Brutus is an honourable man;  ",
  "So are they all, all honourable men-- ",
  "Come I to speak in Caesar's funeral.  ",
  "He was my friend, faithful and just to me:  ",
  "But Brutus says he was ambitious;  ",
  "And Brutus is an honourable man.  ",
  "He hath brought many captives home to Rome ",
  "Whose ransoms did the general coffers fill:  ",
  "Did this in Caesar seem ambitious?  ",
  "When that the poor have cried, Caesar hath wept:  ",
  "Ambition should be made of sterner stuff:  ",
  "Yet Brutus says he was ambitious; ",
  "And Brutus is an honourable man.  ",
  "You all did see that on the Lupercal  ",
  "I thrice presented him a kingly crown,  ",
  "Which he did thrice refuse: was this ambition?  ",
  "Yet Brutus says he was ambitious; ",
  "And, sure, he is an honourable man.  ",
  "I speak not to disprove what Brutus spoke,  ",
  "But here I am to speak what I do know.  ",
  "You all did love him once, not without cause:  ",
  "What cause withholds you then, to mourn for him? ",
  "O judgment! thou art fled to brutish beasts,  ",
  "And men have lost their reason. Bear with me;  ",
  "My heart is in the coffin there with Caesar,  ",
  "And I must pause till it come back to me. "}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 101,  33,  25,  36,  122,  22,  7,  70,  75,  2,  7,  37,  40,  60,  81,  12,  0,  71,  86,  101,  59,  10,  24,  0,  18,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getFreqs(Arg0)); }
	void test_case_3() { string Arr0[] = { "amis, Romans, compatriotes,"," me pretent vos oreilles; ",
 "je viens pour enterrer Caesar,"," pour ne pas le feliciter.  ",
 "le mal que les hommes  les vies apres eux;  ",
 "le bon est oft interred avec leurs os;  ",
 "laissez-ainsi l'etre avec Caesar. Le Brutus noble",
 "Hath vous a indique que Caesar etait ambitieux:  ",
 "s'il en etait ainsi, c'etait un defaut grave,",
 "et gravement answer'd de Caesar de hath il.  ",
 "ici, sous le conge de Brutus et du repos --",
 "pour Brutus est un homme honorable;  ",
 "sont ainsi ils tous, tous les hommes honorables --",
 "viennent I a parler dans l'enterrement de Caesar.",
 "il etait mon ami, fidele et juste a moi:  ",
 "mais Brutus indique qu'il etait ambitieux;  ",
 "et Brutus est un homme honorable.  ",
 "il hath a apporte a beaucoup des captifs"," a la maison a Rome",
 "dont les ransoms ont fait la suffisance"," generale de coffres:  est-ce que ",
 "ceci dans Caesar a semble ambitieux?  ",
 "quand cela les pauvres ont pleure,"," le hath de Caesar a pleure:  ",
 "l'ambition devrait etre faite"," de substance de sterner:",
 "pourtant Brutus indique qu'il etait ambitieux;  ",
 "et Brutus est un homme honorable.  ",
 "vous tout avez vu que sur le Lupercal",
 "je trois fois lui ai presente kingly une couronne,",
 "qu'il a trois fois refuse:"," etait-elle cette ambition?",
 "pourtant Brutus indique qu'il etait ambitieux;  ",
 "et, sur, il est un homme honorable.  ",
 "je parle pour ne pas refuter quel Brutus a parle,",
 "mais ici je dois parler ce que je sais.  ",
 "vous tout l'avez aime par le passe,"," pas sans cause:",
 "quelle cause vous retient alors,"," pour pleurer pour lui?",
 "jugement de O!  l'art de thou"," sauve aux betes de brutish, ",
 "et aux hommes ont perdu leur raison."," Ours avec moi;",
 "mon coeur est dans le cercueil la avec Caesar,",
 "et je dois faire une pause jusqu'a"," ce qu'il reviennent a moi" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 121,  28,  37,  30,  208,  16,  6,  22,  94,  9,  1,  69,  42,  69,  77,  33,  18,  92,  109,  103,  102,  21,  1,  8,  1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getFreqs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LetterFreq ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
