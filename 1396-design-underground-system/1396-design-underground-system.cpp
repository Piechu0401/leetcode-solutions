class UndergroundSystem {
public:
    explicit UndergroundSystem() noexcept {}
    
    inline void checkIn(
        const int&      __id, 
        const string&   __sn, 
        const int&      __t
    ) noexcept { __checkIns[__id] = { __t, __sn }; }
    
    inline void checkOut(
        const int&      __id, 
        const string&   __sn, 
        const int&      __t
    ) noexcept {
        __timeSums[__checkIns[__id].second + " " + __sn].first += __t - __checkIns[__id].first;
        ++__timeSums[__checkIns[__id].second + " " + __sn].second;
        __checkIns.erase( __id );
        
    }
    
    inline const double getAverageTime(
        const string&   __ss, 
        const string&   __es
    ) noexcept {
        return (double)__timeSums[__ss + " " + __es].first / __timeSums[__ss + " " + __es].second;

    }

    unordered_map<int, pair<int, string>>   __checkIns;
    unordered_map<string, pair<int, int>>   __timeSums;

};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */