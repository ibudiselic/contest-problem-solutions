#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAXSUM 162
long long nums[19][MAXSUM+1];
long long sum_nums[MAXSUM+1];
long long starts[19][10][MAXSUM+1];

long long kth_with_sum(long long k, int S) {
    long long ret = 0;
    int maxlen = 18;
    while (S > 0) {
        long long total = 0;
        for (int dig=(ret==0); dig<min(10, S+1); ++dig) {
            long long cnt = 0;
            for (int len=1; len<=maxlen; ++len) {
                long long add = starts[len][dig][S];
                if (dig == 0) {
                    add = 0;
                    for (int suf=0; suf<len; ++suf) {
                        add += nums[suf][S];
                    }
                }
                cnt += add;
            }
            if (total + cnt >= k) {
                ret = ret*10 + dig;
                k -= total;
                --maxlen;
                S -= dig;
                break;
            }
            total += cnt;
        }
    }
    while (k-- > 1) {
        ret *= 10;
    }
    return ret;
}
class FoxAndSorting {
public:
    long long get(long long idx) {
        if (idx == 1) {
            return 0;
        }
        memset(nums, 0, sizeof nums);
        memset(starts, 0, sizeof starts);
        memset(sum_nums, 0, sizeof sum_nums);
        
        for (int i=0; i<10; ++i) {
            nums[1][i] = 1;
            starts[1][i][i] = 1;
        }
        for (int i=2; i<19; ++i) {
            for (int sum=0; sum<=MAXSUM; ++sum) {
                for (int d=1; d<min(10, sum+1); ++d) {
                    for (int j=1; j<i; ++j) {
                        nums[i][sum] += nums[j][sum-d]; // fill the rest with zeros
                        starts[i][d][sum] += nums[j][sum-d];
                    }
                }
            }
        }
        
        for (int sum=0; sum<=MAXSUM; ++sum) {
            sum_nums[sum] = 0;
            for (int i=1; i<19; ++i) {
                sum_nums[sum] += nums[i][sum];
            }
        }
        long long total = 0;
        int sum = 0;
        while (total + sum_nums[sum] < idx) {
            total += sum_nums[sum++];
        }
        
        return kth_with_sum(idx-total, sum);
    }
};
