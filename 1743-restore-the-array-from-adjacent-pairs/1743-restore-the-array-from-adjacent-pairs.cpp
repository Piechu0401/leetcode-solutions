class Solution {
public:
    inline const vector<int> restoreArray(
        const vector<vector<int>>& __ap
    ) const noexcept {
        vector<int> __res;
        unordered_map<int, unordered_set<int>> __um;

        for( auto& __p : __ap ) {
            __um[__p.front()].insert( __p.back() );
            __um[__p.back()].insert( __p.front() );

        }

        for( auto& __p : __um )
            if( __p.second.size() == 1 ) {
                __res.emplace_back( __p.first );
                __res.emplace_back( *__p.second.begin() );

                unordered_set<int> __in;
                __in.insert( __p.first );
                __in.insert( *__p.second.begin() );

                while( __um[__res.back()].size() == 2 ) {
                    auto __it1 = __um[__res.back()].begin();
                    auto __it2 = next( __um[__res.back()].begin(), 1 );
                    
                    if( !__in.count( *__it2 ) ) {
                        __res.emplace_back( *__it2 );
                        __in.insert( *__it2 );

                    }
                    else {
                        __res.emplace_back( *__it1 );
                        __in.insert( *__it1 );
                    
                    }

                    // cout << __res.back() << "\n";

                }
                
                break;

            }

        return __res;

    }
};