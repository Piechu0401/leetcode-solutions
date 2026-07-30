class Solution {
public:
    inline const vector<string> letterCombinations(
        const string& __ds
    ) const noexcept {
        vector<string> __res;

        unordered_map<char, vector<char>> __um = {
            {'2', { 'a', 'b', 'c' } },
            {'3', { 'd', 'e', 'f' } },
            {'4', { 'g', 'h', 'i' } },
            {'5', { 'j', 'k', 'l' } },
            {'6', { 'm', 'n', 'o' } },
            {'7', { 'p', 'q', 'r', 's' } },
            {'8', { 't', 'u', 'v' } },
            {'9', { 'w', 'x', 'y', 'z' } }
        };

        if( __ds.length() == 1 ) {
            for( int __i{}; __i < __um[__ds[0]].size(); ++__i )
                __res.push_back( string( 1, __um[__ds[0]][__i] ) );

        }
        else if( __ds.length() == 2 ) {
            for( int __i{}; __i < __um[__ds[0]].size(); ++__i ) {
                string __load{__um[__ds[0]][__i]};

                for( int __j{}; __j < __um[__ds[1]].size(); ++__j ) {
                    __load += __um[__ds[1]][__j];
                    __res.emplace_back( __load );
                    __load.pop_back();

                }

            }

        }
        else if( __ds.length() == 3 ) {
            for( int __i{}; __i < __um[__ds[0]].size(); ++__i ) {
                string __load{__um[__ds[0]][__i]};

                for( int __j{}; __j < __um[__ds[1]].size(); ++__j ) {
                    __load += __um[__ds[1]][__j];

                    for( int __k{}; __k < __um[__ds[2]].size(); ++__k ) {
                        __load += __um[__ds[2]][__k];
                        __res.emplace_back( __load );
                        __load.pop_back();

                    }

                    __load.pop_back();

                }

            }

        }
        else if( __ds.length() == 4 ) {
            for( int __i{}; __i < __um[__ds[0]].size(); ++__i ) {
                string __load{__um[__ds[0]][__i]};

                for( int __j{}; __j < __um[__ds[1]].size(); ++__j ) {
                    __load += __um[__ds[1]][__j];

                    for( int __k{}; __k < __um[__ds[2]].size(); ++__k ) {
                        __load += __um[__ds[2]][__k];

                        for( int __l{}; __l < __um[__ds[3]].size(); ++__l ) {
                            __load += __um[__ds[3]][__l];
                            __res.emplace_back( __load );
                            __load.pop_back();

                        }

                        __load.pop_back();

                    }

                    __load.pop_back();

                }

            }

        }

        return __res;
        
    }
};