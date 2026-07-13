# Write your MySQL query statement below
SELECT
    __p.firstName,
    __p.lastName,
    IF(
        __p.personId IN (
            SELECT personId
            FROM Address
        ),
        (
            SELECT city
            FROM Address
            WHERE
                __p.personId = personId
        ),
        NULL
    )
AS city,
    IF(
        __p.personId IN (
            SELECT personId
            FROM Address
        ),
        (
            SELECT state
            FROM Address
            WHERE
                __p.personId = personId
        ),
        NULL
    )
AS state
FROM Person __p