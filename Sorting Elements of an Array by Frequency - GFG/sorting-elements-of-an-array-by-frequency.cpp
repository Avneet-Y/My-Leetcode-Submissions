#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> vec;
	    int num;
	    for(int i=0; i<n; i++)
	    {
	        cin>>num;
	        vec.push_back(num);
	    }
	    unordered_map<int, int> mp;
	    for(int i=0; i<n; i++)
	    {
	        mp[vec[i]]++;
	    }
	    
	    sort(vec.begin(), vec.end(), [&](int a, int b)
	    {
	        return mp[a] != mp[b] ? mp[a] > mp[b] : a < b;
	    });
	    
	    for(int i=0; i<n; i++)
	    {
	        cout<<vec[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}