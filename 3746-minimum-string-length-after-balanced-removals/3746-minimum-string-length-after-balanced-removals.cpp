class Solution {
public:
    inline const int minLengthAfterRemovals(
        const string& __s
    ) const noexcept {
        stack<char> __st;
        int __res{};

        for( auto& __c : __s ) {
            if(
                __st.size() &&
                __st.top() != __c
            ) {
                __res += 2;
                __st.pop();
                continue;

            }

            __st.push( __c );

        }

        return __s.length() - __res;
        
    }
};