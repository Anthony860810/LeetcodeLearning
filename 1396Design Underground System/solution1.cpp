class UndergroundSystem {
public:
    
    unordered_map<int, pair<string,int> > checkInMap;
    unordered_map<string, pair< int,int >> checkOutMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto CheckIn = checkInMap[id];
        string endpoints = CheckIn.first + "->" + stationName;
        checkOutMap[endpoints].first += (t-CheckIn.second);
        checkOutMap[endpoints].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string endpoints =startStation + "->" + endStation;
        auto Checkout = checkOutMap[endpoints];
        return (double) Checkout.first / Checkout.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */