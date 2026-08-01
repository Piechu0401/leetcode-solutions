class Solution {
public:
    inline const int secondsBetweenTimes(
        const string& __st, 
        const string& __et
    ) const noexcept {
        return
            abs(
                (
                    ( __st[0] - 48 ) * 10 +
                    ( __st[1] - 48 )
                ) * 3600 +
                (
                    ( __st[3] - 48 ) * 10 +
                    ( __st[4] - 48 )
                ) * 60 +
                (
                    ( __st[6] - 48 ) * 10 +
                    ( __st[7] - 48 )
                ) -
                (
                    ( __et[0] - 48 ) * 10 +
                    ( __et[1] - 48 )
                ) * 3600 -
                (
                    ( __et[3] - 48 ) * 10 +
                    ( __et[4] - 48 )
                ) * 60 -
                (
                    ( __et[6] - 48 ) * 10 +
                    ( __et[7] - 48 )
                )
            );
        
    }
};