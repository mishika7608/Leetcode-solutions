# Write your MySQL query statement below
SELECT MAX(M.num) as num
FROM MyNumbers M
JOIN (
    SELECT num,
    COUNT(num) as cnt FROM MyNumbers GROUP BY num
) C ON M.num=C.num AND C.cnt=1;