# Write your MySQL query statement below
SELECT
    __e.name
AS Employee
FROM Employee __e
WHERE
    __e.managerId IS NOT NULL AND
    (
        __e.salary > (
            SELECT salary
            FROM Employee
            WHERE 
                __e.managerId = id
        )
    )