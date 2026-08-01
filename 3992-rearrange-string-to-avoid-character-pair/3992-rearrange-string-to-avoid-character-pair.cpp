class Solution {
public:
    inline const string rearrangeString(
        const string&   __s, 
        const char&     __x, 
        const char&     __y
    ) const noexcept {
        string __res{};
        char __xc{};
        char __yc{};

        for( auto& __c : __s )
            if( __c == __x ) ++__xc;
            else if( __c == __y ) ++__yc;
            else __res += __c;
        
        return __res + string( __yc, __y ) + string( __xc, __x );

    }
};