class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int* tmp = new int[n+1];
        tmp[0] = 0;
        tmp[1] = 1;
        tmp[2] = 1;

        for (int i = 3; i <= n; i++) {
            tmp[i] = tmp[i-1] + tmp[i-2] + tmp[i-3];
        }

        int result = tmp[n];
        delete[] tmp; // Free memory
        return result;
    }
};
