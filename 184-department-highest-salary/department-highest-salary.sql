# Write your MySQL query statement below
SELECT d.name as Department, e.name as Employee,e.salary as Salary
    FROM Employee e JOIN Department d ON e.departmentId=d.id
    JOIN(
        SELECT departmentId, MAX(salary) as max_salary
        FROM Employee GROUP BY departmentId
    ) m
    ON e.departmentId=m.departmentId 
    AND e.salary=max_salary;