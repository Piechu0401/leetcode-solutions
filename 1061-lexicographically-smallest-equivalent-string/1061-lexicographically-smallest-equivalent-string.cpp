class Solution {
public:
    inline const string smallestEquivalentString(
        const string& __s1, 
        const string& __s2, 
        string& __bs
    ) const noexcept {
        unordered_map<char, vector<char>> __um;

        for( short __i{}; __i < __s1.length(); ++__i ) {
            __um[__s1[__i]].emplace_back( __s2[__i] );
            __um[__s2[__i]].emplace_back( __s1[__i] );

        }

        for( auto& __c : __bs ) {
            char __min{ __c };
            char __letts[26]{};

            queue<char> __q;
            __q.push( __c );

            while( !__q.empty() ) {
                __min = ( __q.front() < __min ? __q.front() :__min );

                for( auto& __l : __um[__q.front()] )
                    if( !__letts[__l - 97] ) {
                        ++__letts[__l - 97];
                        __q.push( __l );

                    }
                
                __q.pop();

            }

            __c = __min;

        }

        return __bs;

    }
};