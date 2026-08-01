class Solution {
public:
    inline const string rearrangeString(
        const string&   __s, 
        const char&     __x, 
        const char&     __y
    ) const noexcept {
        string __res{};

        for( auto& __c : __s )
            if( __c == __x ) __res += __x;
            else if( __c == __y ) __res = __y + __res;
            else __res += __c;
        
        return __res;

    }
};