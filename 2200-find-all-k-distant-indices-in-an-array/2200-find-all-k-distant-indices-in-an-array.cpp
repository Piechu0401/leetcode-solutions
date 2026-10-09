class Solution {
public:
    inline const vector<int> findKDistantIndices(
        vector<int>&    __ns, 
        int&            __key, 
        int&            __k
    ) const noexcept {
        vector<int> __res;
        vector<int> __idxs;

        for( short __i{}; __i < __ns.size(); ++__i ) 
            if( __ns[__i] == __key ) {
                __idxs.emplace_back( __i );
                __res.emplace_back( __i );
                
            }

        for( short __i{}; __i < __ns.size(); ++__i )
            if( 
                __ns[__i] != __key
            ) {
                char __valid{};
                for( auto& __idx : __idxs ) if( abs( __idx - __i ) <= __k ) { __valid = 1; break; }

                if( __valid ) __res.emplace_back( __i );

            }

        sort( __res.begin(), __res.end() );

        return __res;
        
    }
};