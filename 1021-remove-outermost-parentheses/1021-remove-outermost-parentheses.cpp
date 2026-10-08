class Solution {
public:
    inline const string removeOuterParentheses(
        string& __s
    ) const noexcept {
        string __res{};
        int __prev{};
        int __bal{};

        for( int __i{}; __i < __s.length(); ++__i ) {
            if( __s[__i] == '(' ) ++__bal;
            else --__bal;

            if( !__bal ) {
                __res += __s.substr( __prev + 1, __i - __prev - 1 );
                __prev = __i + 1;

            }

        }

        return __res;
    
    }


};