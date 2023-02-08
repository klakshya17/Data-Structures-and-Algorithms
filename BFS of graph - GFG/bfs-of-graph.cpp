//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> sol;
        vector<bool> visited(V+1,false);
        
            queue<int> q;
            // cout<<adj[i][0]<<endl;
            if(visited[0]==false && adj[0].size()>0)
            q.push(0);
            // else continue;
            visited[0]=true;
            
            while(q.empty()!=true){
                sol.push_back(q.front());
                for(int j=0;j<adj[q.front()].size();j++){
                    if(visited[adj[q.front()][j]] == false){
                        q.push(adj[q.front()][j]);
                        visited[adj[q.front()][j]] = true;
                    }
                }
                q.pop();
            }
        return sol;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends