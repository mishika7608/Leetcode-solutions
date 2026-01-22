SELECT 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
FROM (
    SELECT*,
    DENSE_RANK() OVER(
        PARTITION BY departmentId
        ORDER BY salary DESC 
    )as rnk FROM EMPLOYEE
) e
JOIN DEpartment d ON
e.departmentId=d.id
WHERE rnk<=3;
