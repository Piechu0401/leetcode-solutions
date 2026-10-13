class Solution {
public:
    inline const long long maxAlternatingSum(
        vector<int>& __ns
    ) const noexcept {
        long long __res{};

        for( auto& __n : __ns ) __n = ( __n < 0 ? -__n : __n );

        sort( __ns.begin(), __ns.end() );

        for( int __i{}; __i < __ns.size(); ++__i )
            if( __i < ( __ns.size() >> 1 ) ) __res -= __ns[__i] * __ns[__i];
            else __res += __ns[__i] * __ns[__i];

        return __res;
        
    }
};