class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> tmp(sentence.begin(), sentence.end());
        for(char i='a';i<='z'; i++){
            if(tmp.contains(i)){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};