class Solution {
public:
    inline const vector<vector<string>> findDuplicate(
        vector<string>& __ps
    ) const noexcept {
        vector<vector<string>>                  __res;
        unordered_map<string, vector<string>>   __um;

        for( auto& __p : __ps ) {
            short __idx{};

            while( __p[++__idx] != ' ' );

            string __location{ __p.substr( 0, __idx ) };

            // cout << __location << "\n";

            ++__idx;

            while( __idx < __p.length() ) {
                short __begin{__idx};

                string __name{};
                string __content{};
                char __open{};

                while(
                    __idx < __p.length() &&
                    __p[__idx] != ')'
                ) {
                    if( !__open ) {
                        if( __p[__idx] == '(' ) __open = 1;
                        else __name += __p[__idx];

                    } else __content += __p[__idx];

                    ++__idx;

                }

                __um[__content].push_back( __location + "/" + __name );

                // cout << "\t" << __name << " " << __content << "\n";

                __idx += 2;

            }

        }

        for( auto& __u : __um ) if( __u.second.size() > 1 ) __res.emplace_back( __u.second );

        return __res;
        
    }
};