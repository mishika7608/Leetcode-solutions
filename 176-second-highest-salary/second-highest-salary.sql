# Write your MySQL query statement below
SELECT IFNULL(
    (
    SELECT MAX(salary) FROM(
    SELECT salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) as rnk
        FROM Employee) e WHERE rnk=2
), NULL) AS SecondHighestSalary;