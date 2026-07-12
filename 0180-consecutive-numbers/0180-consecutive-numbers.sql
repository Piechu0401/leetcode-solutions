# Write your MySQL query statement below
SELECT
    DISTINCT __ls.num
AS ConsecutiveNums
FROM Logs __ls
WHERE (
    SELECT COUNT( id )
    FROM Logs
    WHERE 
        num = __ls.num &&
        (
            id = __ls.id + 1 ||
            id = __ls.id + 2
        )
) = 2