class Solution {
  public:
  
    int minInsAndDel(vector<int> &a, vector<int> &b) 
    {
        int n=a.size();
        int m=b.size();
        
        vector<int>v1;
        for(auto x:a)
        {
            int in=lower_bound(b.begin(),b.end(),x)-b.begin();
            if(in!=m && x==b[in])v1.push_back(x);
        }
        
        vector<int>tp;
        for(auto x:v1)
        {
            int in=lower_bound(tp.begin(),tp.end(),x)-tp.begin();
            if(in!=tp.size())tp[in]=x;
            else tp.push_back(x);
        }
        
        
        int sz=tp.size();
        int ans=n-sz+m-sz;
        return ans;
        
        
        
        
    }
};
