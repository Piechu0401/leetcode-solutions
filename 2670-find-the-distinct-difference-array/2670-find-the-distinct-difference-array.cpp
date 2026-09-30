class Solution {
public:
    inline const vector<int> distinctDifferenceArray(
        vector<int>& __ns
    ) const noexcept {
        unordered_map<int, int> __total;

        for( auto& __n : __ns ) ++__total[__n];

        unordered_set<int> __curr;

        for( char __i{}; __i < __ns.size(); ++__i ) {
            if( !__curr.count( __ns[__i] ) ) __curr.insert( __ns[__i] );
            if( !--__total[__ns[__i]] ) __total.erase( __ns[__i] );

            __ns[__i] = __curr.size() - __total.size();

        }

        return __ns;
        
    }
};