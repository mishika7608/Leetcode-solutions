# Write your MySQL query statement below
-- SELECT email AS Email FROM Person p
-- JOIN (
-- ) e
-- ON p.email=e.email;
    SELECT email FROM Person 
    GROUP BY email HAVING COUNT(*)>1