class Solution {
public:
    inline const int maximumXOR(
        const vector<int>& __ns
    ) const noexcept {
        char __bits[32]{};
        int __res{};

        for( auto& __n : __ns ) {
            int __p{1};
            int __idx{};

            while( __p <= __n ) {
                if( __n & __p ) __bits[__idx] = 1;

                __p <<= 1;
                ++__idx;

            }

        }

        for( char __i{}; __i < 32; ++__i )
            if( __bits[__i] ) __res += ( 1 << __i );

        return __res;
        
    }
};

// 0001
// 0010
// 0011
// 1001
// 0010