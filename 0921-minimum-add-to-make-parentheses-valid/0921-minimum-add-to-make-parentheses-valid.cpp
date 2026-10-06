class Solution {
public:
    inline const int minAddToMakeValid(
        string& __s
    ) const noexcept {
        short __res{};
        short __count{};

        for( auto& __c : __s ) 
            if( __c == '(' ) ++__count;
            else if( __count ) {
                __res += 2;
                --__count;

            }

        return __s.length() - __res;
        
    }
};