class Solution {
public:
    inline const int uniqueXorTriplets(
        const vector<int>& __ns
    ) const noexcept {
        unordered_set<int> __xors;

        for( int __i{}; __i < __ns.size(); ++__i )
            for( int __j{}; __j < __ns.size(); ++__j )
                if( !__xors.count( __ns[__i] ^ __ns[__j] ) )
                    __xors.insert( __ns[__i] ^ __ns[__j] );

        unordered_set<int> __res;

        for( int __i{}; __i < __ns.size(); ++__i )
            for( auto& __xor : __xors ) 
                if( !__res.count( __ns[__i] ^ __xor ) )
                    __res.insert( __ns[__i] ^ __xor );

        return __res.size();

    }
};

// 0110
// 1001