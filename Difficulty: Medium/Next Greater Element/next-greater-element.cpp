class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // Initialize all answers with -1
        stack<int> st; // Stack to store next greater candidates

        for (int i = n - 1; i >= 0; i--) {
            // If stack is empty, no greater element to the right
            if (st.empty()) {
                ans[i] = -1;
            }
            else {
                // Pop all elements from stack smaller than or equal to arr[i]
                while (!st.empty() && st.top() <= arr[i]) {
                    st.pop();
                }

                // After popping, if stack is not empty, top is the next greater
                if (!st.empty()) {
                    ans[i] = st.top();
                }
                else {
                    ans[i] = -1; // No greater element found
                }
            }

            // Push current element for next iterations to use
            st.push(arr[i]);
        }

        return ans;
    }
};
