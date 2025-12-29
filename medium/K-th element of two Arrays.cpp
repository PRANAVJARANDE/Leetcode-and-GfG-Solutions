class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) 
    {
        int i=0,j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m)
        {
            k--;
            if(a[i]<b[j])
            {
                if(k==0)return a[i];
                i++;
            }
            else
            {
                if(k==0)return b[j];
                j++;
            }
        }
        while(i<n)
        {
            k--;
            if(k==0)return a[i];
            i++;
        }
        
        while(j<m)
        {
            k--;
            if(k==0)return b[j];
            j++;
        }
        
        return -1;
        
    }
};
