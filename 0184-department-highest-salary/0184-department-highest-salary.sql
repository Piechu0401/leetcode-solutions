# Write your MySQL query statement below
WITH __res ( Id, DepartmentId, Salary )
AS (
    SELECT
        __e1.id
    AS Id,
        __e1.departmentId
    AS DepartmentId,
        __e1.salary
    AS Salary
    FROM Employee __e1
    WHERE ( __e1.departmentId, __e1.salary ) IN (
        SELECT DISTINCT
            departmentId, 
            MAX( salary )
        FROM Employee
        GROUP BY departmentId
    )
)

#SELECT *
#FROM __res

SELECT
    (
        SELECT name
        FROM Department
        WHERE
            id = __r.DepartmentId
    )
AS `Department`,
    (
        SELECT name
        FROM Employee
        WHERE
            __r.Id = id
    )
AS `Employee`,
    Salary
FROM __res __r