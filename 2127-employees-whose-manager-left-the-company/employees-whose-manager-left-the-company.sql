# Write your MySQL query statement below
-- SELECT e.employee_id FROM
-- Employees e
-- WHERE e.manager_id IS IN e.employee_id AND e.salary < 30000;

SELECT e.employee_id FROM
Employees e
LEFT JOIN
(SELECT employee_id as id FROM Employees) d 
ON e.manager_id = d.id
WHERE e.manager_id IS NOT NULL AND 
d.id IS NULL AND e.salary<30000
ORDER BY e.employee_id;
