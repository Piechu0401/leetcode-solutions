class Solution {
public:
    inline const bool isMiddleElementUnique(
        vector<int>& __ns
    ) const noexcept {
        char __res{-1};

        for( auto& __n : __ns )
            if( __n == __ns[(__ns.size() >> 1)] ) {
                ++__res;

                if( __res ) return 0;
                
            }

        return 1;
        
    }
};