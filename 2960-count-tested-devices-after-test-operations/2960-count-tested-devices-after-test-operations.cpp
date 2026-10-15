class Solution {
public:
    inline const int countTestedDevices(
        vector<int>& __bps
    ) const noexcept {
        char __count{};

        for( auto& __bp : __bps ) if( __bp - __count > 0 ) ++__count;

        return __count;
        
    }
};