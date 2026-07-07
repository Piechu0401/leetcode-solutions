# Write your MySQL query statement below
SELECT
    __ua1.user_id,
    ROUND(
        SUM(
            IF(
                __ua2.activity_type = 'free_trial',
                __ua2.activity_duration,
                0
            )
        ) / 
        SUM(
            IF(
                __ua2.activity_type = 'free_trial',
                1,
                0
            )
        ),
        2
    )
AS trial_avg_duration,
    ROUND(
        SUM(
            IF(
                __ua2.activity_type = 'paid',
                __ua2.activity_duration,
                0
            )
        ) / 
        SUM(
            IF(
                __ua2.activity_type = 'paid',
                1,
                0
            )
        ),
        2
    )
AS paid_avg_duration 
FROM UserActivity __ua1
JOIN UserActivity __ua2 ON 
    __ua1.user_id = __ua2.user_id AND
    (
        SELECT COUNT( activity_type )
        FROM UserActivity
        WHERE 
            activity_type = 'paid' AND
            user_id = __ua2.user_id
    ) > 0
GROUP BY user_id

# 1: ( 65 + 90 + 75 ) / 3 = 76.6666... ~ 76.67
# 1: ( 45 + 30 + 60 ) / 3 = 45 