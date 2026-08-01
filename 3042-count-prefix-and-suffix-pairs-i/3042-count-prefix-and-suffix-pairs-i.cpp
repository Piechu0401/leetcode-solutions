class Solution {
public:
    inline const int countPrefixSuffixPairs(
        const vector<string>& __ws
    ) const noexcept {
        int __res{};

        for( char __i{}; __i < __ws.size(); ++__i )
            for( char __j = __i + 1; __j < __ws.size(); ++__j ) {
                string_view __sw1(__ws[__i]);
                string_view __sw2(__ws[__j]);

                if( 
                    __sw1 == __sw2 ||
                    (__sw1.size() < __sw2.size() &&
                    __sw1 == __sw2.substr( 0, __sw1.size() ) &&
                    __sw1 == __sw2.substr( __sw2.size() - __sw1.size(), __sw1.size() ))
                )  ++__res;

            }

        return __res;
        
    }
};