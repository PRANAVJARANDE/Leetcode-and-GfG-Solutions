class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) 
    {
        int i=0,j=0,k=0;
        int n=a.size();
        int m=b.size();
        int o=c.size();
        
        vector<int>ans;
        while(i<n && j<m && k<o)
        {
            int mini=min(a[i],min(b[j],c[k]));
            
            int pv=INT_MAX;
            if(!ans.empty())pv=ans.back();
            
            if(pv!=a[i] && a[i]==b[j] && b[j]==c[k])
            {
                ans.push_back(a[i]);
            }
            if(mini==a[i])i++;
            else if(mini==b[j])j++;
            else k++;
        }
        return ans;
    }
};
