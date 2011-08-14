#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

enum type {
	UNK, INT, STR, NA
};
type constantStr = STR;
type constantInt = INT;
type notAvailType = NA;

string t2s(type t) {
	switch (t) {
		case UNK: return "UNK"; break;
		case INT: return "int"; break;
		case STR: return "string"; break;
		case NA: return "NA"; break;
		default: cerr << t << '\n'; assert(0);
	}
	return "-1";
}
bool sw(const string &s, const string &t) {
	if (t.size() > s.size())
		return false;

	for (int i=0; i<(int)t.size(); ++i)
		if (s[i] != t[i])
			return false;

	return true;
}
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
vector< map<char, int> > ind;
vector< vector<type> > varType;
vector< vector<char> > varName;
vector<int> params;
map<char, int> fInd;
vector<char> fName;
vector<type> retType;

void typeUnify(type &a, type &b) {
	//cerr << "***" << a << "***\n";
	//cerr << "***" << b << "***\n";
	//cerr << t2s(a) << ' '; cerr << t2s(b) << '\n';
	if (a==b || a==NA || b==NA)
		return;

	if (b == INT)
		a = INT;
	else if (b == STR)
		a = STR;
	else if (b==UNK && a!=UNK)
		b = a;
}
type& rhsType(const string &rhs, int scope) {
	//cerr << rhs << ' ' << scope << '\n';
	// STR constant
	if (rhs.at(0) == '"')
		return constantStr;

	// INT constant
	if (isdigit(rhs.at(0)))
		return constantInt;

	// function call
	if (rhs.size()>1 && rhs[1]=='(') {
		char fn = rhs[0];
		//cerr << "fname " << fn << '\n';
		if (fInd.count(fn) == 0)
			return notAvailType;
		int fi = fInd[fn];

		string args;
		for (int i=2; rhs[i]!=')'; ++i)
			args += rhs[i];
		vector<string> pars = cutUp(args, ",");

		assert((int)pars.size() == params[fi]);

		for (int i=0; i<(int)pars.size(); ++i) {
			assert(pars[i].size() == 1);
			char nvar = pars[i][0];
			//cerr << "param " << nvar << '\n';
			if (ind.at(scope).count(nvar) == 0) {
				//cerr << "novo\n";
				ind.at(scope)[nvar] = varType.at(scope).size();
				varType.at(scope).push_back(UNK);
				varName.at(scope).push_back(nvar);
			}
			typeUnify(varType.at(scope)[ind.at(scope)[nvar]], varType.at(fi).at(i));
			//cerr << varType.at(scope)[ind.at(scope)[nvar]] << ' ' << varType.at(fi).at(i) << '\n';
		}

		return retType[fi];
	}

	// asignment
	if (rhs.size() == 1) {
		char nvar = rhs.at(0);

		//cerr << "isAsignment\n";
		if (ind.at(scope).count(nvar) == 0) {
			//cerr << "new var\n";
			ind.at(scope)[nvar] = varType.at(scope).size();
			varType.at(scope).push_back(UNK);
			varName.at(scope).push_back(nvar);
		}

		//cerr << ind.at(scope)[nvar] << '\n';
		//cerr << "vraca " << t2s(varType.at(scope)[ind.at(scope)[nvar]]) << '\n';
		return varType.at(scope)[ind.at(scope)[nvar]];
	}

	// expression
	assert(rhs.size() == 3);
	char left, right, op;
	left = rhs[0];
	op = rhs[1];
	right = rhs[2];

	if (ind[scope].count(left) == 0) {
		ind[scope][left] = varType[scope].size();
		varType[scope].push_back(UNK);
		varName[scope].push_back(left);
	}
	if (ind[scope].count(right) == 0) {
		ind[scope][right] = varType[scope].size();
		varType[scope].push_back(UNK);
		varName[scope].push_back(right);
	}

	if (op=='*' || op=='/') {
		varType[scope][ind[scope][left]] = INT;
		varType[scope][ind[scope][right]] = INT;

		return constantInt;
	}
	typeUnify(varType[scope][ind[scope][left]], varType[scope][ind[scope][right]]);
	//cerr << t2s(varType[scope][ind[scope][left]]) << '\n';

	//cerr << "vraca " << t2s(varType[scope][ind[scope][left]]) << '\n';
	return varType[scope][ind[scope][left]];
}
void go(vector<string> &program, int x, int fi) {
	while (1) {
		++x;
		//cerr << program[x] << '\n';
		if (sw(program[x], "return")) {
			typeUnify(retType.at(fi), rhsType(program[x].substr(7), fi));
			return;
		} else if (program[x][1] == ':') { // var definition
			;//typeUnify(rhsType(program[x].substr(0, 1), fName.size()-1), (program[x].substr(2)=="int" ? constantInt : constantStr));
		} else { // asignment
			//cerr << "isGlobalAssignment\n";
			type& t1 = rhsType(program[x].substr(0, 1), fi);
			//cerr << "lijevi " << t1 << '\n';
			type& t2 = rhsType(program[x].substr(2), fi);
			//cerr << "desni " << t2 << '\n';

			//cerr << "povratak " << t1 << ' ' << t2 << '\n';
			typeUnify(t1, t2);
			/*typeUnify(rhsType(program[x].substr(0, 1), fName.size()-1), rhsType(program[x].substr(2), fName.size()-1));*/
		}
	}
}
void go1(vector<string> &program, int x) {
	assert(sw(program[x], "function"));
	int j = string("function ").size();
	char fn = program[x][j];

	fInd[fn] = ind.size();
	fName.push_back(fn);
	ind.push_back(map<char, int>());
	varType.push_back(vector<type>());
	varType.back().reserve(200);
	varName.push_back(vector<char>());
	varName.back().reserve(200);
	params.push_back(0);
	retType.push_back(UNK);

	j += 2;
	string par;
	while (program[x][j] != ')')
		par += program[x][j++];

	if (j < (int)program[x].size()-1)
		retType.back() = (program[x].substr(j+2) == "int" ? INT : STR);

	vector<string> pp = cutUp(par, ",");
	params.back() = pp.size();
	for (int i=0; i<(int)pp.size(); ++i) {
		ind.back()[pp[i][0]] = varType.back().size();
		varType.back().push_back(UNK);
		varName.back().push_back(pp[i][0]);
		if (pp[i].size() > 1)
			varType.back().back() = (pp[i].substr(2) == "int" ? INT:STR);
	}
	while (1) {
		++x;
		//cerr << program[x] << '\n';
		if (sw(program[x], "return")) {
			typeUnify(retType.back(), rhsType(program[x].substr(7), fName.size()-1));
			return;
		} else if (program[x][1] == ':') { // var definition
			typeUnify(rhsType(program[x].substr(0, 1), fName.size()-1), (program[x].substr(2)=="int" ? constantInt : constantStr));
		} else { // asignment
			//cerr << "isGlobalAssignment\n";
			type& t1 = rhsType(program[x].substr(0, 1), fName.size()-1);
			//cerr << "lijevi " << t1 << '\n';
			type& t2 = rhsType(program[x].substr(2), fName.size()-1);
			//cerr << "desni " << t2 << '\n';

			//cerr << "povratak " << t1 << ' ' << t2 << '\n';
			typeUnify(t1, t2);
			/*typeUnify(rhsType(program[x].substr(0, 1), fName.size()-1), rhsType(program[x].substr(2), fName.size()-1));*/
		}
	}
}

class TCMinMin {
	public:
	vector <string> deduceTypes(vector <string> program) {
		ind.clear();
		varType.clear();
		params.clear();
		fInd.clear();
		retType.clear();
		fName.clear();
		varName.clear();
		ind.reserve(200);
		varType.reserve(200);
		params.reserve(200);
		retType.reserve(200);
		fName.reserve(200);
		varName.reserve(200);

		for (int i=0; i<1000; ++i) {
			int fi = 0;
			for (int j=0; j<(int)program.size(); ++j)
				if (sw(program[j], "function"))
					if (i)
						go(program, j, fi++);
					else
						go1(program, j);
		}

		vector<string> sol;
		for (int i=0; i<(int)ind.size(); ++i) {
			string s = "function ";
			s += fName[i];
			s += '(';
			for (int j=0; j<(int)params[i]; ++j) {
				if (j)
					s += ',';
				s += varName[i][j];
				s += ':';
				s += t2s(varType[i][j]);
			}
			s += "):" + t2s(retType[i]);

			sol.push_back(s);

			const map<char, int> &fVarInd = ind[i];
			for (map<char, int>::const_iterator it=fVarInd.begin(); it!=fVarInd.end(); ++it)
				if (it->second >= params[i])
					sol.push_back(it->first + string(":") + t2s(varType[i][it->second]));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"function f(a,b,c)",
	"e:int",
	"g=h(a)",
	"e=b+c",
	"return c",
"function h(p:string):string",
	"return p"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "function f(a:string,b:int,c:int):int",  "e:int",  "g:string",  "function h(p:string):string" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, deduceTypes(Arg0)); }
	void test_case_1() { string Arr0[] = {"function a()",
	"return 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "function a():int" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, deduceTypes(Arg0)); }
	void test_case_2() { string Arr0[] = {"function a(b:int):int",
	"c:int",
	"return c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "function a(b:int):int",  "c:int" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, deduceTypes(Arg0)); }
	void test_case_3() { string Arr0[] = {"function f(a,b,c)",
	"g=a(a)",
	"f=b+c",
	"return f",
"function a(a:string)",
	"return a",
"function b()",
	"a=f(b,a,c)",
	"a=0123456789012345678901234567890",
	"return a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "function f(a:string,b:int,c:int):int",  "f:int",  "g:string",  "function a(a:string):string",  "function b():int",  "a:int",  "b:string",  "c:int" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, deduceTypes(Arg0)); }
	void test_case_4() { string Arr0[] = {"function s(s)",
"s=s*s",
"return s",
"function f():int",
"a=f()",
"return b"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "function s(s:int):int",  "function f():int",  "a:int",  "b:int" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, deduceTypes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TCMinMin ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
