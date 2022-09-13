class Solution {
public:
    bool solve(vector<int> &data, int i,int n){
        if(i == n){
            return true;
        }
        if((data[i]&(1<<7)) == 0){
            return solve(data,i+1,n);
        }
        else if(i<(n-1) && (data[i]&(1<<7)) != 0 && (data[i]&(1<<6)) != 0 && (data[i]&(1<<5)) == 0){
            if((data[i+1]&(1<<7)) != 0 && (data[i+1]&(1<<6)) == 0) return solve(data,i+2,n);
        }
        else if(i<(n-2) && (data[i]&(1<<7)) != 0 && (data[i]&(1<<6)) != 0 && (data[i]&(1<<5)) != 0 && (data[i]&(1<<4)) == 0){
            if((data[i+1]&(1<<7)) != 0 && (data[i+1]&(1<<6)) == 0 && (data[i+2]&(1<<7)) != 0 && (data[i+2]&(1<<6)) == 0) return solve(data,i+3,n);
        }
        else if(i<(n-3) && (data[i]&(1<<7)) != 0 && (data[i]&(1<<6)) != 0 && (data[i]&(1<<5)) != 0 && (data[i]&(1<<4)) != 0 && (data[i]&(1<<3)) == 0){
            if((data[i+1]&(1<<7)) != 0 && (data[i+1]&(1<<6)) == 0 && (data[i+2]&(1<<7)) != 0 && (data[i+2]&(1<<6)) == 0 && (data[i+3]&(1<<7)) != 0 && (data[i+3]&(1<<6)) == 0) return solve(data,i+4,n);
        }
        return false;
    }
    
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        return solve(data,0,n);
    }
};