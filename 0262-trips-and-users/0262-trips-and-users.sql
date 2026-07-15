# Write your MySQL query statement below
SELECT
    __ts1.request_at
AS `Day`,
    ROUND(
        (
            SELECT 
                COUNT(*)
            FROM Trips __ts2
            WHERE ( 
                __ts2.status LIKE 'ca%' AND
                __ts2.request_at = __ts1.request_at AND
                __ts2.client_id NOT IN (
                    SELECT 
                        __us.users_id
                    AS id
                    FROM Users __us
                    WHERE 
                        __us.banned = 'Yes'
                ) AND
                __ts2.driver_id NOT IN (
                    SELECT 
                        __us.users_id
                    AS id
                    FROM Users __us
                    WHERE 
                        __us.banned = 'Yes'
                )
            )
        ) /
        (
            SELECT 
                COUNT(*)
            FROM Trips __ts2
            WHERE ( 
                __ts2.request_at = __ts1.request_at AND
                __ts2.client_id NOT IN (
                    SELECT 
                        __us.users_id
                    AS id
                    FROM Users __us
                    WHERE 
                        __us.banned = 'Yes'
                ) AND
                __ts2.driver_id NOT IN (
                    SELECT 
                        __us.users_id
                    AS id
                    FROM Users __us
                    WHERE 
                        __us.banned = 'Yes'
                )
            )
        ),
        2
    )
AS `Cancellation Rate`
FROM Trips __ts1
WHERE
    (
        __ts1.request_at BETWEEN '2013-10-01' AND '2013-10-03' 
    ) AND
    (
        SELECT 
            COUNT(*)
        FROM Trips __ts2
        WHERE ( 
            __ts2.request_at = __ts1.request_at AND
            __ts2.client_id NOT IN (
                SELECT 
                    __us.users_id
                AS id
                FROM Users __us
                WHERE 
                    __us.banned = 'Yes'
            ) AND
            __ts2.driver_id NOT IN (
                SELECT 
                    __us.users_id
                AS id
                FROM Users __us
                WHERE 
                    __us.banned = 'Yes'
            )
        )
    ) > 0
GROUP BY `Day`