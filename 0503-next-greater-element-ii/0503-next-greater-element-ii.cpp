class Solution {
public:
    inline const vector<int> nextGreaterElements(
        const vector<int>& __ns
    ) const noexcept {
        vector<int> __res = __ns;

        for( int __i1{}; __i1 < __res.size(); ++__i1 ) {
            char __fuckOff{};

            for( int __i2{__i1 + 1}; __i2 < __ns.size(); ++__i2 )
                if( __res[__i1] < __ns[__i2] ) {
                    __res[__i1] = __ns[__i2];
                    __fuckOff = 1;
                    break;

                }

            if( __fuckOff ) continue;

            for( int __i2{}; __i2 < __i1; ++__i2 ) 
                if( __res[__i1] < __ns[__i2] ) {
                    __res[__i1] = __ns[__i2];
                    __fuckOff = 1;
                    break;

                }

            if( !__fuckOff ) {
                __res[__i1] = -1;

            }

        }

        return __res;
        
    }
};