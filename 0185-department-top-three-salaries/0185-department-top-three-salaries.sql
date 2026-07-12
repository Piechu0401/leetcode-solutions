# Write your MySQL query statement below
WITH __res ( departmentId, salary )
AS (
    SELECT DISTINCT
        departmentId,
        salary
    FROM Employee
    GROUP BY departmentId, salary
    ORDER BY departmentId, salary
)
# SELECT * 
# FROM __res

SELECT 
    (
        SELECT name
        FROM Department
        WHERE id = __e.departmentId
    )
AS Department,
    __e.name 
AS `Employee`,
    __e.salary
AS Salary
FROM __res
JOIN Employee __e ON (
    __e.salary IN (
        SELECT salary
        FROM (
            SELECT *,
                ROW_NUMBER() OVER ( ORDER BY salary DESC )
            AS __rn
            FROM __res
            WHERE __e.departmentId = __res.departmentId
        ) __fuckers 
        WHERE __rn < 4
    ) 
)
GROUP BY Department, Employee, Salary