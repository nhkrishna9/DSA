class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++ ){
                if(arr[j] > arr[i]){
                    swap(arr[j], arr[i]);
                }
            }
        }
    }
};