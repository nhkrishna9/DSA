class Solution {
public:
    bool check(vector<int>& fruits, int i, int j){
      unordered_set<int> s;
        for (int k = i; k <= j; k++) {
            s.insert(fruits[k]);
            if (s.size() > 2) return false;
        }
        return true;
        
    }
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check(fruits, i, j)){
                    ans = max(ans, j-i+1);
                }

            }
        }
        return ans;
        
    }
};