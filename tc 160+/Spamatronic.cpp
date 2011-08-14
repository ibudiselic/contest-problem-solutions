#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cctype>

using namespace std;

set<string> tokenize(const string &t) {
	set<string> ret;
	for (int j=0; j<(int)t.size(); ++j) {
		string s;
		while (j<(int)t.size() && isalpha(t[j]))
			s += tolower(t[j++]);
		if (!s.empty())
			ret.insert(s);
	}
	return ret;
}

class Spamatronic {
	public:
	vector <int> filter(vector <string> knownSpam, vector <string> newMail) {
		set<string> S;
		for (int i=0; i<(int)knownSpam.size(); ++i) {
			const set<string> S_ = tokenize(knownSpam[i]);
			S.insert(S_.begin(), S_.end());
		}

		vector<int> sol;
		for (int i=0; i<(int)newMail.size(); ++i) {
			const set<string> T = tokenize(newMail[i]);
			int cnt = 0;
			for (set<string>::const_iterator it=T.begin(); it!=T.end(); ++it)
				cnt += S.count(*it);
			if (100*cnt < 75*(int)T.size())
				sol.push_back(i);
			else
				S.insert(T.begin(), T.end());
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"This is a vile piece of spam."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Spam is spiced ham.",
 "Spam is VILE!",
 "Spam is not vile."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, filter(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"We have the best mortgage rates. Refinance today.",
 "Money-making opportunity! $5000/week potential!!!",
 "Don't Feel Short; try Elevator Shoes for increase.",
 "All-new pics: Stacy, Tiffany, Donner, and Blitzen."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5000 bucks for shoes?",
 "Short bucks for new shoes?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, filter(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"We have the best mortgage rates. Refinance today.",
 "Money-making opportunity! $5000/week potential!!!",
 "Don't Feel Short; try Elevator Shoes for increase.",
 "All-new pics: Stacy, Tiffany, Donner, and Blitzen."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"On, Dasher! On, Dancer! On, Donner and Blitzen!"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, filter(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"We have the best mortgage rates. Refinance today.",
 "Money-making opportunity! $5000/week potential!!!",
 "Don't Feel Short; try Elevator Shoes for increase.",
 "All-new pics: Stacy, Tiffany, Donner, and Blitzen."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Try the prime ribs.",
 "Donner: New Prime Rates Today",
 "Try the prime ribs."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, filter(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"One, two, buckle my shoe.",
 "Eins, zwei, polizei.",
 "On the first day of Christmas, my true love",
 "gave to me a partridge in a pear tree."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Christmas shoe buckle madness!",
 "Partridge polizei madness day!",
 "I did not shoot the deputy.",
 "The second day of Christmas, a partridge bit me."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, filter(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",
 "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",
 "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",
 "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",
 "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",
 "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",
 "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",
 "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",
 "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",
 "zkmC JuIK jEaC AjuA jXRX TUyI cpJP bmnE qXsI BYAM ",
 "JcJO BEQN bTrL OpXy fKfx XGyV aMFv TNCG xrmH rnsq ",
 "olSb fBig LuzT rJbq IEjR ygzg GgpS qaiS GDMT wMoN ",
 "Ypxx tWrb WSEe COmB XwqK GOWj ZCQW qtkm riJO weoj ",
 "uDHD nmTu yruZ zVEu Bhyl qheT KqwD YFTK frMk daSC ",
 "ywfg arFu KGOk rciT PZQX tSll dpXd Aczq EYjW RQkh ",
 "BJcC dJkr lWPM jaJI UCMt NQiy azlc encg srwA YhUH ",
 "wqET eMLv kFYM GbDi hkQq sFvy ZwLi gvbu wdLz bZzl ",
 "NIVA xpTx SUOz vhQM fYTn NkrJ pKYm sVpf DMxL RtAn ",
 "kCXI TAzJ aaeQ zYqX TpfN nLpA bsmp GsAa rDhI kexj ",
 "ibLo DWfO aEYD Dkzt gqOf IKeP jDJk iaAH viBk kbyz ",
 "ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",
 "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",
 "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",
 "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",
 "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",
 "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",
 "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",
 "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",
 "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",
 "zkmC JuIK jEaC AjuA jXRX TUyI cpJP bmnE qXsI BYAM ",
 "JcJO BEQN bTrL OpXy fKfx XGyV aMFv TNCG xrmH rnsq ",
 "olSb fBig LuzT rJbq IEjR ygzg GgpS qaiS GDMT wMoN ",
 "Ypxx tWrb WSEe COmB XwqK GOWj ZCQW qtkm riJO weoj ",
 "uDHD nmTu yruZ zVEu Bhyl qheT KqwD YFTK frMk daSC ",
 "ywfg arFu KGOk rciT PZQX tSll dpXd Aczq EYjW RQkh ",
 "BJcC dJkr lWPM jaJI UCMt NQiy azlc encg srwA YhUH ",
 "wqET eMLv kFYM GbDi hkQq sFvy ZwLi gvbu wdLz bZzl ",
 "NIVA xpTx SUOz vhQM fYTn NkrJ pKYm sVpf DMxL RtAn ",
 "kCXI TAzJ aaeQ zYqX TpfN nLpA bsmp GsAa rDhI kexj ",
 "ibLo DWfO aEYD Dkzt gqOf IKeP jDJk iaAH viBk kbyz ",
 "ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",
 "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",
 "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",
 "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",
 "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",
 "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",
 "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",
 "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",
 "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",
 "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"qXsI hRfD viBk KGOk GLPK kFYM WSEe oCEF ysrX Gicz ",
 "YMav Clmy LuzT wdLz nmTu jiCs gvbu sRdG aaeQ EMFM ",
 "syuO pKYm ootQ UyOJ TpfN encg LuzT sRdG TJGj elbx ",
 "LuzT nDXV boPm zOqG jLeu gcxH zOqG KqwD RQkh PJFZ ",
 "srwA aKdp VOZP rJbq viBk WIlz kexj ysrX icKO OpXy ",
 "Flij SHTh shhx EMFM pcdV viBk ESfL zkmC sHHV TNCG ",
 "GDMT lWPM tWrb tnzK aEYD dJkr NQiy CyZJ GOWj Ybsv ",
 "wBEy IEjR COmB bZzl vhQM iaAH EMFM bsmp GLPK lWPM ",
 "tWrb HFzg XPoH ZCQW zOqG PZQX CyZJ qnsD Txbg tLgZ ",
 "LYUT vODC DzEE bTrL Clmy AYyL lBJT EYjW fBig MGEK ",
 "UbbN DTQd ysrX vhQM tSll bZzl qXsI DWfO LzXO UfCU ",
 "BYAM wAAt Aczq Ckym lWPM lBJT KcTV Hbut rJbq ibLo ",
 "feoz qaiS oSvE kFYM XGyV lWPM NIVA sDKm QuDv rnsq ",
 "BYAM UDNV GuIh GuIh bKFz ootQ sFvy zpXB ZbWY NQiy ",
 "cWfG oeRC LHJC NYmX ppzA NIVA rDhI QCOQ fBig aMFv ",
 "RQkh SUOz WkoW wqET sRdG sRdG tnzK ARuG OMpb xbcc ",
 "gvbu AjuA GgpS nLpA TUyI Swfg LCbJ aaeQ XGyV yruZ ",
 "ygzg xnuE afWW tuUM KGOk GOWj ousC mrXE ZwLi FSll ",
 "ckKT frMk McdI zVEu nVIK ygzg daSC ArcZ Dagc ryuQ ",
 "bPhx zurF XAIM gqOf aRSX Ypxx dfwy aKdp chtc iCCo ",
 "ovIj ywfg QuDv pKYm iaAH BbPq LHJC tTGm Vztx VwjP ",
 "TpfN TAzJ Vztx tTGm sXKj IKeP AUoD qXsI DMxL azlc ",
 "sRdG WYmV NQuu xnuE TUyI XPoH YhUH ousC AYyL jEaC ",
 "RQkh BbPq UbbN GuIh oCEF tLgZ arFu qTLZ Dkzt zVEu ",
 "NIVA FDib PZQX McdI GgpS Euso ppzA Dagc Vztx LHJC ",
 "ZvMg Bhyl GOWj sDKm ywfg oJYB AjuA jaJI ZIaH Dkzt ",
 "ygzg oSvE qheT encg SUOz vODC mDVo KcTV swcU Dkzt ",
 "GgpS RtAn TpfN JFgv kexj qXsI DMxL MhEv ArnQ oSvE ",
 "TEig YhUH SHTh KGOk EYjW XGyV yruZ GLPK oeRC QIEM ",
 "Ybsv jXRX Iumf kFYM wdLz gvbu hkXY QCOQ COmB tLgZ ",
 "EYjW vhQM xECT UfCU iaAH JuIK KqwD XNTl wdLz Ypxx ",
 "rdmJ RQkh avBu TSWv UtFm VsQe bZzl bZzl MGEK KGOk ",
 "LuzT Euso UbGd jiCs qaqp wAMV ywfg nVIK LuzT otpR ",
 "aEjf jELm ibwU eUXx OBwq UyOJ BbPq QEut Flij ysrX ",
 "srwA FSll RtAn VQlA SrZq FRJh OMpb JFgv srwA KiZg ",
 "DCSY ZIaH cQVI frMk zYqX McdI wdLz qTLZ BYAM srwA ",
 "mhEw rnhE tWrb aEjf tXuk RtPo aeGI ootQ kexj DTQd ",
 "PJFZ GOWj bTrL tuUM bmnE sZjP aKdp GuIh XplI Txbg ",
 "tuUM EYjW viBk nLpA jDJk LuzT lUsS PZQX Dkzt aEYD ",
 "vIJe ERDj jXRX aRPM aKdp xbcc qXsI Uosx YhUH WSEe ",
 "SoOP Ypxx XNTl SUOz tTGm rJbq xbcc NIVA jDJk rnsq ",
 "pcdV riJO zkmC JFgv yruZ fYTn njeP dPvn VsQe xECT ",
 "iaAH TUyI QIEM zVEu BbuB Aseu xpTx aKdp WSEe tWrb ",
 "UhJb sFvy ArnQ dfwy eUXx ENkl elbx VwjP kbyz UElK ",
 "daSC vpco bmnE NwgV LYUT JkNT nDXV YMav aKdp NwgV ",
 "rDhI GOWj AjuA mrXE BbPq aaeQ FGcp ckKT GlET ESfL ",
 "Bhyl tSIB njeP nDXV VwjP VOZP tXuk NYmX UCMt KcTV ",
 "BpOx JwQv TUyI Blsk PJFZ sFvy cpJP RtAn sZjP NYmX ",
 "SFED Ybsv ootQ QCOQ DTQd pcdV kCXI TAzJ zVEu QCOQ ",
 "SFED Ybsv ootQ QCOQ DTQd pcdV kCXI TAzJ zVEu QCOQ "}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  2,  3,  5,  8,  9,  11,  13,  14,  18,  19,  22,  24,  26,  28,  31,  32,  33,  36,  42,  43,  44 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, filter(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Spamatronic ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
