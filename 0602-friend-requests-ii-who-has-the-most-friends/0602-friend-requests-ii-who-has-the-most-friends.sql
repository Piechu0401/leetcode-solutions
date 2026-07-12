# Write your MySQL query statement below
WITH __res ( id )
AS (
    SELECT DISTINCT requester_id
    FROM RequestAccepted
    UNION
    SELECT DISTINCT accepter_id
    FROM RequestAccepted
)
SELECT 
    __r.id,
    COUNT( __ra.accept_date )
AS num
FROM __res __r
JOIN RequestAccepted __ra ON
    __ra.requester_id = __r.id ||
    __ra.accepter_id = __r.id
GROUP BY id
ORDER BY num DESC
LIMIT 0, 1