class BrowserHistory {
public:
    vector<string> vec;
    int curr, count = 1;
    
    BrowserHistory(string homepage) {
     
        vec.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
     
      curr++;
      vec.resize(curr);
      vec.push_back(url); 
    }
    
    string back(int steps) {
     
     curr = max(0, curr - steps);
     return vec[curr];
    }
    
    string forward(int steps) {
     int n = vec.size();
     curr = min(n-1, curr+steps);
     return vec[curr];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */