# Write your MySQL query statement below
SELECT E.name as Employee FROM Employee E JOIN Employee S ON E.managerId=S.id WHERE E.salary>S.salary;