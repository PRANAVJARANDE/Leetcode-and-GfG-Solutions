class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>v1;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)v1.push_back({mat[i][j],i,j});
        sort(v1.begin(),v1.end());
        vector<int>rmax(n,0),cmax(m,0);

        int ans=1;
        for(int i=0;i<v1.size();)
        {
            int val=v1[i][0];
            map<int,int>m1,m2;
            while(i<v1.size() && v1[i][0]==val)
            {
                int r=v1[i][1],c=v1[i][2];
                int cur=1+max(rmax[r],cmax[c]);
                ans=max(ans,cur);
                m1[r]=max(m1[r],cur);
                m2[c]=max(m2[c],cur);
                i++;
            } 
            for(auto x:m1)rmax[x.first]=x.second;
            for(auto x:m2)cmax[x.first]=x.second;
        }
        return ans;
    }
};
