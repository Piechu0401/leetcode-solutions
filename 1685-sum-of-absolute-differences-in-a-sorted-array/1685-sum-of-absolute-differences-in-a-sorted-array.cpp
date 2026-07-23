class Solution {
public:
    inline const vector<int> getSumAbsoluteDifferences(
        vector<int>& __ns
    ) const noexcept {
        vector<int> __pref( __ns.size(), 0 );
        vector<int> __suff( __ns.size(), 0 );
        __pref.front() = __ns.front();
        __suff.back() = __ns.back();

        for( int __i{1}; __i < __ns.size(); ++__i ) {
            __pref[__i] += __pref[__i - 1] + __ns[__i];
            __suff[__ns.size() - 1 -__i] += 
                __suff[__ns.size() - __i] +
                __ns[__ns.size() - 1 - __i];

        }

        // for( auto& __p : __pref ) cout << __p << " ";
        // cout << "\n";
        // for( auto& __s : __suff ) cout << __s << " ";

        for( int __i{1}; __i < __ns.size() - 1; ++__i )
            __ns[__i] = (
                (
                    __ns[__i] * __i - __pref[__i - 1]
                ) +
                (
                    __suff[__i + 1] - __ns[__i] * ( __ns.size() - 1 -__i )
                )
            );

        __ns.front() = __suff[1] - __ns.front() * ( __ns.size() - 1 );
        __ns.back() = __ns[__ns.size() - 1] * ( __ns.size() - 1 ) - __pref[__ns.size() - 2];

        return __ns;
        
    }
};