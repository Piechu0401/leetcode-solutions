class Solution {
public:
    inline const int minFlips(
        vector<vector<int>>& __g
    ) const noexcept {
        int __rows{};
        int __cols{};

        for( int __i{}; __i < __g.size(); ++__i )
            for( int __j{}; __j < ( __g.front().size() >> 1 ); ++__j )
                if( __g[__i][__j] != __g[__i][__g.front().size() - 1 - __j] ) ++__rows;

        for( int __j{}; __j < __g.front().size(); ++__j )
            for( int __i{}; __i < ( __g.size() >> 1 ); ++__i )
                if( __g[__i][__j] != __g[__g.size() - 1 - __i][__j] ) ++__cols;

        return ( __rows < __cols ? __rows : __cols );
        
    }

};