class Solution {
public:
    bool helper(int mid, vector<int>& weights, int N, int days) {
        int sum = 0, d = 1;
        for (int i = 0; i < N; i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                d++;
                sum = weights[i]; // Reset sum for new day
            }
        }
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low < high) {
            int mid = low + (high - low) / 2; // avoid overflow

            if (helper(mid, weights, weights.size(), days)) {
                high = mid; // look for smaller capacity
            } else {
                low = mid + 1; // need larger capacity
            }
        }

        return low;
    }
};
