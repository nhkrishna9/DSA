/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int, int> sumToSumAtIdx;
        int sum=0, ans=0;
        for(int i=0; i<arr.size();i++){
            sum = sum + arr[i];
            if(sum == 0){
                ans = i + 1;
            }
            else if(sumToSumAtIdx.find(sum) != sumToSumAtIdx.end()){
                int temp = i-sumToSumAtIdx[sum];
                ans = max(ans, temp);
            }
            else{
                sumToSumAtIdx[sum] = i;
            }
        }
        return ans;
    }
};