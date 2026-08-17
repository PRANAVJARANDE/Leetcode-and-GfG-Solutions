class Solution {
  public:
    int minProd(vector<int>& a) {
        
        int mini=INT_MAX;
        for(auto x:a)mini=min(mini,x);
        if(mini>=0)return mini;
        
        int pp=1,np=1;
        int ncnt=0;
        int maxi=INT_MIN;
        for(auto x:a)
        {
            if(x>0)pp*=x;
            if(x<0)
            {
                np*=x;
                maxi=max(maxi,x);
            }
        }
        if(np>0)np/=maxi;
        return np*pp;
    }
};
