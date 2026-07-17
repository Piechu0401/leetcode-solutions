class Solution {
public:
    inline const int maxScore(
        const string& __s
    ) const noexcept {
        int __ones{};
        int __res{};

        for( auto& __c : __s ) 
            __ones += ( (__c - 48) ? 1 : 0 );

        int __zeros{};

        for( int __i{}; __i < __s.length() - 1; ++__i ) {
            if( __s[__i] - 48 ) --__ones;
            else ++__zeros;

            __res = ( __zeros + __ones > __res ? __zeros + __ones : __res );

        }

        return __res;

    }
};