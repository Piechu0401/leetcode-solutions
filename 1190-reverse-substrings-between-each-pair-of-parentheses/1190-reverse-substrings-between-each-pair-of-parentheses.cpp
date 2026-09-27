class Solution {
public:
    inline const string reverseParentheses(
        string& __s
    ) const noexcept {
        stack<short> __st;
        short __i{};

        while( __i < __s.length() ) {
            if( __s[__i] == '(' ) __st.push( __i );
            else if( __s[__i] == ')' ) {
                string __temp{ __s.substr( __st.top() + 1, __i - __st.top() - 1 ) };
                __s.erase( __s.begin() + __st.top(), __s.begin() + __i + 1 );
                // reverse( __temp.begin(), __temp.end() );
                __s.insert( __s.begin() + __st.top(), __temp.rbegin(), __temp.rend() );
                __i = __st.top();
                __st.pop();
                continue;

            }
            
            ++__i;

        }

        return __s;
        
    }
};

// (ed(et(oc))el)
// (ed(etco)el)
// (edocteel)
// leetcode