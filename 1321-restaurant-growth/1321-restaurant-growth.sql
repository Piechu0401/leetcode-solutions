# Write your MySQL query statement below
WITH __res ( first_date, last_date )
AS (
    SELECT DISTINCT
        __c1.visited_on
    AS first_date,
        __c2.visited_on
    AS last_date
    FROM Customer __c1
    JOIN Customer __c2 ON
        __c2.visited_on = DATE_ADD(
            __c1.visited_on,
            INTERVAL 6 DAY
        ) AND
        __c2.visited_on IN (
            SELECT visited_on
            FROM Customer
        )
)
SELECT  
    last_date
AS visited_on,
    (
        SELECT SUM( amount )
        FROM Customer
        WHERE
            visited_on BETWEEN first_date AND last_date
    )
AS amount,
    (
        SELECT
            ROUND( 
                SUM( amount ) / 7,
                2
            )
        FROM Customer
        WHERE
            visited_on BETWEEN first_date AND last_date
    )
AS average_amount
FROM __res