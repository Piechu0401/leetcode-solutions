class Solution {
public:
    inline int sumOfSquares(
        vector<int>& __ns
    ) const noexcept {
        int __res{};

        for( char __i{}; __i < ( __ns.size() >> 1 ); ++__i )
            if( !( __ns.size() % ( __i + 1 ) ) ) __res += __ns[__i] * __ns[__i];

        __res += __ns.back() * __ns.back();

        return __res;
        
    }

};