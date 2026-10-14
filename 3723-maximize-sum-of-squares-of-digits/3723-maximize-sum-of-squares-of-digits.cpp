class Solution {
public:
    inline const string maxSumOfSquares(
        int& __n, 
        int& __s
    ) const noexcept {
        if( __n * 9 < __s ) return "";

        string __res{};

        while( __n ) {
            if( __s >= 9 ) { __res += '9'; __s -= 9; }
            else { __res += __s + 48; __s = 0; }

            --__n;

        }

        return __res;
        
    }
};