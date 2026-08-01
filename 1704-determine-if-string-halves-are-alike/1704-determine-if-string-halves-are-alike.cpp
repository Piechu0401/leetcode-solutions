class Solution {
public:
    inline const bool halvesAreAlike(
        const string& __s
    ) const noexcept {
        int __res{};

        for( short __i{}; __i < ( __s.length() >> 1 ); ++__i ) {
            if(
                __s[__i] == 'a' ||
                __s[__i] == 'e' ||
                __s[__i] == 'i' ||
                __s[__i] == 'o' ||
                __s[__i] == 'u' ||
                __s[__i] == 'A' ||
                __s[__i] == 'E' ||
                __s[__i] == 'I' ||
                __s[__i] == 'O' ||
                __s[__i] == 'U'
            ) ++__res;

            if(
                __s[__s.length() - 1 - __i] == 'a' ||
                __s[__s.length() - 1 - __i] == 'e' ||
                __s[__s.length() - 1 - __i] == 'i' ||
                __s[__s.length() - 1 - __i] == 'o' ||
                __s[__s.length() - 1 - __i] == 'u' ||
                __s[__s.length() - 1 - __i] == 'A' ||
                __s[__s.length() - 1 - __i] == 'E' ||
                __s[__s.length() - 1 - __i] == 'I' ||
                __s[__s.length() - 1 - __i] == 'O' ||
                __s[__s.length() - 1 - __i] == 'U'    
            ) --__res;

        }

        return !__res;

    }
};