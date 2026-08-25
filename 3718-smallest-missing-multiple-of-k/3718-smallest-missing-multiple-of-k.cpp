class Solution {
public:
    inline const int missingMultiple(
        const vector<int>&  __ns, 
        const int&          __k
    ) const noexcept {
        char __NS[100]{};

        for( auto& __n : __ns ) ++__NS[__n - 1];

        for( short __i = __k - 1; __i < 100; __i += __k ) if( !__NS[__i] ) return __i + 1;

        return ( ( 100 / __k ) + 1 ) * __k;

    }
};