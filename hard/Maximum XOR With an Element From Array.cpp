class Solution {
public:

    class Node{
    public:
        vector<Node*>next;
        Node()
        {
            next=vector<Node*>(2,NULL);
        }
    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        Node* root=new Node();
        int in=0;
        for(auto &x:queries)
        {
            swap(x[0],x[1]);
            x.push_back(in++);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end());

        in=0;
        int n=nums.size();
        int sz=queries.size();
        vector<int>ans(sz,0);
        for(int i=0;i<sz;i++)
        {
            int m=queries[i][0],x=queries[i][1];
            while(in<n && nums[in]<=m)
            {
                Node* temp=root;
                for(int i=31;i>=0;i--)
                {
                    int tp=0;
                    if(nums[in] & (1<<i))tp=1;
                    if(!temp->next[tp])temp->next[tp]=new Node();
                    temp=temp->next[tp];
                }
                in++;
            }
            int res=0;
            Node* temp=root;
            bool flag=1;
            for(int i=31;i>=0;i--)
            {
                int tp=0;
                if(x & (1<<i))tp=1;
                if(temp->next[1-tp])
                {
                    temp=temp->next[1-tp];
                    res=res | (1<<i);
                }
                else if(temp->next[tp])
                {
                    temp=temp->next[tp];
                }
                else 
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)res=-1;
            ans[queries[i][2]]=res;
        }

        return ans;
    }
};
