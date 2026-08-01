class Solution {
public:
    inline const char kthCharacter(
        const int& __k
    ) const noexcept {
        string __s{"a"};

        while( __s.length() < __k ) {
            string __temp{__s};

            for( auto& __c : __temp )
                __c = ( ( __c + 1 ) - 97 ) % 26 + 97;

            __s += __temp;

        }

        return __s[__k - 1];
        
    }
};