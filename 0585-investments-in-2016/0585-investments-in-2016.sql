# Write your MySQL query statement below
WITH __res ( tiv_2016, tiv_2015, lat, lon )
AS (
    SELECT __i.tiv_2016, __i.tiv_2015, __i.lat, __i.lon
    FROM Insurance __i
    HAVING
        (
            SELECT 
                COUNT( pid )
            FROM Insurance
            WHERE 
                __i.tiv_2015 = tiv_2015            
        ) > 1 &&
        (
            SELECT 
                COUNT( pid )
            FROM Insurance
            WHERE 
                __i.lat = lat &&
                __i.lon = lon
        ) < 2
)
SELECT 
    ROUND(
        SUM( tiv_2016 ),
        2
    )
AS tiv_2016
FROM __res
