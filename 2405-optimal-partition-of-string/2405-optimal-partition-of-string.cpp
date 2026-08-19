class Solution {
public:
    inline const int partitionString(
        const string& __s
    ) const noexcept {
        int __res{};
        
        for( int __i{}; __i < __s.length(); ++__i ) {
            char __letts[26]{};
            int __j{__i};

            while( 
                __j < __s.length() &&
                !__letts[__s[__j] - 97] 
            ) {
                ++__letts[__s[__j] - 97];
                ++__j;

            }

            ++__res;
            __i = --__j;

        }

        return __res;
        
    }
};