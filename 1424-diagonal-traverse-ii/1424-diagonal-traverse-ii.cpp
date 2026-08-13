class Solution {
public:
    inline const vector<int> findDiagonalOrder(
        const vector<vector<int>>& __ns
    ) const noexcept {
        vector<tuple<int, int, int>> __ts;

        for( int __i{}; __i < __ns.size(); ++__i )
            for( int __j{}; __j < __ns[__i].size(); ++__j )
                __ts.push_back( { __i + __j, __i, __ns[__i][__j] } );

        sort(
            __ts.begin(),
            __ts.end(),
            [](
                const tuple<int, int, int>& __a,
                const tuple<int, int, int>& __b
            ) -> const bool { 
                if( get<0>(__a) != get<0>(__b) ) return get<0>(__a) < get<0>(__b); 
                else return get<1>(__a) > get<1>(__b);
            
            }
        );

        vector<int> __res;

        for( auto& __t : __ts ) __res.emplace_back( get<2>(__t) );

        return __res;
        
    }
};