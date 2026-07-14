# Write your MySQL query statement below

# dear author of this task --> wonhay hooya.

WITH __res ( id, name, number, type )
AS (
    SELECT
        __ms.movie_id
    AS id,
        __ms.title
    AS name,
        (
            SELECT AVG( __mr.rating )
            FROM MovieRating __mr
            WHERE
                __ms.movie_id = __mr.movie_id AND
                __mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
        )
    AS number,
        (
            1
        )
    AS type
    FROM Movies __ms
    UNION ALL
    SELECT
        __us.user_id
    AS id,
        __us.name
    AS name,
        (
            SELECT COUNT( __mr.rating )
            FROM MovieRating __mr
            WHERE
                __us.user_id = __mr.user_id
        )
    AS number,
        (
            0
        )
    AS type
    FROM Users __us
)

# SELECT *
# FROM __res
# ORDER BY number DESC, name ASC

SELECT name
AS results
FROM ( 
    (
        SELECT 
            name
        FROM (
            SELECT 
                *,
                ROW_NUMBER() OVER ()
            AS __rn
            FROM __res
            WHERE type = 0
            ORDER BY number DESC, name ASC
        ) __fuckers
        WHERE 
            __rn < 2
    ) 
    UNION ALL
    (
        SELECT 
            name
        FROM (
            SELECT 
                *,
                ROW_NUMBER() OVER ()
            AS __rn
            FROM __res
            WHERE type = 1
            ORDER BY number DESC, name ASC
        ) __fuckers
        WHERE 
            __rn < 2
    )
) __fuckers