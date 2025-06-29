class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto ele : arr) {
        minHeap.push(ele);
        if (minHeap.size() > k) {
            minHeap.pop(); // remove smallest
        }
    }

    while (!minHeap.empty()) {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    // ✅ Sort descending to match expected output
    sort(ans.begin(), ans.end(), greater<int>());

    return ans;
}
};