class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) 
    {
        int n=men.size();
        vector<int>wpt(n,-1),mpt(n,-1);
        vector<int>next(n,0);
        
        queue<int>free_men;
        for(int i=0;i<n;i++)free_men.push(i);
        
        vector<int>nx(n,0);
        
        while(!free_men.empty())
        {
            int m=free_men.front();
            free_men.pop();
            
            int w=men[m][nx[m]];
            nx[m]++;
            
            if(wpt[w]==-1)
            {
                wpt[w]=m;
                mpt[m]=w;
            }
            else
            {
                bool flag=0;
                for(int i=0;i<women[w].size();i++)
                {
                    if(women[w][i]==m)
                    {
                        flag=1;
                        break;
                    }
                    if(women[w][i]==wpt[w])break;
                }
                
                if(flag)
                {
                    free_men.push(wpt[w]);
                    mpt[m]=w;
                    wpt[w]=m;
                }
                else
                {
                    free_men.push(m);
                }
            }
        }
        return mpt;
    }
    
};
