// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
    priority_queue<int> maxHeap;

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop(); // Remove the largest among the k+1
        }
    }

    return maxHeap.top(); // kth smallest
    }
};