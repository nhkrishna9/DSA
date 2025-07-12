class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        int* tmp = new int[n+1];
        tmp[0] = 1;
        tmp[1] = 1;
        for(int i=2; i<=n; i++){
            tmp[i] = tmp[i-1] + tmp[i-2];
        }
        return tmp[n];    
    }
};