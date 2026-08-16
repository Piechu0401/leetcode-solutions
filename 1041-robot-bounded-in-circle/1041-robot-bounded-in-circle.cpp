class Solution {
public:
    inline const bool isRobotBounded(
        string& __is
    ) const noexcept {
        __is = __is + __is + __is + __is;
        char __x{};
        char __y{};
        char __dir{};

        for( auto& __i : __is )
            if( __i == 'R' ) __dir = ( --__dir < 0 ? 3 : __dir );
            else if( __i == 'L' ) __dir = ( ++__dir > 3 ? 0 : __dir );
            else if( !__dir ) ++__y;
            else if( __dir == 1 ) --__x;
            else if( __dir == 2 ) --__y;
            else if( __dir == 3 ) ++__x;

        return ( !__x && !__y );

    }
};