# Write your MySQL query statement below
WITH __res ( turn, person_id, person_name, weight, total_weight )
AS (
    SELECT
        turn,
        person_id,
        person_name,
        weight,
        SUM( weight ) OVER ( ORDER BY turn )
    FROM Queue
    GROUP BY person_id
    ORDER BY turn
)
SELECT person_name 
FROM __res
WHERE total_weight = (
    SELECT MAX( total_weight )
    FROM __res
    WHERE total_weight <= 1000
)