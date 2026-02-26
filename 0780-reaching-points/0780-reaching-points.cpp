class Solution {
public:
    bool reachingPoints(
        int __sx, 
        int __sy,
        int __tx, 
        int __ty
    ) {
        // thats just easy work with recurention
        // we repeat operations in function until
        // sx and sy arent equal to tx and ty or greater than them
        // EDIT:
        // okay so after recurention approach clearly failed I figured out
        // that we can do things in reverse by trying to achieve
        // sx and sy from tx and ty by subtracting them from eachother and seeing if this
        // will lead to sy and sx in a loop, lets try this.

        if( __sx == __tx && __sy == __ty ) return 1;
        else if( __sx == __sy && __tx == __ty ) return 0;

        while( __tx >= __sx && __ty >= __sy ) {
            if( __tx == __sx && __ty == __sy ) return 1;
            else if( __tx > __ty ) 
                if( __sy < __ty ) __tx %= __ty;
                else return (__tx - __sx) % __ty == 0;
            else 
                if( __sx < __tx ) __ty %= __tx;
                else return (__ty - __sy) % __tx == 0;

        }

        return __tx == __sx && __ty == __sy;

    }
};