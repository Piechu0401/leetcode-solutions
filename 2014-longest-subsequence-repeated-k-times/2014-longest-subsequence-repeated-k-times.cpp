class Solution {
public:
    inline void doTheTrick(
        string&                     __res,
        string&                     __src,
        string&                     __curr,
        vector<pair<char, int>>&    __cands,
        short&                      __len,
        int&                        __k
    ) const noexcept {
        if( __curr.length() == __len ) {
            int __idx{};
            short __count{};

            for( auto& __c : __src )
                if( __c == __curr[__idx] ) {
                    ++__idx;
                    if( __idx == __curr.length() ) {
                        __idx = 0;
                        ++__count;

                    }

                }

            // cout << __count << " " << __curr << "\n";

            if( __count >= __k )
                __res = __curr;

            return;

        }

        for( auto& __cand : __cands ) {
            if( !__cand.second ) continue;

            __curr += __cand.first;
            --__cand.second;

            doTheTrick(
                __res,
                __src,
                __curr,
                __cands,
                __len,
                __k
            );

            if( __res.length() ) return;

            __curr.pop_back();
            ++__cand.second;

        }

    }

    inline const string longestSubsequenceRepeatedK(
        string& __s, 
        int&    __k
    ) const noexcept {
        int __ls[26]{};
        char __fuckOff{};

        for( auto& __c : __s ) 
            __fuckOff |= ( ++__ls[__c - 97] == __k );
        
        if( !__fuckOff ) return "";

        vector<pair<char, int>> __cands;

        for( char __i{25}; __i > -1; --__i )
            if( __ls[__i] >= __k ) __cands.push_back( { __i + 97, __ls[__i] / __k } );

        if( !__cands.size() ) return "";

        string __res{};

        for( short __len = __s.length() / __k; __len > 0; --__len ) {
            string __curr{};

            doTheTrick(
                __res,
                __s,
                __curr,
                __cands,
                __len,
                __k
            );

            if( __res.length() ) return __res;

        }

        return __res;

    }

};