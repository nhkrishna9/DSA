class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);
    
    // Step 1: Prefix products
    for (int i = 1; i < n; ++i) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    
    // Step 2: Suffix products (using long long)
    long long suffixProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] = static_cast<int>(answer[i] * suffixProduct);
        suffixProduct *= nums[i];
    }
    
    return answer;
}
};