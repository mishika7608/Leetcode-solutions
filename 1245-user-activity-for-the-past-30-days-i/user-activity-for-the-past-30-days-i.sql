# Write your MySQL query statement below
SELECT activity_date as day , COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date  BETWEEN '2019-06-28' AND DATE_ADD('2019-06-28', INTERVAL 30 DAY)
GROUP BY activity_date;