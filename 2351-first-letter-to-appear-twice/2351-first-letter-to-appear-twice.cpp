class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for(char c:s){
            if(s.contains(c)){
                return c;
            }
            seen.insert(c);
        }
        return ' ';
        /*
        int n = s.size();
        for(int i=0; i<n; i++){
            char c = s[i];
            for(int j=0; j<i;j++){
                if(c == s[j]){
                    return c;
                }
            }
        } */
        //return ' ';
    }
};