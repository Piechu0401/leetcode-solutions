class Solution {
public:
    inline const bool isKPal(
        long long   __n,
        const int&  __k 
    ) const noexcept {
        long long __p{1};
        string    __cand{};

        while( __p * __k <= __n ) __p *= __k;

        while( __p ) {
            char __j{};

            while( ( __j + 1 ) * __p <= __n ) ++__j;

            __n -= __j * __p;
            __p /= __k;
            __cand += ( __j + 48 );

        }

        // cout << __cand << "\n";

        for( char __i{}; __i < ( __cand.length() >> 1 ); ++__i )
            if( __cand[__i] != __cand[__cand.length() - 1 - __i] ) return 0;

        return 1;

    }

    inline void doTheTrick(
        string&     __curr,
        char&       __maxSize,
        const int&  __idx,      // must be less/equal than/to half of max size
        long long&  __res,
        int&        __n,
        const int&  __k
    ) const noexcept {
        // cout << __idx << "\n";
        if( !__n ) return;

        if( ( ( __maxSize - !( __maxSize & 1 ) ) >> 1 ) < __idx ) {
            // cout << __curr << "\n";
            if( isKPal( stoll( __curr ), __k ) ) {
                // cout << __curr << "\n";
                
                --__n;
                __res += stoll( __curr );
                if( !__n ) return;

            }

            return;

        }

        if( !__idx )
            for( char __c{'1'}; __c <= '9'; ++__c ) {
                __curr[__idx] = __c;
                __curr[__maxSize - 1 - __idx] = __c;

                doTheTrick(
                    __curr,
                    __maxSize,
                    __idx + 1,
                    __res,
                    __n,
                    __k
                );

                if( !__n ) return;

            }
        else
            for( char __c{'0'}; __c <= '9'; ++__c ) {
                __curr[__idx] = __c;
                __curr[__maxSize - 1 - __idx] = __c;

                doTheTrick(
                    __curr,
                    __maxSize,
                    __idx + 1,
                    __res,
                    __n,
                    __k
                );

                if( !__n ) return;

            }

    }

    inline const long long kMirror(
        const int& __k, 
        int& __n
    ) const noexcept {
        long long __res{};
        char __maxSize{};

        // isKPal( 1024, 2 );

        while( __n ) {
            string __curr( ++__maxSize, 0 );

            doTheTrick(
                __curr,
                __maxSize,
                0,
                __res,
                __n,
                __k
            );

        }

        return __res;
        
    }
};