class Solution {
public:
    inline const string sortString(
        string& __s
    ) const noexcept {
        char __zeros{};
        short __letts[26]{};

        for( char& __c : __s ) ++*( __letts + (char)( __c - 97 ) );

        __s = "";

        for( char __i{}; __i < 26; ++__i )
            if( !*( __letts + __i ) ) ++__zeros;

        while( __zeros < 26 ) {
            for( char __i{}; __i < 26; ++__i )
                if( *( __letts + __i ) ) {
                    __s += __i + 97;

                    if( !( --*( __letts + __i ) ) ) ++__zeros;

                }

            if( __zeros == 26 ) break;

            for( char __i{25}; __i > -1; --__i )
                if( *( __letts + __i ) ) {
                    __s += __i + 97;

                    if( !( --*( __letts + __i ) ) ) ++__zeros;

                }

        }

        return __s;
        
    }
};