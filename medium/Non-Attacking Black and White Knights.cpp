class Solution {
  public:
    
    vector<int>dx{2,2,-2,-2,1,1,-1,-1};
    vector<int>dy{1,-1,1,-1,2,-2,2,-2};
    
    int n,m;
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int numOfWays(int n, int m) {
        this->n=n;
        this->m=m;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                for(int z=0;z<8;z++)
                {
                    if(issafe(i+dx[z],j+dy[z]))cnt++;
                }
                //cout<<cnt<<endl;
                ans+=((n*m)-cnt-1);
            }
        }
        return ans;
    }
};
