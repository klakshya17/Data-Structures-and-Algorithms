class Solution {
public:
    string reorganizeString(string s) {        
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> um;
        for(int i=0;i<s.size();i++){
            um[s[i]]+=1;
        }
        for(auto i:um){
            pq.push(make_pair(i.second,i.first));
        }
        if(pq.top().first > (s.size()+1)/2)
            return "";
        pair<int,char> block,temp;
        for(int i=0;i<s.size();i++){
            // pq.push(block);
            temp = pq.top();
            s[i]=temp.second;
            temp.first--;
            pq.pop();
            if(i>0)
                pq.push(block);
            block = temp;
        }
        return s;
        
    }
};