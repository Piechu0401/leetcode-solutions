class Solution {
public:
    inline const vector<string> divideString(
        string& __s, 
        int&    __k, 
        char&   __f
    ) const noexcept {
        vector<string> __res;
        char __i{};

        while( __i < __s.length() ) {
            if( __s.length() - __i >= __k ) __res.push_back( __s.substr( __i, __k ) );
            else __res.push_back( 
                __s.substr( __i, __s.length() - __i ) + 
                string( __k - ( __s.length() - __i ), __f ) 
            );

            __i += __k;

        }

        return __res;
        
    }
};