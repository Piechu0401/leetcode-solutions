class Solution {
public:
    inline const int numSimilarGroups(
        vector<string>& __ss
    ) const noexcept {
        int __res{};
        unordered_map<string, unordered_set<string>> __um;

        for( short __i{}; __i < __ss.size(); ++__i )
            for( short __j{}; __j < __ss.size(); ++__j ) {
                if( __i == __j ) continue;

                short __diffs{};

                for( short __k{}; __k < __ss[__i].length(); ++__k )
                    __diffs += ( __ss[__i][__k] != __ss[__j][__k] ? 1 : 0 );

                if( __diffs == 2 ) __um[__ss[__i]].insert( __ss[__j] );

            }

        unordered_set<string> __used;

        for( auto& __s : __ss ) {
            if( __used.count( __s ) ) continue;
            
            queue<string> __q;
            __q.push( __s );
            __used.insert( __s );

            while( !__q.empty() ) {
                for( auto& __str : __um[__q.front()] ) 
                    if( !__used.count( __str ) ) {
                        __q.push( __str );
                        __used.insert( __str );

                    }

                __q.pop();

            }

            ++__res;

        }

        return __res;

    }
};