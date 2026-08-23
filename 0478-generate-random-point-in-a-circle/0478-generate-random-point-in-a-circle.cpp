class Solution {
public:
    explicit Solution(
        const double& __r, 
        const double& __x, 
        const double& __y
    ) noexcept :
        __rc( __r ),
        __xc( __x ),
        __yc( __y )
    {
        __gen = mt19937( __rd() );
        __urd = uniform_real_distribution<double>( 0.00000, 1.00000 );

    }
    
    inline const vector<double> randPoint() noexcept {
        const double __dst = __urd( __gen ); 
        const double __rad = __urd( __gen ) * 2.00000 * 3.14159;
        const double __r = __rc * sqrt( __dst );

        return { cos( __rad ) * __r + __xc, sin( __rad ) * __r + __yc };    

    }

    const double __rc;
    const double __xc; 
    const double __yc;

    random_device __rd;
    mt19937 __gen;
    uniform_real_distribution<double> __urd;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */