class Solution {
public:
    inline const int arrayNesting(
        vector<int>& __ns
    ) const noexcept {
        int __max{};
        vector<char> __vs( __ns.size(), 0 );

        for( int __i{}; __i < __ns.size(); ++__i ) {
            if( __vs[__i] ) continue;
            
            queue<pair<int, int>> __q;
            __vs[__i] = 1;
            __q.push( { __i, 1 } );

            while( !__q.empty() ) {
                if( __vs[__ns[__q.front().first]] ) break;
                
                __vs[__ns[__q.front().first]] = 1;
                __q.push( { __ns[__q.front().first], __q.front().second + 1 } );

                // cout << __q.front().first << " ";

                __max = __max < __q.front().second ? __q.front().second : __max;

                __q.pop();

            }

            // cout << "\n";

        }

        return ++__max;
        
    }
};