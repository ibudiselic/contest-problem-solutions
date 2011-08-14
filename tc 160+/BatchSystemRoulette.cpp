#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

double F[51];
class BatchSystemRoulette {
	public:
	vector <double> expectedFinishTimes(vector <int> duration, vector <string> user) {
        map<string, vector< pair<int, long long> > > tmp;
        for (int i=0; i<(int)user.size(); ++i) {
            tmp[user[i]].push_back(make_pair(i, duration[i]));
        }
        vector< pair<long long, vector< pair<int, long long> > > > V;
        for (map<string, vector< pair<int, long long> > >::const_iterator it=tmp.begin(); it!=tmp.end(); ++it) {
            const vector< pair<int, long long> > &v = it->second;
            long long sum = 0;
            for (int i=0; i<(int)v.size(); ++i) {
                sum += v[i].second;
            }
            V.push_back(make_pair(sum, it->second));
        }
        
        sort(V.begin(), V.end()); // to get the lowest average wait time over all users, the users get served in increasing order of their total job time
        /*for (int i=0; i<(int)V.size(); ++i) {
            for (int j=0; j<(int)V[i].second.size(); ++j) {
                cerr << V[i].second[j] << ' ';
            }
            cerr << "total: " << V[i].first << '\n';
        }*/
        
        vector<int> same_sum(V.size(), 0); // the order within groups of users that have the same total job time is random, i.e. any permutation is equally likely
        for (int i=0; i<(int)V.size(); ++i) {
            int j = i+1;
            while (j<(int)V.size() && V[i].first==V[j].first) {
                ++j;
            }
            for (int k=i; k<j; ++k) {
                same_sum[k] = j-i;
            }
            i = j-1;
        }
        /*for (int i=0; i<(int)V.size(); ++i) {
            cerr << i << ' '  << V[i].first << ' ' << same_sum[i] << '\n';
        }*/
        
        F[0] = 1.0;
        for (int i=1; i<51; ++i) {
            F[i] = F[i-1] * i;
        }

        long long S_done = 0;
        vector<double> sol(duration.size(), 0.0);
        for (int i=0; i<(int)V.size(); ++i) {
            if (i>0 && V[i].first!=V[i-1].first) {
                S_done += same_sum[i-1] * V[i-1].first;
            }
            int SS = same_sum[i];
            const vector< pair<int, long long> > &v = V[i].second;
            for (int k=0; k<SS; ++k) { // where in this user section
                // there are 1/SS ways for i to be in the kth slot in this user section ( (SS-1)!/(SS!) )
                for (int j=0; j<(int)v.size(); ++j) { // choose the job
                    int job_id = v[j].first;
                    for (int l=0; l<(int)v.size(); ++l) { // chose the pos for this job in this user's section
                        double contrib = S_done + k*V[i].first + duration[job_id];
                        if (l > 0) {
                            // since all the permutations of the remaining elements are eqaully likely
                            // the expected time of the previous l jobs is equal to the average time of
                            // all the jobs except job_id which is fixed at position l+1
                            contrib += double(V[i].first-duration[job_id]) / (v.size()-1) * l; // the time spent by the l previus jobs
                        }
                        sol[job_id] += contrib / SS / v.size();
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 2, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {6.0, 3.0, 10.0, 1.0 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 2, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"mac taylor", "Mac Taylor", "Mac Taylor", "Peyton Driscoll"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {4.0, 8.0, 9.0, 1.0 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13, 14, 15, 56, 56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Tim Speedle", "Tim Speedle", "Tim Speedle", "Horatio Caine", "YEEEAAAAAAAAAAH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {27.5, 28.0, 28.5, 126.0, 126.0 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, expectedFinishTimes(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BatchSystemRoulette ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
