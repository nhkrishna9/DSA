class Solution {
public:
    void reverseHelper(vector<char>& s, int low, int high){
        if(low > high) return;
        swap(s[low], s[high]);
        reverseHelper(s, low+1, high-1);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        int low=0, high=n-1;
        reverseHelper(s, low, high);
        /*
        while(low<=high){
            s[high] = s[low]+s[high] - (s[low]=s[high]);
            low++;high--;
        }
        */
    }
};