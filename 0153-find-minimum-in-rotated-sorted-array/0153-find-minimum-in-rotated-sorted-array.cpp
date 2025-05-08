class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high = n-1, mid = (low+high)/2;
        while(low<high){
            int mid = (low+high) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
        
    }
};