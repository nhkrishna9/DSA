class Solution {
public:
Why this is optimal:
/*
A peak element is defined as nums[i] > nums[i - 1] && nums[i] > nums[i + 1].
Since the array may have multiple peaks, the goal is to find any one of them.
At any index mid, if nums[mid] < nums[mid+1], a peak must exist on the right.
If nums[mid] > nums[mid+1], a peak must exist on the left or could be mid.
This property lets us use binary search to eliminate half the array at each step, resulting in O(log n) time and O(1) space.
*/
/*
Why this works:
If nums[mid] < nums[mid+1], go right (low = mid+1) → peak lies to the right.
Else, go left (high = mid) → peak lies to the left or at mid.
Eventually, low == high, and we return it as the peak index.
*/


    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high){
            int mid = (low+high)/2;

            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
        
    }
};
