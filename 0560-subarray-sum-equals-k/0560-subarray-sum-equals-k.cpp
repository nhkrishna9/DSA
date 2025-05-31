class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> sumToSumAtIdx;
        int sum=0, ans=0;
        for(int i=0; i<arr.size();i++){
            sum = sum + arr[i];
            if(sum == k){
                ans = i + 1;
            }
            if(sumToSumAtIdx.find(sum-k) != sumToSumAtIdx.end()){
                int temp = i-sumToSumAtIdx[sum-k];
                ans = max(ans, temp);
            }
            if(sumToSumAtIdx.find(sum) == sumToSumAtIdx.end()){
                sumToSumAtIdx[sum] = i;
            }
        }
        return ans;
    }
};