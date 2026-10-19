class Solution {
public:
    inline const vector<int> targetIndices(
        vector<int>&    __ns, 
        int&            __t
    ) const noexcept {
        sort( __ns.begin(), __ns.end() );

        vector<int> __res;
        char __b{};
        char __e = __ns.size() - 1;
        char __idx{-1};

        while( __b <= __e ) {
            char __mid = __b + ( ( __e - __b ) >> 1 );

            if( __ns[__mid] < __t ) __b = ++__mid;
            else if( __ns[__mid] > __t ) __e = --__mid;
            else { __idx = __mid; __e = --__mid; } 

        }

        if( __idx == -1 ) return {};

        while(
            __idx < __ns.size() &&
            __ns[__idx] == __t
        ) __res.emplace_back( __idx++ );

        return __res;
        
    }
};