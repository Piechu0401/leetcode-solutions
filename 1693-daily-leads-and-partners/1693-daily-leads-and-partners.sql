# Write your MySQL query statement below
SELECT
    __dss.date_id,
    __dss.make_name,
    (
        SELECT COUNT( DISTINCT lead_id )
        FROM DailySales
        WHERE
            date_id = __dss.date_id &&
            make_name = __dss.make_name
    )
AS unique_leads,
    (
        SELECT COUNT( DISTINCT partner_id )
        FROM DailySales
        WHERE
            date_id = __dss.date_id &&
            make_name = __dss.make_name
    )
AS unique_partners
FROM DailySales __dss
GROUP BY date_id, make_name