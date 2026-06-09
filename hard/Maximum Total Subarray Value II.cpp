#define ll long long
class Solution {
public:

    void build(int node,int i,int j,vector<int>&nums,vector<int>&tree1,vector<int>&tree2)
    {
        if(i==j)
        {
            tree1[node]=nums[i];
            tree2[node]=nums[i];
            return;
        }
        ll mid=i+(j-i)/2;
        build(2*node+1,i,mid,nums,tree1,tree2);
        build(2*node+2,mid+1,j,nums,tree1,tree2);
        tree1[node]=max(tree1[2*node+1],tree1[2*node+2]);
        tree2[node]=min(tree2[2*node+1],tree2[2*node+2]);
    }

    pair<ll,ll> query(int node,int i,int j,int l,int r,vector<int>&tree1,vector<int>&tree2)
    {
        if(j<l || r<i)return {INT_MIN,INT_MAX};
        if(l<=i && j<=r)return {tree1[node],tree2[node]};
        ll mid=i+(j-i)/2;
        auto p1=query(2*node+1,i,mid,l,r,tree1,tree2);
        auto p2=query(2*node+2,mid+1,j,l,r,tree1,tree2);
        return {max(p1.first,p2.first),min(p1.second,p2.second)};
    }

    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>tree1(4*n,0),tree2(4*n,0);
        build(0,0,n-1,nums,tree1,tree2);
        
        map<pair<ll,ll>,ll>vis;
        vis[{0,n-1}]=1;

        priority_queue<pair<int,pair<int,int>>>q1;
        auto tp=query(0,0,n-1,0,n-1,tree1,tree2);
        q1.push({tp.first-tp.second,{0,n-1}});

        ll ans=0;
        while(!q1.empty() && k>0)
        {
            auto tp=q1.top();
            q1.pop();
            ans+=tp.first;
            k--;
            if(k==0)break;

            int l=tp.second.first;
            int r=tp.second.second;
            if(l!=r)
            {
                if(vis[{l+1,r}]==0)
                {
                    vis[{l+1,r}]=1;
                    auto temp1=query(0,0,n-1,l+1,r,tree1,tree2);
                    q1.push({temp1.first-temp1.second,{l+1,r}});
                }
                if(vis[{l,r-1}]==0)
                {
                    vis[{l,r-1}]=1;
                    auto temp2=query(0,0,n-1,l,r-1,tree1,tree2);
                    q1.push({temp2.first-temp2.second,{l,r-1}});
                }
            }
        }
        return ans;
    }
};
