class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int low=0, high=n-1;
        while(low<=high){
            s[high] = s[low]+s[high] - (s[low]=s[high]);
            low++;high--;
        }
    }
};