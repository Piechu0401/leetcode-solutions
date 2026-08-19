class Solution {
public:
    inline const int countTriplets(
        const vector<int>& __ns
    ) const noexcept {
        int __res{};
        vector<int> __ps( 1, __ns.front() );

        for( short __i{1}; __i < __ns.size(); ++__i )
            __ps.emplace_back( __ps.back() ^ __ns[__i] );

        for( short __i{}; __i < __ps.size(); ++__i )
            for( short __j = __i + 1; __j < __ps.size(); ++__j )
                if(
                    (
                        __i && 
                        !( __ps[__i - 1] ^ __ps[__j] ) 
                    ) ||
                    (
                        !__i &&
                        !__ps[__j]
                    )
                ) __res += __j - __i;

        return __res;
        
    }
};