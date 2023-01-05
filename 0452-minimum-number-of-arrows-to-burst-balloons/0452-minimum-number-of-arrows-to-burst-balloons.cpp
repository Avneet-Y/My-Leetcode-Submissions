//A balloon [1, 6] and a balloon [2, 9] can be replaced with one balloon [2, 6] because any arrow it this can burst both the balloons. check further balloons with this overlap as one 

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int start = points[0][0];
		int end = points[0][1];
        int arrow = 1;  //need atleast 1 arrow to burst the first balloon
        
        for(int i=1; i<n; i++)
        {
         //start of balloon is before end of the balloon, it means they coincide   	
           if(points[i][0] <= end)                 
           {                        
                start = max(start,points[i][0]); //intersection,start val more to the right
                end = min(end,points[i][1]);  // intersection,end value more to the left
           }
           else
           {	
                start = points[i][0];  //current doesnt coincide with other balloons 
                end = points[i][1];    //set start, end to the curr balloon and arrow++
                arrow++;
           }
        }
        return arrow;
    }
}; 