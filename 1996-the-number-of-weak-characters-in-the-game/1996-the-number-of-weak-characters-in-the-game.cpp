/*
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
    
        sort(properties.begin(), properties.end(), []( vector<int>& a, vector<int>& b)
             {
                 if( a[0] == b[0]) 
                    return (a[1] > b[1]); 
                 else
                     return (a[0] < b[0]);
             });
         int maxi = 0 ;   
         int count = 0;

          for (int i = n-1; i >= 0; i--)
          {
             if (properties[i][1] < maxi) 
                    count++;
               maxi = max(maxi, properties[i][1]);
          }
          return count ;
                                                                          
    }
};
*/

//sabse pehle ham properties ko sort karege incresing order me attack ke hisaab se
//jab attack same ho to sort acc to defense  

//Sort benefit = attack ke according ab nhi dekhna pdega
//defense ke according dekhenge

//Now next greater left strategy follow karege or jab ham smaller element pop kar
//rahe honge defense ke hisaab se to count bhi increase kar denge kyuki wo hi weak character honge
//and they pop hote jaege saath saath to baar baar count bhi nahi honge

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        stack<int> st;
        int count = 0;
        
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b)
             {
                 if( a[0] == b[0]) 
                    return (a[1] > b[1]); 
                 else
                     return (a[0] < b[0]);
             });
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && properties[st.top()][1] < properties[i][1])
            {
                st.pop();
                count++;
            }
            
            st.push(i);
        }
        return count;
                                                                          
    }
};



