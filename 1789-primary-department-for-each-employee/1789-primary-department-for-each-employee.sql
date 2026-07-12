# Write your MySQL query statement below
SELECT
    __e.employee_id, 
    __e.department_id
FROM Employee __e
WHERE 
    __e.primary_flag = 'Y' ||
    (
        SELECT COUNT( primary_flag )
        FROM Employee
        WHERE 
            primary_flag = 'Y' AND
            __e.employee_id = employee_id
    ) = 0