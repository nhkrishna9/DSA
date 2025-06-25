#include <algorithm>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0;
        double curr = 0;
        double ans = 0;
        for(int i=0; i<k; i++){
            curr = curr + nums[i];
        }
        ans = curr/k;
        for(int i=k; i<n; i++){
            curr = curr - nums[i-k];
            curr = curr + nums[i];
            ans = max(ans, curr/k);
        }
        return ans;
        
    }
};