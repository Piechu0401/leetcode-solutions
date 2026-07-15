# Write your MySQL query statement below
WITH __res ( product_id, max_date_less_than_that_fuck_ass_date )
AS (
    SELECT
        __ps.product_id,
        (
            SELECT MAX( change_date )
            FROM Products
            WHERE
                __ps.product_id = product_id AND
                change_date <= '2019-08-16'
        )
    AS max_date_less_than_that_fuck_ass_date
    FROM Products __ps
    GROUP BY product_id
)
SELECT 
    __r.product_id,
    (
        CASE
            WHEN max_date_less_than_that_fuck_ass_date IS NULL
            THEN 10
            ELSE
                (
                    SELECT new_price
                    FROM Products
                    WHERE
                        __r.product_id = product_id AND
                        max_date_less_than_that_fuck_ass_date = change_date
                )
        END
    )
AS price
FROM __res __r