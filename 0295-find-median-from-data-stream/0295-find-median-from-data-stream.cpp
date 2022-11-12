/*

class MedianFinder {
public:
    
    priority_queue<int> small;  
    priority_queue<int, vector<int>, greater<int>> large; //hs half larger elements 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);
        
        // if largest element of smaller is greater than the smallest element of larger, then push the top of smaller into larger
        if(small.size() > 0 && large.size() > 0 && small.top() > large.top())
        {
            int ele = small.top();
            small.pop();
            large.push(ele);
        }
        
        if(small.size() > large.size() + 1) // if the size of small>large by 2 then push                                               //the top of small into large
        {
            int ele = small.top();
            small.pop();
            large.push(ele);
        }
         // if the size of larger is greater than smaller by 2 then push the top of larger into smaller
        else if(large.size() > small.size() + 1)
        {
            int ele = large.top(); 
            large.pop();
            small.push(ele);
        }
    }
    
    double findMedian() {
        
        if(small.size() == large.size())
        {
            return (double(small.top()) + double(large.top())) / 2;
        }
        else if(small.size() == large.size() + 1)
        {
            return double(small.top());
        }
        else
        {
            return double(large.top());
        }
    }
};


 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



    
class MedianFinder {
public:
    
    priority_queue<int> maxh;   //max heap left  
    priority_queue<int, vector<int>, greater<int>> minh; //min heap right 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(minh.size() > 0 && num > maxh.top())
            minh.push(num);
        else 
            maxh.push(num);
        balanceHeap();
    }
    void balanceHeap()
    {
        if(minh.size() - maxh.size() == 2)
        {
            int ele = minh.top();
            minh.pop();
            maxh.push(ele);
        }
        else if(maxh.size() - minh.size() == 2)
        {
            int ele = maxh.top();
            maxh.pop();
            minh.push(ele);
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size())
            return (maxh.top() + minh.top())/2.0;
        else if(minh.size() > maxh.size())
            return minh.top();
        else
            return maxh.top();
        
       
    }
};

