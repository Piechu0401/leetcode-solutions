# Write your MySQL query statement below
WITH __res ( id, visit_date, people )
AS (
    SELECT
        id, 
        visit_date, 
        people
    FROM Stadium
    WHERE 
        people > 99
)

SELECT *
FROM __res __r
WHERE
    (
        (
            ( __r.id - 1 ) IN (
                SELECT id
                FROM __res 
            ) &&
            ( __r.id + 1 ) IN (
                SELECT id
                FROM __res 
            )
        ) ||
        (
            ( __r.id - 1 ) IN (
                SELECT id
                FROM __res 
            ) &&
            ( __r.id - 2 ) IN (
                SELECT id
                FROM __res 
            )
        ) ||
        (
            ( __r.id + 1 ) IN (
                SELECT id
                FROM __res 
            ) &&
            ( __r.id + 2 ) IN (
                SELECT id
                FROM __res 
            )
        )
    )
    
