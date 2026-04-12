class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<m;i++)
        {
            int r=0,c=i;
            int base=a[r][c];
            while(r<n && c<m)
            {
                if(base!=a[r][c])return 0;
                r++;
                c++;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            int r=i,c=0;
            int base=a[r][c];
            while(r<n && c<m)
            {
                if(base!=a[r][c])return 0;
                r++;
                c++;
            }
        }
        return 1;
        
        
    }
};
