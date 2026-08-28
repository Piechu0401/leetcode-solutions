class Solution {
public:
    inline void doTheTrick(
        long long&  __res,
        string&     __num,
        const int&  __k,
        const int&  __i        
    ) noexcept {
        if( __i > ( __num.length() >> 1 ) ) {
            if( !( stoll( __num ) % __k ) ) {
                // cout << __i << " " << __num.length() << "\n";
                
                string __key = __num;
                sort( __key.begin(), __key.end() );

                // cout << __num << " " << __key << " " << __us.count( __key ) << "\n";

                if( __us.count( __key ) ) return;

                __us.insert( __key );

                long __n{1};
                char __ns[10]{};

                ++__ns[__num[0] - 48];

                for( char __j{2}; __j <= __num.length(); ++__j ) {
                    __n *= __j;
                    ++__ns[__num[__j - 1] - 48];

                }

                long __cpy = __n;

                for( char __j{}; __j < 10; ++__j )
                    for( char __k{2}; __k <= __ns[__j]; ++__k )
                        __n /= __k;

                // cout << __num << " " << __cpy << " " << __n << "\n";
                // for( char __i{}; __i < 10; ++__i ) cout << (int)__ns[__i] << " ";
                // cout << "\n";

                __res += __n * ( __num.length() - __ns[0] ) / __num.length();
                // cout << __res << "\n";

            }
            return;

        }

        if( __i )
            for( char __ch{'0'}; __ch <= '9'; ++__ch ) {
                __num[__i] = __ch;
                __num[__num.length() - 1 - __i] = __ch;

                doTheTrick(
                    __res,
                    __num,
                    __k,
                    __i + 1
                );

            }
        else
            for( char __ch{'1'}; __ch <= '9'; ++__ch ) {
                __num[__i] = __ch;
                __num[__num.length() - 1 - __i] = __ch;

                doTheTrick(
                    __res,
                    __num,
                    __k,
                    __i + 1
                );

            }

    }

    inline const long long countGoodIntegers(
        const int& __n, 
        const int& __k
    ) noexcept {
        if( __n == 1 && __k > 4 ) return 1;
        else if( __n == 1 && __k == 1 ) return 9;
        else if( __n == 1 && __k == 4 ) return 2;
        else if( __n == 1 && __k == 3 ) return 3;
        else if( __n == 1 && __k == 2 ) return 4;

        long long __res{};
        string __num( __n, 0 );

        doTheTrick(
            __res,
            __num,
            __k,
            0
        );

        return __res;
        
    }

    unordered_set<string> __us;

};

// n = 3, k = 5
// 505 550      2
// 515 551 155  3
// 525 552 255  3
// 535 553 355  3
// 545 554 455  3
// 555          1
// 565 556 655  3
// 575 557 755  3
// 585 558 855  3
// 595 559 955  3