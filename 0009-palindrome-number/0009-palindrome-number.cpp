class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!= 0)){
            // Handling negative case and two digits with (<Non-Zero><Zero>) case
            return false;
        }
        int x_rev = 0;
        while(x>x_rev){
            x_rev = x_rev*10 + x%10;
            x = x/10;
        }
        if(x_rev == x || x_rev/10 == x){
            return true;
        }
        else{
            return false;
        }
        
    }
};