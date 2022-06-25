class Twitter {
public:
    Twitter() {
      
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(tweetId,userId));
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=0,i=tweets.size()-1;
        vector<int> v;
        while(count<10 && i>=0){
            if(tweets[i].second == userId || um[userId].find(tweets[i].second)!=um[userId].end()){
                v.push_back(tweets[i].first);
                count++;
            }
            i--;
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        um[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        um[followerId].erase(followeeId);
    }
    
private:
        vector<pair<int,int>> tweets;
      unordered_map<int,unordered_set<int>> um; 
   };

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */