class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            long long dis = (((points[i][0])*(points[i][0]))+((points[i][1])*(points[i][1])));
            // cout<<dis<<" ";
            pq.push(make_pair(dis,i));
        }
        while(k--){
            v.push_back(points[pq.top().second]);
            pq.pop();
        }
        return v;
    }
};