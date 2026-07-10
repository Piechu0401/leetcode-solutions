# Write your MySQL query statement below
WITH __res( player_id, date )
AS (
    SELECT
        __a.player_id,
        MIN( __a.event_date )
    AS date
    FROM Activity __a
    GROUP BY player_id
)
SELECT 
    ROUND(
        SUM(
            IF(
                DATE_ADD(
                    __r.date,
                    INTERVAL 1 DAY
                ) IN (
                    SELECT event_date
                    FROM Activity
                    WHERE __r.player_id = player_id
                ),
                1,
                0
            )
        ) / (
            SELECT COUNT( player_id )
            FROM __res
        ),
        2
    )
AS fraction
FROM __res __r