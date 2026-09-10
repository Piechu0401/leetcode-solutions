class Solution {
public:
    explicit Solution(
        const int& __n, 
        vector<int>& __bl
    ) noexcept :
        __fuckAss( __n )
    {
        sort( __bl.begin(), __bl.end() );
        
        if( __bl.size() == 1 && !__bl.front() )
            __allowed.push_back( { 1, __n - 1 } );
        else for( int __i{}; __i < __bl.size(); ++__i ) {
            if( __i ) {
                if( __bl[__i] - __bl[__i - 1] == 1 ) continue;     

                __allowed.push_back( { 
                    __bl[__i - 1] + 1, 
                    __bl[__i] - 1 
                } );

            }  
            else {
                if( __bl.size() > 1 && __bl[__i + 1] == 1 || !__bl[__i] ) continue; 
                __allowed.push_back( { 0, __bl[__i] - 1 == -1 ? 0 : __bl[__i] - 1 } );

            }

            // cout << __allowed.back().first << " " << __allowed.back().second << "\n";

        }

        if( __bl.size() && __bl.back() != __n - 1 ) {
            __allowed.push_back( { 
                __bl.back() + 1 > ( !__n ? 0 : __n - 1 ) ? ( !__n ? 0 : __n - 1 ) : __bl.back() + 1,
                ( !__n ? 0 : __n - 1 ) < __bl.back() + 1 ? __bl.back() + 1 : ( !__n ? 0 : __n - 1 )
            } );
            // cout << __allowed.back().first << " " << __allowed.back().second << "\n";

        }

    }
    
    inline const int pick() { 
        if( !__allowed.size() ) return rand() % ( __fuckAss);

        pair<int, int> __rand = __allowed[rand() % __allowed.size()];

        return __rand.first + ( rand() % ( __rand.second - __rand.first + 1 ) );
        
    }

    const int               __fuckAss;
    vector<pair<int, int>>  __allowed;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */