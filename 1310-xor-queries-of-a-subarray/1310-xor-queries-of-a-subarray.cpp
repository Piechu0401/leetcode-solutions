class Solution {
public:
    inline const vector<int> xorQueries(
        vector<int>& __ns, 
        const vector<vector<int>>& __qs
    ) const noexcept {
        vector<int> __ps( __ns.size() );
        __ps.front() = __ns.front();

        for( int __i{1}; __i < __ns.size(); ++__i )
            __ps[__i] = __ps[__i - 1] ^ __ns[__i];

        vector<int> __res( __qs.size(), 0 );

        for( int __i{}; __i < __qs.size(); ++__i )
            if( __qs[__i][0] == __qs[__i][1] ) __res[__i] = __ns[__qs[__i][0]];
            else if( !__qs[__i][0] ) __res[__i] = __ps[__qs[__i][1]];
            else __res[__i] = __ps[__qs[__i][0] - 1] ^ __ps[__qs[__i][1]];

        return __res;

    }
};

// 0010
// 0111
// 1110
// 1000