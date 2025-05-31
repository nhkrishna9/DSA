class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> numToFrequency;
        for(auto num : nums){
            numToFrequency[num]++;
        }

        int maxFreq = 0;
        for(auto& pair : numToFrequency){
            maxFreq = max(maxFreq, pair.second);
        }

        int total = 0;
        for(auto& pair : numToFrequency){
            if(pair.second == maxFreq) total += pair.second;
        }

        return total;
    }
};
