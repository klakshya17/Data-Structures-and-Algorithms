class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        //start by making the vector of pairs(captainRatios,quality)
        vector<pair<double,int>> captainRatios;
        for(int i=0;i<quality.size();i++){
            double ratio = (double)wage[i]/(double)quality[i];
            captainRatios.push_back({ratio,quality[i]});
            // cout<<captainRatios[i].first<<" ";
        }
        
        //sort the captainRatios
        sort(captainRatios.begin(),captainRatios.end());
        
        //make at        priority_queue<int> pq;
        priority_queue<int> pq;
        double sum = 0;
        for(int i=0;i<k;i++){
            pq.push(captainRatios[i].second);
            sum+=captainRatios[i].second;
        }
        //cout<<sum<<endl;
        double ans = sum*captainRatios[k-1].first; //final answer
       // cout<<ans<<endl<<endl;
        for(int i=k;i<quality.size();i++){
            // cout<<"Top Element "<<pq.top()<<" current quant "<<captainRatios[i].second<<endl;
            if( pq.top()>captainRatios[i].second){
                sum-=pq.top();
                pq.pop();
                sum+=captainRatios[i].second;
                pq.push(captainRatios[i].second);
                 //cout<<sum<<endl;
            double minwage = (sum)*(captainRatios[i].first);
            // string s="Captain "+to_string(i)+": sum is "+to_string(sum)+" ratio is "+to_string(captainRatios[i].first)+" Wage is "+to_string(minwage);
            //cout<<s<<endl<<endl;
            ans = min(minwage,ans);
            }
           
        }
        return ans;
    }
};