class Solution {
public:
    bool isAnagram(string s, string t) {

        //sort(s.begin(), s.end());
        //sort(t.begin(), t.end());
        //return s ==t;

        unordered_map<char, int> count;
        for(auto tmpChar:s){
            count[tmpChar]++;
        }

        for(auto tmpChar:t){
            count[tmpChar]--;
        }

        for(auto tmpCountOfChar:count){
            if(tmpCountOfChar.second != 0){
                return false;
            }
        }
        return true;


        
    }
};