class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // Below is bubble sort solution which takes O(N^2)
        // But, we need to solve it in O(N).
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        */

        //O(N) solution
        int low=0, mid = 0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};