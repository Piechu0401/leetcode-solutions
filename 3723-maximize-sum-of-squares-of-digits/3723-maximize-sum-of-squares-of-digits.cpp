class Solution {
public:
    inline const string maxSumOfSquares(
        int& __n, 
        int& __s
    ) const noexcept {
        if( __n * 9 < __s ) return "";

        string __res{};

        __res += string( __s / 9, '9' );
        __n -= ( __s / 9 );
        __s -= ( __s / 9 ) * 9;
        
        if( __s ) { __res += __s + 48; --__n; };
        
        __res += string( __n, '0' );

        return __res;
        
    }
};