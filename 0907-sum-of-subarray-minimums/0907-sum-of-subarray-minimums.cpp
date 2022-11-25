class Solution {
public:
    vector<int> NSR(vector<int> &arr){
        vector<int> v;
        stack<pair<int,int>> stk;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(stk.empty())
                v.push_back(n);
            else
            {
                if(stk.top().first<=arr[i])
                    v.push_back(stk.top().second);
                else
                {
                    while(!stk.empty() and stk.top().first>arr[i])
                        stk.pop();
                    if(stk.empty())
                        v.push_back(n);
                    else
                        v.push_back(stk.top().second);
                }
            }
            stk.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<int> NSL(vector<int> &arr){
        vector<int> v;
        stack<pair<int,int>> stk;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(stk.empty())
                v.push_back(-1);
            else
            {
                if(stk.top().first<arr[i])
                    v.push_back(stk.top().second);
                else
                {
                    while(!stk.empty() and stk.top().first>=arr[i])
                        stk.pop();
                    if(stk.empty())
                        v.push_back(-1);
                    else
                        v.push_back(stk.top().second);
                }
            }
            stk.push({arr[i],i});
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        vector<int> nsl=NSL(arr);
        vector<int> nsr=NSR(arr);
        long long int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            long long int temp=((arr[i]%mod)*((nsr[i]-i)%mod))%mod;
            long long int t=((temp%mod)*((i-nsl[i])%mod))%mod;
            sum=(sum+t)%mod;
        }
        return sum;
    }
};