class Solution {
public:
    inline void doTheTrick(
        char*           __busy,
        const string&   __p,
        const int&      __idx,
        string&         __curr,
        string&         __res
    ) const noexcept {
        // cout << __curr.length() << "\n";
        
        if( __curr.length() == __p.length() + 1 ) {
            __res = ( __curr < __res ? __curr : __res );
            return;

        }

        for( char __i{'1'}; __i <= __p.length() + 49; ++__i ) {
            if( 
                __busy[__i - 49] ||
                ( __p[__idx] == 'I' && __curr[__idx] > __i ) ||
                ( __p[__idx] == 'D' && __curr[__idx] < __i )
            ) continue;

            __busy[__i - 49] = 1;
            __curr += __i;

            doTheTrick(
                __busy,
                __p,
                __idx + 1,
                __curr,
                __res
            );
            
            __curr.pop_back();
            __busy[__i - 49] = 0;

        }

    }

    inline const string smallestNumber(
        const string& __p
    ) const noexcept {
        string __res{"9999999999"};
        
        for( char __i{'1'}; __i <= __p.length() + 49; ++__i ) {
            string __curr{__i};
            char __busy[9]{};
            __busy[__i - 49] = 1;

            doTheTrick(
                __busy,
                __p,
                0,
                __curr,
                __res
            );

            if( __res != "9999999999" ) return __res;

        }

        return __res;
        
    }
};