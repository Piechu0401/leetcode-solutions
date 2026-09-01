class Solution {
public:
    inline void doTheTrick(
        string&             __curr,
        const int&          __idx,
        vector<int>&        __counter,
        long long&          __res,
        char&               __fuckOuttaHere,
        const long long&    __n
    ) const noexcept {
        // cout << __curr << "\n";
        if( __fuckOuttaHere ) return;

        if( __idx > ( ( ( __curr.length() ) - !( __curr.length() & 1 ) ) >> 1 ) ) {
            char __valid{1};

            for( char __i{}; __i < 9; ++__i )
                if( __counter[__i] && __counter[__i] != __i + 1) {
                    __valid = 0;
                    break;

                }

            if( __valid && __n < stoll( __curr ) ) {
                __res = stoll( __curr );
                // cout << stoll( __curr ) << "\n";
                __fuckOuttaHere = 1;

            }

            return;

        }

        for( char __i{'1'}; __i <= ( __curr.length() < 9 ? __curr.length() + 48 : '9' ); ++__i ) {
            char __mid = ( __idx == __curr.length() - 1 - __idx );

            __counter[__i - 49] += ( __mid ? 1 + !( __curr.length() ) : 2 );

            if( __counter[__i - 49] > __i - 48 ) {
                __counter[__i - 49] -= ( __mid ? 1 + !( __curr.length() ) : 2 );
                continue;

            }

            __curr[__idx] = __i;
            __curr[__curr.length() - 1 - __idx] = __i;

            doTheTrick(
                __curr,
                __idx + 1,
                __counter,
                __res,
                __fuckOuttaHere,
                __n
            );

            if( __fuckOuttaHere ) return;

            __counter[__i - 49] -= ( __mid ? 1 + !( __curr.length() ) : 2 );

        }

    }
    
    inline const long long specialPalindrome(
        const long long& __n
    ) const noexcept {
        vector<int> __counter( 9, 0 );
        long long __res{};
        char __fuckOuttaHere{};
        
        for( char __i = to_string( __n ).length(); __i <=  16; ++__i ) {
            string __curr( __i, 0 );

            doTheTrick(
                __curr,
                0,
                __counter,
                __res,
                __fuckOuttaHere,
                __n
            );

            if( __fuckOuttaHere ) break;

        }

        return __res;

    }

};

// 1
// 22
// 212
// 32323
// 333
// 4444
// 23332