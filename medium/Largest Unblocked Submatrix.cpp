class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) 
    {
        vector<int>v1,v2;
        for(auto x:arr)
        {
            v1.push_back(x[0]);
            v2.push_back(x[1]);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        
        int k=arr.size();
        if(k==0)return n*m;
        int dx=max(v1[0]-1,n-v1[k-1]);
        int dy=max(v2[0]-1,m-v2[k-1]);
        
        for(int i=1;i<k;i++)
        {
            dx=max(dx,v1[i]-v1[i-1]-1);
            dy=max(dy,v2[i]-v2[i-1]-1);
        }
        //cout<<dx<<" "<<dy<<endl;
        return dx*dy;
    }
};
