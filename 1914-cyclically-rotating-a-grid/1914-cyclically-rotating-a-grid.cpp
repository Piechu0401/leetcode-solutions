class Solution {
public:
    inline const vector<vector<int>> rotateGrid(
        vector<vector<int>>&        __g, 
        const int&                  __k
    ) const noexcept {
        for( char __i{}; __i < ( min( __g.size(), __g.front().size() ) >> 1 ); ++__i ) {
            vector<int> __temp;

            for( char __j{__i}; __j < __g.front().size() - __i; ++__j ) 
                __temp.emplace_back( __g[__i][__j] );

            for( char __j = __i + 1; __j < __g.size() - __i - 1; ++__j ) 
                __temp.emplace_back( __g[__j][__g.front().size() - __i - 1] );

            for( char __j = __g.front().size() - __i - 1; __j > __i - 1; --__j ) 
                __temp.emplace_back( __g[__g.size() - __i - 1][__j] );

            for( char __j = __g.size() - __i - 2; __j > __i; --__j ) 
                __temp.emplace_back( __g[__j][__i] );

            // for( auto& __n : __temp ) cout << __n << " ";
            // cout << "\n";

            const int __shift = 
                __k % __temp.size();

            // cout 
            //     << __shift << " " 
            //     << (( __g.front().size() << 1 ) + ( __g.size() << 1 ) - 4 ) << " "
            //     << __g.front().size() << " "
            //     << __g.size() << " "
            //     << __temp.size() << "\n";

            __temp.insert( __temp.end(), __temp.begin(), __temp.begin() + __shift );
            __temp.erase( __temp.begin(), __temp.begin() + __shift );

            // for( auto& __n : __temp ) cout << __n << " ";
            // cout << "\n";

            short __idx{};

            for( char __j{__i}; __j < __g.front().size() - __i; ++__j ) { 
                __g[__i][__j] = __temp[__idx];
                ++__idx;

            }

            for( char __j = __i + 1; __j < __g.size() - __i - 1; ++__j ) { 
                __g[__j][__g.front().size() - __i - 1] = __temp[__idx];
                ++__idx;

            }

            for( char __j = __g.front().size() - __i - 1; __j > __i - 1; --__j ) {
                __g[__g.size() - __i - 1][__j] = __temp[__idx];
                ++__idx;

            }

            for( char __j = __g.size() - __i - 2; __j > __i; --__j ) { 
                __g[__j][__i] = __temp[__idx];
                ++__idx;

            }

        }

        return __g;
        
    }
};

// # # # # # #
// # # # # # #
// # # # # # #
// # # # # # #
// # # # # # #
// # # # # # #
// # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #
// # # # # # # # # # # # #