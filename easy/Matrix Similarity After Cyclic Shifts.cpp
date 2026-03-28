class Solution {
public:
    bool areSimilar(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m=a[0].size();
        k=k%m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val;
                if(i%2)val=a[i][(j-k+m)%m];
                else val=a[i][(j+k)%m];
                if(a[i][j]!=val)return 0;
            }
        }
        return 1;
    }
};
