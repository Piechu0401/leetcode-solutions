class Solution {
public:
    inline const string simplifyPath(
        string& __p
    ) const noexcept {
        stack<string> __st;
        bool __slash{};
        string __temp{""};

        for( auto& __c : __p ) {
            if( 
                __c == '/' &&
                __slash
            ) continue;
            
            __slash = ( __c == '/' );

            if( !__slash ) __temp += __c;
            else if( __temp == ".." ) {
                if( !__st.empty() )
                __st.pop();
                __temp = "";
                continue;

            }
            else if( __temp == "." ) {
                __temp = "";
                continue;
                
            }
            else {
                __st.push( __temp );
                // cout << __temp << "\n";
                __temp = "";

            }

        }

        if( 
            __temp.length() &&
            __temp != ".." &&
            __temp != "."
        ) __st.push( __temp );
        else if( __temp == ".." && !__st.empty() ) 
            __st.pop();

        __p = "";

        while( !__st.empty() ) {
            __p = "/" + __st.top() + __p;
            __st.pop();

        }

        if( !__p.length() ) return "/";
        
        __p = __p.substr( 1, __p.length() - 1 );

        if( __p.front() != '/' ) return "/" + __p;

        return __p;

    }
};