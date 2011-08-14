#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

const int MAXVAL = 500000;
double prob_amount[MAXVAL+1];
double temp_prob_amount[MAXVAL+1];
int apples[50][50];
class RandomApple {
	public:
	vector <double> theProbability(vector <string> hundred, vector <string> ten, vector <string> one) {
		int n = hundred.size();
        int k = hundred[0].size();
        for (int box=0; box<n; ++box) {
            for (int kind=0; kind<k; ++kind) {
                apples[box][kind] = 100*(hundred[box][kind]-'0')
                    + 10*(ten[box][kind]-'0') + (one[box][kind]-'0');
            }
        }
        memset(prob_amount, 0, sizeof prob_amount);
        prob_amount[0] = 1.0;
        for (int box=0; box<n; ++box) {
            int box_total = 0;
            for (int kind=0; kind<k; ++kind) {
                box_total += apples[box][kind];
            }
            for (int old_amount=MAXVAL; old_amount>=0; --old_amount) {
                // added a new box which has a 50% chance of being chosen in a subset
                prob_amount[old_amount] /= 2.0; 
                if (old_amount + box_total <= MAXVAL) {
                    prob_amount[old_amount+box_total] += prob_amount[old_amount];
                }
            }
        }
        
        vector<double> sol(k, 0.0);
        for (int box=0; box<n; ++box) {
            int box_total = 0;
            for (int kind=0; kind<k; ++kind) {
                box_total += apples[box][kind];
            }
            memcpy(temp_prob_amount, prob_amount, sizeof temp_prob_amount);
            // temp_prob_amount should have the probability that 
            // a certain total amount of apples is chosen without
            // using box 'box' - basically undo one step of the previous
            // calculation
            for (int old_amount=0; old_amount<=MAXVAL; ++old_amount) {
                if (old_amount+box_total <= MAXVAL) {
                    temp_prob_amount[old_amount+box_total] -= temp_prob_amount[old_amount];
                }
                temp_prob_amount[old_amount] *= 2.0;
            }
            // calculate the probability that with some amount of apples
            // from the other boxes, an apple from 'box' is ultimately
            // chosen
            double prob_apple_from_box_chosen = 0.0;
            for (int old_amount=0; old_amount<=MAXVAL; ++old_amount) {
                prob_apple_from_box_chosen += temp_prob_amount[old_amount] * box_total / (old_amount + box_total);
            }
            
            // now for each kind of apple, calculate the probability that
            // an apple of that kind is chosen from 'box' when an apple
            // is chosen from 'box'
            for (int i=0; i<k; ++i) {
                sol[i] += prob_apple_from_box_chosen * apples[box][i] / box_total;
            }
        }
        
        double sum = accumulate(sol.begin(), sol.end(), 0.0);
        for (int i=0; i<k; ++i) {
            sol[i] /= sum;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"58"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.38461538461538464, 0.6153846153846154 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"00", "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"21", "11"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.5888888888888889, 0.4111111111111111 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0000", "0000", "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2284", "0966", "9334"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1090", "3942", "4336"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.19685958571981937, 0.24397246802233483, 0.31496640865458775, 0.24420153760325805 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"01010110", "00011000", "00001000", "10001010", "10111110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"22218214", "32244284", "68402430", "18140323", "29043145"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"87688689", "36101317", "69474068", "29337374", "87255881"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.11930766223754977, 0.14033271060661345, 0.0652282589028571, 0.14448118133046356, 0.1981894622733832, 0.10743462836879789, 0.16411823601857622, 0.06090786026175882 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, theProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {1.0, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, theProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RandomApple ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
