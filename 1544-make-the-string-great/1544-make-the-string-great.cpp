class Solution {
public:
    string makeGood(string s) {
        if(s.size()<2)
            return s;
        // cout<<s<<endl;
        string ans="";
        int i=0;
          for(;i<s.size()-1;i++){
              if(s[i]==s[i+1]-32 || s[i]==s[i+1]+32)
                  i++;
              else ans+=s[i];
          }
        if(i==s.size()-1)
        ans+=s[s.size()-1];
        cout<<ans;
        if(ans.size()==s.size())
            return ans;
        else
            return makeGood(ans);
    }
};