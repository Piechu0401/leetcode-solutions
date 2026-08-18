class Solution {
public:
    inline const int findShortestSubArray(
        const vector<int>& __ns
    ) const noexcept {
        unordered_map<int, vector<int>> __um;

        for( int __i{}; __i < __ns.size(); ++__i ) __um[__ns[__i]].emplace_back( __i );

        int __max{};
        int __min{INT_MAX};

        for( auto& __e : __um )
            if( __e.second.size() == __max ) {
                __min = 
                    (
                        __e.second.back() - __e.second.front() + 1 > __min ?\
                        __min :\
                        __e.second.back() - __e.second.front() + 1
                    );

            }
            else if( __e.second.size() > __max ) {
                __min = __e.second.back() - __e.second.front() + 1;
                __max = __e.second.size();

            }

        return __min;
        
    }
};