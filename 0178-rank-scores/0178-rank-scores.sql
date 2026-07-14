# Write your MySQL query statement below
WITH __res ( score )
AS (
    SELECT DISTINCT
        score
    FROM Scores
    ORDER BY score DESC
)

#SELECT *
#FROM __res

SELECT
    __ss.score,
    (    
        SELECT 
            __rn
        FROM (
            SELECT *,
                ROW_NUMBER() OVER ()
            AS __rn
            FROM __res
        ) __fuckers
        WHERE 
            __fuckers.score = __ss.score
    ) AS `rank`
FROM Scores __ss
RIGHT JOIN __res __r ON
    __r.score = __ss.score
ORDER BY score DESC