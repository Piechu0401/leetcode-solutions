# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE id & 1 = 1 AND description != 'Boring'
ORDER BY rating DESC