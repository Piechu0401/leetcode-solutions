# Write your MySQL query statement below
SELECT
    __a1.machine_id,
    ROUND(
        SUM(
            IF(
                __a1.activity_type = 'start',
                __a2.timestamp - __a1.timestamp,
                0
            )
        ) / 
        SUM(
            IF(
                __a2.process_id = __a1.process_id,
                0.5,
                0        
            )
        ),
        3
    )
AS processing_time
FROM Activity __a1
JOIN Activity __a2 ON 
    __a2.activity_type = 'end' AND
    __a2.process_id = __a1.process_id AND
    __a2.machine_id = __a1.machine_id 
GROUP BY machine_id