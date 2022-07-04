class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<2)
            return 1;
        vector<int> ans(ratings.size(),0);
        
        //setting initial 1s
        for(int i=1;i<ratings.size()-1;i++){
            if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1])
                ans[i]=1;
        }
        if(ratings[0]>ratings[1])
            ans[0]=1;
        if(ratings[ratings.size()-1]>ratings[ratings.size()-2])
            ans[ratings.size()-1]=1;
        
        //second iteration
        if(ratings[0]>ratings[1])
            ans[0]=max(ans[0],(ans[1]+1));
        for(int i=1;i<ratings.size()-1;i++){
            if(ratings[i]>ratings[i-1])
                ans[i]=max(ans[i-1]+1,ans[i]);
            if(ratings[i]>ratings[i+1])
                ans[i]=max(ans[i+1]+1,ans[i]);
        }
        if(ratings[ratings.size()-1]>ratings[ratings.size()-2])
            ans[ratings.size()-1]=max(ans[ratings.size()-1],ans[ratings.size()-2]+1);
        
        //last iteration
        if(ratings[ratings.size()-1]>ratings[ratings.size()-2])
            ans[ratings.size()-1]=max(ans[ratings.size()-1],ans[ratings.size()-2]+1);
        for(int i=ratings.size()-2;i>0;i--){
            if(ratings[i]>ratings[i-1])
                ans[i]=max(ans[i-1]+1,ans[i]);
            if(ratings[i]>ratings[i+1])
                ans[i]=max(ans[i+1]+1,ans[i]);
        }
        if(ratings[0]>ratings[1])
            ans[0]=max(ans[0],(ans[1]+1));
        
        
        int sum=0;
        for(int i=0;i<ans.size();i++){
            // cout<<ratings[i]<<" "<<ans[i]<<endl;
            sum+=ans[i];
        }
        return sum+ratings.size();
    }
};