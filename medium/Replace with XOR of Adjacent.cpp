class Solution {
  public:
    void replaceElements(vector<int>& arr) 
    {
        int n=arr.size();
        int p1=-1,p2=-1;
        int n1=arr[1],n2=-1;
        if(2<n)n2=arr[2];
        
        for(int i=0;i<n;i++)
        {
            int val=arr[i];
            
            if(i==0)
            {
                arr[i]=arr[i]^n1;
            }
            else if(i==n-1)
            {
                arr[i]=arr[i]^p1;
            }
            else
            {
                arr[i]=p1^n1;
            }
            p2=p1;
            p1=val;
            n1=n2;
            if(i+3<n)n2=arr[i+3];
            else n2=-1;
        }
    }
};
