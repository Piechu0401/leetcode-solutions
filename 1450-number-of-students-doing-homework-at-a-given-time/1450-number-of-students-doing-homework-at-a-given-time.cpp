class Solution {
public:
    inline const int busyStudent(
        const vector<int>& __st, 
        const vector<int>& __et, 
        const int& __qt
    ) const noexcept {
        char __res{};

        for( char __i{}; __i < __st.size(); ++__i )
            if(
                __st[__i] <= __qt &&
                __et[__i] >= __qt
            ) ++__res;

        return __res;
        
    }
};