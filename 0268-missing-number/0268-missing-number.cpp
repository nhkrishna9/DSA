class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

    
        int ans=0;
        for(int i=0;i<=n;i++){
            ans = ans ^ i;
        }
/*
        for(const auto& num: nums){
            ans = ans ^ num;
        }

        return ans;
        
        */


    //std::reduce	Faster parallel-friendly alternative to accumulate (C++17)
    //std::bit_xor<>	Functional object for XOR operation
    //std::views::iota(0, n+1)	Lazy range generation from 0 to n (C++20 ranges)
    //No loops	Entire solution is declarative and clean

        // Compute XOR of all indices [0..n]. Leet code doesn't support C++20 constructs.
        // int expected = std::reduce(std::views::iota(0, n + 1), 0, std::bit_xor<>());

        // Compute XOR of all elements in nums
        //int actual = std::reduce(nums.begin(), nums.end(), 0, std::bit_xor<>());


        int actual = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>());


        return ans ^ actual;

    }
};