class Solution {
public:
    inline const int gcd(
        const int& __a,
        const int& __b
    ) const noexcept { return !__b ? __a : gcd( __b, __a % __b ); }

    inline const int gcdOfOddEvenSums(
        const int& __n
    ) const noexcept {
        int __a{};
        int __b{};

        for( short __i{}; __i < __n; ++__i ) {
            __a += ( ( __i + 1 ) << 1 );
            __b += ( ( __i + 1 ) << 1 ) - 1; 

        }

        return gcd(
            __a,
            __b
        );
        
    }
};