// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int* maxSumArr = new int[n];
        
        maxSumArr[0] = arr[0];
        maxSumArr[1] = max(arr[0], arr[1]);
        
        for(int i=2; i<n; i++){
            if(maxSumArr[i-1] < arr[i]+maxSumArr[i-2]){
                maxSumArr[i] = arr[i]+maxSumArr[i-2];        
            }
            else{
                maxSumArr[i] = maxSumArr[i-1];
            }
        }
        
        return maxSumArr[n-1];
    }
};