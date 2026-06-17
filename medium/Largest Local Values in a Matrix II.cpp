class Solution {
public:

    void build(int node,int i,int j,vector<int>&tree,vector<int>&a)
    {
        if(i==j)
        {
            tree[node]=a[i];
            return;
        }
        int mid=i+(j-i)/2;
        build(2*node+1,i,mid,tree,a);
        build(2*node+2,mid+1,j,tree,a);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node,int i,int j,int l,int r,vector<int>&tree)
    {
        if(r<i || j<l)return INT_MIN;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,l,r,tree),query(2*node+2,mid+1,j,l,r,tree));
    }

    int countLocalMaximums(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>tree(n,vector<int>(4*m,0));
        for(int i=0;i<n;i++)build(0,0,m-1,tree[i],a[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)continue;
                int cmax=INT_MIN;
                for(int r=max(0,i-a[i][j]);r<=min(n-1,i+a[i][j]);r++)
                {
                    int lh=j-a[i][j];
                    int rh=j+a[i][j];
                    if(i==r)
                    {
                        if(j!=0)cmax=max(cmax,query(0,0,m-1,max(0,lh),j-1,tree[r]));
                        if(j!=m-1)cmax=max(cmax,query(0,0,m-1,j+1,min(m-1,rh),tree[r]));
                    }
                    else if(r==i-a[i][j] || r==i+a[i][j])
                    {
                        cmax=max(cmax,query(0,0,m-1,max(0,lh+1),min(m-1,rh-1),tree[r]));
                    }
                    else
                    {
                        cmax=max(cmax,query(0,0,m-1,max(0,lh),min(m-1,rh),tree[r]));
                    }
                }
                if(cmax<=a[i][j])ans++;
            }
        }
        return ans;
    }
};
