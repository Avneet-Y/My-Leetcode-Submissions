class UndergroundSystem {
public:
    map<int,pair<string,int>>m1;
    map<pair<string,string>,vector<int>>dist;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id]={stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        auto st=m1[id];
        dist[{st.first,stationName}].push_back(t-st.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int c=0;
        auto v=dist[{startStation,endStation}];
        for(auto x:v)
        c+=x;

        return double(c)/v.size();
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */