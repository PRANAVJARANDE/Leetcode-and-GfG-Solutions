class Solution {
public:

    void build(int node,int i,int j,vector<int>&tree,vector<int>&p1,vector<int>&p2)
    {
        if(i==j)
        {
            tree[node]=p1[i]+p2[i];
            return;
        }
        int mid=i+(j-i)/2;
        build(2*node+1,i,mid,tree,p1,p2);
        build(2*node+2,mid+1,j,tree,p1,p2);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node,int i,int j,vector<int>&tree,int l,int r)
    {
        if(l<=i && j<=r)return tree[node];
        if(r<i || j<l)return INT_MIN;
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,tree,l,r),query(2*node+2,mid+1,j,tree,l,r));
    }

    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) 
    {
        int n=nums1.size();
        vector<vector<int>>v1;
        for(int i=0;i<n;i++)v1.push_back({nums1[i],nums2[i]});
        sort(v1.begin(),v1.end());
        vector<int>p1,p2;
        for(auto x:v1)
        {
            while(!p2.empty() && p2.back()<=x[1])
            {
                p1.pop_back();
                p2.pop_back();
            }
            p1.push_back(x[0]);
            p2.push_back(x[1]);
        }

        int sz=p1.size();
        vector<int>tree(4*sz,0);
        build(0,0,sz-1,tree,p1,p2);

        reverse(p2.begin(),p2.end());

        vector<int>ans;
        for(auto x:queries)
        {
            int l=lower_bound(p1.begin(),p1.end(),x[0])-p1.begin();
            int r=lower_bound(p2.begin(),p2.end(),x[1])-p2.begin();
            r=sz-r-1;
            int res=-1;
            if(l<=r)res=query(0,0,sz-1,tree,l,r);
            ans.push_back(res);
        }
        return ans;
    }
};
