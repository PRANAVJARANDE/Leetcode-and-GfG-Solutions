class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) 
    {
        int n=arr.size();
        int s=0;
        map<int,int>freq;
        int ans=0;
        for(int e=0;e<n;e++)
        {
            freq[arr[e]]++;
            while(freq.size()>k)
            {
                freq[arr[s]]--;
                if(freq[arr[s]]==0)freq.erase(arr[s]);
                s++;
            }
            ans+=e-s+1;
        }
        return ans;
        
    }
};
