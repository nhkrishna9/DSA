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
    int totalFruit_o_n3(vector<int>& fruits) {
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

    bool hasAtMostTwoFruitTypes(const unordered_map<int, int>& basket) {
        return basket.size() <= 2;
    }

    void removeLeftFruitIfNeeded(unordered_map<int, int>& basket, vector<int>& fruits, int& left) {
        while (!hasAtMostTwoFruitTypes(basket)) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }
    }

    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // fruit -> count
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++; // pick fruit at right position
            removeLeftFruitIfNeeded(basket, fruits, left); // adjust window
            int currentFruits = right - left + 1;
            maxFruits = max(maxFruits, currentFruits);
        }

        return maxFruits;
    }
};