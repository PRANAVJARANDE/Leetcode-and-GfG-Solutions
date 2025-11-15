class Solution {
public:

    void update(int node,int i,int j,vector<int>&tree,int in,int val)
    {
        if(i==j)
        {
            tree[node]=val;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,tree,in,val);
        else update(2*node+2,mid+1,j,tree,in,val);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int query(int node,int i,int j,vector<int>&tree,int l,int r)
    {
        if(l<=i && j<=r)return tree[node];
        if(r<i || j<l)return 0;
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
    }

    vector<int> canSeePersonsCount(vector<int>& a) 
    {
        int n=a.size();
        vector<int>nmaxi(n,0);
        stack<int>s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && a[s1.top()]<a[i])s1.pop();
            if(s1.empty())nmaxi[i]=n;
            else nmaxi[i]=s1.top();
            s1.push(i);
        }
        
        int sz=n+1;
        vector<int>ans(n,0);
        vector<int>tree(4*sz,0);
        while(!s1.empty())s1.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)
            {
                ans[i]=query(0,0,sz-1,tree,i+1,nmaxi[i]);
            }
            while(!s1.empty() && a[s1.top()]<a[i])
            {
                update(0,0,sz-1,tree,s1.top(),0);
                s1.pop();
            }
            s1.push(i);
            update(0,0,sz-1,tree,i,1);
        }
        return ans;
    }
};
