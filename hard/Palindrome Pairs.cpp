class Solution {
  public:
    
    bool ispalindrome(string s)
    {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])return 0;
        }
        return 1;
    }
    
    class Node{
      public:
        int flag;
        vector<Node*>next;
        
        Node()
        {
            flag=0;
            next=vector<Node*>(26,NULL);
        }
    };
    
    void insert_trie(string s,Node* root)
    {
        Node* temp=root;
        for(auto x:s)
        {
            if(!temp->next[x-'a'])temp->next[x-'a']=new Node();
            temp=temp->next[x-'a'];
        }
        temp->flag++;
    }
    
    bool find_trie(string s,Node* root)
    {
        Node* temp=root;
        for(auto x:s)
        {
            if(!temp->next[x-'a'])return 0;
            temp=temp->next[x-'a'];
        }
        return temp->flag;
    }
    
    void remove_trie(string s,Node*root)
    {
        Node* temp=root;
        for(auto x:s)
        {
            if(!temp->next[x-'a'])return;
            temp=temp->next[x-'a'];
        }
        temp->flag=(temp->flag)-1;
    }
    
    bool palindromePair(vector<string>& a) 
    {
        
        Node* root=new Node();
        for(auto x:a)
        {
            reverse(x.begin(),x.end());
            insert_trie(x,root);
        }
        
        for(auto s:a)
        {
            int n=s.size();
            string rev=s;
            reverse(rev.begin(),rev.end());
            remove_trie(rev,root);
            if(find_trie(s,root))return 1;
            
            for(int j=n-1;j>=0;j--)
            {
                if(ispalindrome(s.substr(j)) && find_trie(s.substr(0,j),root))
                {
                    return 1;
                }
                if(ispalindrome(s.substr(0,j)) && find_trie(s.substr(j),root))
                {
                    return 1;
                }
            }
            
            insert_trie(rev,root);
        }
        return 0;
        
    }
};
