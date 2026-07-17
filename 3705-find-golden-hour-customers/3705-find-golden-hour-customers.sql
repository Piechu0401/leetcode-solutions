# Write your MySQL query statement below
SELECT 
    __ros.customer_id,
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
            __ros.customer_id = customer_id
    )
AS total_orders,
    ROUND(
        (
            SELECT COUNT( order_id )
            FROM restaurant_orders
            WHERE
                __ros.customer_id = customer_id &&
                (
                    TIME( order_timestamp ) BETWEEN '11:00' AND '14:00' ||
                    TIME( order_timestamp ) BETWEEN '18:00' AND '21:00'
                )
        ) / 
        (
            SELECT COUNT( order_id )
            FROM restaurant_orders
            WHERE
               __ros.customer_id = customer_id
        ) * 100,
        0
    )
AS peak_hour_percentage,
    ROUND(
        (
            SELECT AVG( order_rating )
            FROM restaurant_orders
            WHERE
               __ros.customer_id = customer_id        
        ),
        2
    )
AS average_rating
FROM restaurant_orders __ros
WHERE
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
           __ros.customer_id = customer_id
    ) > 2 &&
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
            __ros.customer_id = customer_id &&
            (
                TIME( order_timestamp ) BETWEEN '11:00' AND '14:00' ||
                TIME( order_timestamp ) BETWEEN '18:00' AND '21:00'
            )
    ) / 
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
           __ros.customer_id = customer_id
    ) >= 0.6 &&
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
           __ros.customer_id = customer_id &&
           order_rating IS NOT NULL
    ) / 
    (
        SELECT COUNT( order_id )
        FROM restaurant_orders
        WHERE
           __ros.customer_id = customer_id
    ) >= 0.5 &&
    (
        SELECT AVG( order_rating )
        FROM restaurant_orders
        WHERE
           __ros.customer_id = customer_id        
    ) >= 4.0
GROUP BY customer_id
ORDER BY average_rating DESC, customer_id DESC