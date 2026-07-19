class Solution {
public:
    inline const bool checkStrings(
        const string& __s1, 
        const string& __s2
    ) const noexcept {
        short __cs1[26]{};
        short __cs2[26]{};

        for( int __i{}; __i < __s1.length(); __i += 2 ) {
            ++__cs1[__s1[__i] - 97];
            ++__cs2[__s2[__i] - 97];

        }

        for( char __i{}; __i < 26; ++__i ) {
            if( __cs1[__i] != __cs2[__i] ) return 0;

            __cs1[__i] = 0; 
            __cs2[__i] = 0;

        }

        for( int __i{1}; __i < __s1.length(); __i += 2 ) {
            ++__cs1[__s1[__i] - 97];
            ++__cs2[__s2[__i] - 97];

        }

        for( char __i{}; __i < 26; ++__i ) 
            if( __cs1[__i] != __cs2[__i] ) return 0;

        return 1;

    }
};