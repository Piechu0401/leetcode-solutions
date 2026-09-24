class Solution {
public:
    inline const int smallestIndex(
        vector<int>& __ns
    ) const noexcept {
        for( char __i{}; __i < __ns.size(); ++__i ) {
            char __s{};

            while( __ns[__i] ) {
                __s += __ns[__i] % 10;
                __ns[__i] /= 10;

            }

            if( __i == __s ) return __i;

        }

        return -1;
        
    }
};