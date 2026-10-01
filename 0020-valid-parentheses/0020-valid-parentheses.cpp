class Solution {
public:
    inline const bool isValid(
        string& __s
    ) const noexcept {
        stack<char> __st;

        for( auto& __ch : __s )
            if(
                __ch == '(' ||
                __ch == '{' ||
                __ch == '['
            ) __st.push( __ch );
            else if(
                !__st.size() ||
                ( __st.top() == '(' && __ch != ')' ) ||
                ( __st.top() == '{' && __ch != '}' ) ||
                ( __st.top() == '[' && __ch != ']' )
            ) return 0;
            else __st.pop();

        return !__st.size();

    }
};