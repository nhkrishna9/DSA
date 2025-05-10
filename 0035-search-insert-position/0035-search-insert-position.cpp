class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                //target is greater than nums[mid]
                low = mid + 1;
            }

        }
        // In binary search, If a element is not present then low variable point to next possible greater than target.
        return low; //return high+1; also works.
    }
};