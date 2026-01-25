# Write your MySQL query statement below
SELECT s.id AS Id 
FROM Weather w
JOIN Weather s
ON DATEDIFF(s.recordDate,w.recordDate) = 1
WHERE s.temperature > w.temperature;
