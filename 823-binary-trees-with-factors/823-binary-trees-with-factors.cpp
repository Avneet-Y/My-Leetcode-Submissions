class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
         int n=arr.size();
        if(n==1)
            return 1;
        sort(arr.begin(),arr.end());
        
        map<int,long>m1;
        
        for(int a:arr)
        {
            m1[a]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int r=arr[i]/arr[j];
                    if(m1[r]>0)
                    {
                        m1[arr[i]]+=m1[arr[j]]*m1[r];
                    }
                }
            }
        }
        long  int sum=0;
        for(auto it:m1)
        {
            sum+=it.second;
        }
        return int(sum % 1000000007);
    }
};