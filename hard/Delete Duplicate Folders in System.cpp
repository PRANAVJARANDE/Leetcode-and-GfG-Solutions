class Solution {
public:

    class Node{
        public:
            string name;
            map<string,Node*>next;
            string serial;
            Node(string name)
            {
                serial="";
                this->name=name;
            }
    };

    map<string,int>cnt;
    void serialize(Node* root)
    {
        if(root->next.empty())return;
        vector<string>temp;
        for(auto x:root->next)
        {
            serialize(x.second);
            temp.push_back(x.first +"("+((x.second)->serial)+")");
        }
        sort(temp.begin(),temp.end());
        for(auto x:temp)root->serial+=x;
        cnt[root->serial]++;
    }

    vector<vector<string>>ans;
    void helper(Node* root,vector<string>&v1)
    {
        if(!root->next.empty() && cnt[root->serial]>=2)return;
        v1.push_back(root->name);
        ans.push_back(v1);
        for(auto x:root->next)
        {
            helper(x.second,v1);
        }
        v1.pop_back();
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) 
    {
        Node* root=new Node("");
        for(auto x:paths)
        {
            Node* temp=root;
            for(auto y:x)
            {
                if(temp->next.find(y)==temp->next.end())temp->next[y]=new Node(y);
                temp=temp->next[y];
            }
        }
        serialize(root);
        vector<string>v1;
        for(auto x:root->next)
        {
            helper(x.second,v1);
        }

        return ans;
    }
};
