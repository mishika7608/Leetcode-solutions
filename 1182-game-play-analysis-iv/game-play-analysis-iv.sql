# Write your MySQL query statement below

SELECT
    ROUND(
        SUM(a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY))/COUNT(DISTINCT a.player_id)
        , 2
    ) AS fraction
    FROM Activity a
    JOIN (
        SELECT MIN(event_date) AS first_date, player_id
        FROM Activity GROUP BY player_id
    ) f
    ON a.player_id=f.player_id;
