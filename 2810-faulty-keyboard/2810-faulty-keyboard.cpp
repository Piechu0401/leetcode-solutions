class Solution {
public:
    inline const string finalString(
        const string& __s
    ) const noexcept {
        string __res{};

        for( auto& __c : __s ) {
            if( __c == 'i' ) reverse( __res.begin(), __res.end() );
            else __res += __c;

        }

        return __res;
        
    }
};