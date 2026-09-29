class Solution {
public:
    inline const int removePalindromeSub(
        string& __s
    ) const noexcept {
        char __var{ ( 1 << 3 ) };

        for( short __i{}; __i <= ( __s.length() >> 1 ); ++__i ) {
            __var |= ( 1 << ( __s[__i] - 96 ) );
            __var |= ( 1 << ( __s[__s.length() - __i - 1] - 96 ) );

            if( __s[__i] != __s[__s.length() - __i - 1] ) { __var -= ( 1 << 3 ); break; }

        }

        if(
            ( __var & ( 1 << 3 ) ) ||
            (
                ( __var & ( 1 << 1 ) ) &&
                !( __var & ( 1 << 2 ) )
            ) ||
            (
                !( __var & ( 1 << 1 ) ) &&
                ( __var & ( 1 << 2 ) )
            )
        ) return 1;

        return 2;
     
    }
};