class Solution {
public:
    inline const int minFlips(
        const string& __t
    ) const noexcept {
        // easy peasy, just count segments.
        int __i{};

        while( 
            __i < __t.length() &&
            !( __t[__i] - 48 )
        ) ++__i;

        if( __i == __t.length() ) return 0;

        char __p{__t[__i]};
        int __res{};

        for( __i = __i + 1; __i < __t.length(); ++__i ) {
            if( __t[__i] != __p ) ++__res;
            __p = __t[__i];

        }

        if( __t[__i] != __p ) ++__res;

        return __res ? __res : 0;
        
    }
};