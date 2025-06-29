class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int index = 0;
        
        // Step 1: Build initial heap of first k+1 elements
        for (int i = 0; i <= k && i < arr.size(); ++i) {
            minHeap.push(arr[i]);
        }
        
        // Step 2: For remaining elements, pop and push
        for (int i = k + 1; i < arr.size(); ++i) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        
        // Step 3: Empty the heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};