class Solution {
public:
    inline void doTheTrick(
        vector<vector<char>>& __b,
        const char& __i,
        const char& __j
    ) noexcept {
        // cout << (int)__i << " " << (int)__j << "\n";

        if( !__dots ) { 
            // cout << "0\n"; 
            return; 
            
        }
        else if( __b[__i][__j] != '.' ) {
            if( __i == 8 && __j == 8 ) { __dots = 0; return; }
            if( __j == 8 ) doTheTrick( __b, __i + 1, 0 );
            else doTheTrick( __b, __i, __j + 1 );

        }
        else {
            for( char __n{'1'}; __n <= '9'; ++__n ) {
                if(
                    ( ( __used[__n - 49] & ( 1 << __i ) ) == ( 1 << __i ) ) ||
                    ( ( __used[__n - 49] & ( 1 << ( __j + 9 ) ) ) == ( 1 << ( __j + 9 ) ) ) ||
                    ( ( __used[__n - 49] & ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) ) ) == ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) ) )
                ) continue;

                --__dots;
                __b[__i][__j] = __n;
                __used[__n - 49] +=
                    ( 1 << __i ) +
                    ( 1 << ( __j + 9 ) ) +
                    ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) );

                if( __j == 8 ) doTheTrick( __b, __i + 1, 0 );
                else doTheTrick( __b, __i, __j + 1 );

                if( !__dots ) return;

                ++__dots;
                __b[__i][__j] = '.';
                __used[__n - 49] -=
                    (
                        ( 1 << __i ) +
                        ( 1 << ( __j + 9 ) ) +
                        ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) )
                    );

            }

        }
        
        // ( ( __used[__n - 49] & ( 1 << __i ) ) == ( 1 << __i ) ) ||
        // ( ( __used[__n - 49] & ( 1 << ( __j + 9 ) ) ) == ( 1 << ( __j + 9 ) ) ) ||
        // ( ( __used[__n - 49] & ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) ) ) == ( 1 << ( __i / 3 * 3 + __j / 3 + 18 ) ) )

    }

    inline void solveSudoku(
        vector<vector<char>>& __b
    ) noexcept {
        for( char __i{}; __i < 9; ++__i )
            for( char __j{}; __j < 9; ++__j )
                if( __b[__i][__j] == '.' ) ++__dots;
                else {
                    __used[__b[__i][__j] - 49] += 
                        ( 1 << __i                              ) +
                        ( 1 << ( __j + 9 )                      ) +
                        ( 1 << ( __i / 3 * 3 + __j / 3 + 18 )   );

                }

        doTheTrick( __b, 0, 0 );

    }

    int __used[9]{};
    char __dots{};

};