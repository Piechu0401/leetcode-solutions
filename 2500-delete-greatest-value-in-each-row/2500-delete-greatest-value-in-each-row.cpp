class Solution {
public:
    inline const int deleteGreatestValue(
        const vector<vector<int>>& __g
    ) const noexcept {
        vector<priority_queue<int>> __rs;

        for( auto& __v : __g ) 
            __rs.push_back(
                priority_queue<int>( __v.begin(), __v.end() )
            );

        int __res{};

        while( !__rs.front().empty() ) {
            int __max{};

            for( auto& __r : __rs ) {
                if( __r.top() > __max ) __max = __r.top();
                __r.pop();

            }

            __res += __max;

        }

        return __res;

    }
};