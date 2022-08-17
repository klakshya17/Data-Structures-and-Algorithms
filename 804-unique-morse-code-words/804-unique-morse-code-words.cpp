class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
         
        map<char, string> mp = {{'a',".-"},
                                {'b',"-..."},
                                {'c',"-.-."},
                                {'d',"-.."},
                                {'e',"."},
                                {'f',"..-."},
                                {'g',"--."},
                                {'h',"...."},
                                {'i',".."},
                                {'j',".---"},
                                {'k',"-.-"},
                                {'l',".-.."},
                                {'m',"--"},
                                {'n',"-."},
                                {'o',"---"},
                                {'p',".--."},
                                {'q',"--.-"},
                                {'r',".-."},
                                {'s',"..."},
                                {'t',"-"},
                                {'u',"..-"},
                                {'v',"...-"},
                                {'w',".--"},
                                {'x',"-..-"},
                                {'y',"-.--"},
                                {'z',"--.."}
                               };
        
        set<string> ans;
        for(int i=0 ; i<words.size() ; i++){
            string s = words[i];
            string temp  = "";
            for(int j=0 ; j<s.size() ; j++){
                for(auto k:mp){
                    if(k.first == s[j]){
                        temp+=k.second;
                    }
                }
                
            }
            ans.insert(temp);
            temp = "";
        }
        
        return ans.size();
    }
};