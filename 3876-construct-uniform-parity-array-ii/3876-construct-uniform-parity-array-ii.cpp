class Solution {
public:
    inline const bool uniformArray(
        vector<int>& __ns
    ) const noexcept {
        if( __ns.size() == 1 ) return 1;

        int __e{};
        int __o{};
        int __min{INT_MAX};
        int __min2{INT_MAX};

        for( auto& __n : __ns ) {
            ( ( __n & 1 ) && !( ++__o & 1 ) );
            ( !( __n & 1 ) && !( ++__e & 1 ) ); 

            if( __min > __n ) {
                __min2 = __min;
                __min = __n;

            }
            
            if( __n > __min && __min2 > __n ) __min2 = __n;

        }

        if( __o == __ns.size() || __e == __ns.size() ) return 1;
        else if( __o && __e && !( __min & 1 ) ) return 0;

        return __min2 - __min >= 1;

    }
};