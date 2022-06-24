#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void fun(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int i=0;
    for(;i<k;i++)
        pq.push(v[i]);
    int j=0;
    for(;i<v.size();i++){
        v[j++]=pq.top();
        pq.pop();
        pq.push(v[i]);
    }
    while(!pq.empty()){
        v[j++] = pq.top();
        pq.pop();
    }
    print(v);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> v;
	    for(int i=0;i<n;i++){
	       int temp;
	       cin>>temp;
	       v.push_back(temp);
	    }
	    fun(v,k);
	}
	return 0;
}