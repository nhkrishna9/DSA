class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=0, greatness=0;
        int n = nums.size();
        while(i<n && j < n){
            if(nums[j] > nums[i]){
                greatness++;
                i++;j++;
            }
            else{
                j++;
            }
        }
        return greatness;
    }
};