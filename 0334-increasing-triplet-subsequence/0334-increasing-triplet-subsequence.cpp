class Solution {
public:
    inline const bool increasingTriplet(
        const vector<int>& __ns
    ) const noexcept {
        long __min{LONG_MAX};
        long __mid{LONG_MAX};
        long __max{LONG_MAX};

        for( int __i{}; __i < __ns.size(); ++__i ) 
            if( __ns[__i] < __min ) __min = __ns[__i];
            else if( 
                __ns[__i] > __min &&
                __ns[__i] < __mid  
            ) __mid = __ns[__i];
            else if( 
                __ns[__i] > __mid &&
                __ns[__i] < __max  
            ) __max = __ns[__i];

        // cout << __min << " " << __mid << " " << __max << "\n";

        return __min != LONG_MAX && __mid != LONG_MAX && __max != LONG_MAX && (__min < __mid && __mid < __max);
        
    }
};