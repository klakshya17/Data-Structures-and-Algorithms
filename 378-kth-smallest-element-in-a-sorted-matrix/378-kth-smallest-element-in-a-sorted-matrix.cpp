class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int a=0,b=0;
        for(int i=0;i<matrix.size();i++){
            if(k<=0)
                break;
            for(int j=0;j<matrix[0].size();j++){
                pq.push(matrix[i][j]);
                k--;
                if(k<=0){
                    a=i;
                    b=j;
                    break;
                }
                // cout<<i<<j<<endl;
            }
        }
        cout<<a<<b;
        cout<<pq.top();
        for(int i=a;i<matrix.size();i++){
            if(matrix[i][0]>pq.top())
                break;
            int j;
            if(i==a)
                j=++b;
            else j=0;
            for(;j<matrix[0].size();j++){
                if(matrix[i][j]<pq.top()){
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
                if(matrix[i][j]>pq.top())
                    break;
            }
        }
        return pq.top();
    }
};