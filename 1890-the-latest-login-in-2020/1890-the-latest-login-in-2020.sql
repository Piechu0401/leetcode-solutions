# Write your MySQL query statement below
WITH __res ( user_id, time_stamp )
AS (
    SELECT
        __ls.user_id,
        __ls.time_stamp
    FROM Logins __ls
    WHERE
        __ls.time_stamp REGEXP '2020+'
    ORDER BY user_id, time_stamp ASC
)
SELECT DISTINCT
    __r.user_id,
    (
        SELECT MAX( time_stamp )
        FROM __res
        WHERE
            __r.user_id = user_id
    )
AS last_stamp
FROM __res __r