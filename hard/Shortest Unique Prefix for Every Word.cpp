class Solution {
  public:
    
    class Node{
    public:
        int cnt;
        vector<Node*>next;
        Node()
        {
            cnt=0;
            next=vector<Node*>(26,NULL);
        }
    };
  
    vector<string> findPrefixes(vector<string>& arr) 
    {
        Node* root=new Node();
        
        for(auto s:arr)
        {
            Node* temp=root;
            for(auto c:s)
            {
                if(!temp->next[c-'a'])temp->next[c-'a']=new Node();
                temp=temp->next[c-'a'];
                temp->cnt++;
            }
        }
        
        vector<string>ans;
        for(auto s:arr)
        {
            Node* temp=root;
            int in=0;
            bool flag=0;
            for(auto c:s)
            {
                temp=temp->next[c-'a'];
                if(temp->cnt==1)
                {
                    flag=1;
                    ans.push_back(s.substr(0,in+1));
                    break;
                }
                in++;
            }
            if(flag==0)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
