#define ll long long
class Solution {
public:
    const ll INF=1e15;
    class Node{
        public:
            int id;
            vector<Node*>next;
        Node()
        {
            id=-1;
            next=vector<Node*>(26,NULL);
        }    
    };

    int nid;

    void insert(string&s,Node* root)
    {
        Node* temp=root;
        for(auto x:s)
        {
            if(!temp->next[x-'a'])temp->next[x-'a']=new Node();
            temp=temp->next[x-'a'];
        }
        if(temp->id==-1)temp->id=nid++;
    }


    int getid(string&s,Node* root)
    {
        Node* temp=root;
        for(auto x:s)
        {
            if(!temp->next[x-'a'])return -2;
            temp=temp->next[x-'a'];
        }
        return temp->id;
    }


    ll helper(ll in,string&s,string&tar,vector<vector<ll>>&adj,Node* root,vector<ll>&dp)
    {
        ll n=s.size();
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];

        ll ans=INF;
        if(s[in]==tar[in])ans=min(ans,helper(in+1,s,tar,adj,root,dp));

        Node* p1=root;
        Node* p2=root;
        for(ll j=in;j<n;j++)
        {
            if(!p1 || !p2)break;
            p1=p1->next[s[j]-'a'];
            p2=p2->next[tar[j]-'a'];
            if(!p1 || !p2)break;
            if(p1->id>=0 && p2->id>=0)
            {
                ll res=adj[p1->id][p2->id]+helper(j+1,s,tar,adj,root,dp);
                ans=min(ans,res);
            }
        }
        return dp[in]=ans;
    }

    
    ll minimumCost(string src,string tar,vector<string>&from,vector<string>&to,vector<int>&cost) 
    {
        nid=0;
        Node* root=new Node();
        for(auto x:from)insert(x,root);
        for(auto x:to)insert(x,root);
        
        vector<vector<ll>>adj(nid,vector<ll>(nid,INF));
        int sz=from.size();
        for(int i=0;i<sz;i++)
        {
            ll u=getid(from[i],root);
            ll v=getid(to[i],root);
            ll c=cost[i];
            adj[u][v]=min(adj[u][v],c);
            adj[u][u]=0;
            adj[v][v]=0;
        }

        for(int k=0;k<nid;k++)
        {
            for(int i=0;i<nid;i++)
            {
                for(int j=0;j<nid;j++)
                {
                    if(adj[i][k]!=INF && adj[k][j]!=INF)adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        vector<ll>dp(src.size(),-1);
        ll res=helper(0,src,tar,adj,root,dp);
        if(res==INF)res=-1;
        return res;
    }
};
