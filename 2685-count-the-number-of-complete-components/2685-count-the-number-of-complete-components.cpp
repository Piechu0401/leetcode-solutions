class Solution {
public:
    inline const int countCompleteComponents(
        const int& __n, 
        const vector<vector<int>>& __es
    ) const noexcept {
        int __res{};

        unordered_map<int, unordered_set<int>> __g;

        for( auto& __e : __es ) {
            __g[__e.front()].insert( __e.back() );
            __g[__e.back()].insert( __e.front() );

        }

        vector<bool> __visited( __n, 0 );

        for( char __i{}; __i < __n; ++__i ) {
            if( __visited[__i] ) continue;
            else if( !__g[__i].size() ) {
                ++__res;
                continue;

            }

            queue<int> __q;
            __q.push( __i );
            bool __add{1};
            char __distinct{};
            const int __size = __g[__q.front()].size();

            while( !__q.empty() ) {
                // cout << "queue: " << __q.front() << "\n";

                if( __visited[__q.front()] ) {
                    if( __size != __g[__q.front()].size() ) {
                        __add = 0;
                        // cout 
                        //     << "vistetd: "
                        //     << __size << " " 
                        //     << __q.front() << " " 
                        //     << __g[__q.front()].size() << "\n";

                    }
                    __q.pop();
                    continue;

                }

                const int __s = __g[__q.front()].size();

                if( __s != __size ) {
                    __add = 0;
                        // cout 
                        //     << "not vistetd: "
                        //     << __size << " " 
                        //     << __q.front() << " " 
                        //     << __g[__q.front()].size() << "\n";
                    
                }

                for( auto& __v : __g[__q.front()] )
                    __q.push( __v );

                __visited[__q.front()] = 1;
                ++__distinct;
                __q.pop();

            }

            // cout << (int)__distinct << " " << __size << "\n";

            if( __add && __distinct == __size + 1 ) {
                ++__res;
                
            }

        }

        return __res;
        
    }
};