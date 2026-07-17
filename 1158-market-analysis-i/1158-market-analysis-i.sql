# Write your MySQL query statement below
SELECT
    __us.user_id
AS buyer_id,
    __us.join_date,
    (
        SELECT COUNT( __os.order_id )
        FROM Orders __os
        WHERE
            __os.order_date LIKE '2019%' &&
            __os.buyer_id = __us.user_id
    )
AS orders_in_2019
FROM Users __us
GROUP BY user_id