class Solution {
public:
    inline const int minSwaps(
        const string& __s
    ) const noexcept {
        int __e = __s.length() - 1;
        int __bal{};
        int __res{};

        for( auto& __c : __s ) { 
            if( __c == ']' ) --__bal;
            else ++__bal;

            if( __bal < 0 ) {
                __bal += 2;

                while(
                    __e > -1 &&
                    __s[__e] == ']'
                ) --__e;

                ++__res;

            }

        }

        return __res;
        
    }
};