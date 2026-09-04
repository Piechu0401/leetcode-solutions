class Solution {
public:
    inline const int firstStableIndex(
        vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        vector<int> __ps( __ns.size(), 0 );
        vector<int> __ss( __ns.size(), 0 );

        __ps.front() = __ns.front();
        __ss.back() = __ns.back();

        for( char __i{1}; __i < __ns.size(); ++__i ) {
            __ps[__i] = ( __ps[__i - 1] > __ns[__i] ? __ps[__i - 1] : __ns[__i] );
            __ss[__ns.size() - __i - 1] = 
                ( 
                    __ss[__ns.size() - __i] < __ns[__ns.size() - __i - 1] ?\ 
                    __ss[__ns.size() - __i] : __ns[__ns.size() - __i - 1] 
                );

        }

        for( char __i{}; __i < __ns.size(); ++__i )
            if( __ps[__i] - __ss[__i] <= __k ) return __i;

        return -1;

    }

};