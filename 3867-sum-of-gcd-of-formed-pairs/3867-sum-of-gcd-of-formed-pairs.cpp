class Solution {
public:
    inline const int GCD(
        const int& __a,
        const int& __b
    ) const noexcept { return !__b ? __a : GCD( __b, __a % __b ); }

    inline const long long gcdSum(
        const vector<int>& __ns
    ) const noexcept {
        long long __res{};
        int __max{};
        vector<int> __gcd;

        for( auto& __n : __ns ) {
            __max = ( __max < __n ? __n : __max );
            __gcd.emplace_back( GCD( __max, __n ) );

        }

        sort( __gcd.begin(), __gcd.end() );

        for( int __i{}; __i < (__gcd.size() >> 1); ++__i )
            if( __i != __gcd.size() - 1 - __i )
                __res += GCD( __gcd[__i], __gcd[__gcd.size() - 1 - __i] );

        return __res;
        
    }
};