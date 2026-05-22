class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) 
    {
        int mx=1002;
        vector<int>dis(mx,INT_MAX);
        dis[start]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,start});
        
        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();
            
            if(cst>dis[in])continue;
            
            for(auto x:arr)
            {
                int ch=(x*in)%1000;
                if(dis[ch]>dis[in]+1)
                {
                    dis[ch]=dis[in]+1;
                    q1.push({dis[ch],ch});
                }
            }
            
        }
        if(dis[end]==INT_MAX)dis[end]=-1;
        return dis[end];
    }
};
