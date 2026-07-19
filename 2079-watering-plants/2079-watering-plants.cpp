class Solution {
public:
    inline const int wateringPlants(
        const vector<int>& __ps, 
        const int& __c
    ) const noexcept {
        int __water{__c};
        int __res{};

        for( short __i{}; __i < __ps.size(); ++__i ) {
            if( __water < __ps[__i] ) {
                __water = __c;
                __res += __i << 1;

            }
            
            ++__res;
            __water -= __ps[__i];

        }

        return __res;
        
    }
};