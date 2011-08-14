#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

const int Y0=1900;
long long parse(const char *s)
{
  long long ret_val = 0;
  int d, y, h, m, sec;
  char buff[5];
  
  sscanf(s, "%d", &d);
  if (d/10)
    ++s;
  s+=2;
  sscanf(s, "%s", buff);
  if (strcmp(buff, "")==0)
    sscanf(++s, "%s", buff);
  s += strlen(buff);
  sscanf(s, "%d", &y);
  s += 8;
  
  bool leap = (y%4==0)&&(y%100 || y%400==0);
  if (strcmp(buff, "Jan")==0)
    d+=0;
  else if (strcmp(buff, "Feb")==0)
    d+=31;
  else if (strcmp(buff, "Mar")==0)
    d+=31+28+leap;
  else if (strcmp(buff, "Apr")==0)
    d+=31+28+leap+31;
  else if (strcmp(buff, "May")==0)
    d+=31+28+leap+31+30;
  else if (strcmp(buff, "Jun")==0)
    d+=31+28+leap+31+30+31;
  else if (strcmp(buff, "Jul")==0)
    d+=31+28+leap+31+30+31+30;
  else if (strcmp(buff, "Aug")==0)
    d+=31+28+leap+31+30+31+30+31;
  else if (strcmp(buff, "Sep")==0)
    d+=31+28+leap+31+30+31+30+31+31;
  else if (strcmp(buff, "Oct")==0)
    d+=31+28+leap+31+30+31+30+31+31+30;
  else if (strcmp(buff, "Nov")==0)
    d+=31+28+leap+31+30+31+30+31+31+30+31;
  else if (strcmp(buff, "Dec")==0)
    d+=31+28+leap+31+30+31+30+31+31+30+31+30;
  
  ret_val += d*24*60*60;
  for (int i=Y0; i<y; ++i) {
    bool leap = (i%4==0)&&(i%100 || i%400==0);
    ret_val += (365+leap)*24*60*60;
  }
  sscanf(s, "%d:%d:%d", &h, &m, &sec);
  cerr << h << ' ' << m << ' ' << sec << ' ';
  s+=10;
  sscanf(s, "%s", buff);
  if (strcmp(buff, "PM")==0) {
    if (h!=12)
      h += 12;
  } else {
    assert(strcmp(buff, "AM")==0);
    if (h==12)
      h = 0;
  }
  ret_val += h*60*60 + m*60 + sec;
  return ret_val;
}
class Uptime {
  public:
  string calcUptime(string started, string now) {
    string sol;
    char buff[10];
    long long diff = parse(now.c_str())-parse(started.c_str());
    int d = diff/(24*60*60);
    diff %= 24*60*60;
    int h = diff/(60*60);
    diff %= 60*60;
    int m = diff/60;
    diff %= 60;
    
    if (d) {
      sprintf(buff, "%d", d);
      sol += buff;
      sol += 'd';
    }
    if (h) {
      if (d)
        sol += ' ';
      sprintf(buff, "%d", h);
      sol += buff;
      sol += 'h';
    }
    if (m) {
      if (d||h)
        sol += ' ';
      sprintf(buff, "%d", m);
      sol += buff;
      sol += 'm';
    }
    if (diff) {
      if (d||h||m)
        sol += ' ';
      sprintf(buff, "%lld", diff);
      sol += buff;
      sol += 's';
    }
    return sol;
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7 Jun 2004 at 04:41:32 PM"; string Arg1 = "8 Jun 2004 at 07:16:28 PM"; string Arg2 = "1d 2h 34m 56s"; verify_case(0, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "7 Jun 2004 at 04:41:32 PM"; string Arg1 = "7 Jun 2004 at 04:41:32 PM"; string Arg2 = ""; verify_case(1, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "28 Feb 2004 at 01:23:45 PM"; string Arg1 = "1 Mar 2004 at 12:34:56 AM"; string Arg2 = "1d 11h 11m 11s"; verify_case(2, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "28 Feb 2005 at 01:23:45 PM"; string Arg1 = "1 Jan 2015 at 12:34:56 AM"; string Arg2 = "3593d 11h 11m 11s"; verify_case(3, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "25 Jan 1922 at 05:58:52 AM"; string Arg1 = "26 Feb 2190 at 11:53:14 AM"; string Arg2 = "97918d 5h 54m 22s"; verify_case(4, Arg2, calcUptime(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Uptime ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
