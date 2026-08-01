class Solution {
public:
    inline const string freqAlphabets(
        const string& __s
    ) const noexcept {
        string __res{};
        
        for( short __i = __s.length() - 1; __i > -1 ; --__i ) {
            if( __s[__i] != '#' ) __res = string( 1, __s[__i] + 48 ) + __res;
            else {
                __res = string(
                    1,
                    (char)( 96 + ( __s[__i - 2] - 48 ) * 10 + ( __s[__i - 1] - 48 ) )
                ) + __res;
                __i -= 2;

            }

        }
        
        return __res;

    }

};