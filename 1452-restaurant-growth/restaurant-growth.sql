# Write your MySQL query statement below
WITH daily_totals AS (
    SELECT 
        visited_on,
        SUM(amount) AS total_amount
    FROM Customer
    GROUP BY visited_on
),
moving_window AS (
    SELECT
        a.visited_on,
        SUM(b.total_amount) AS amount,
        ROUND(AVG(b.total_amount), 2) AS average_amount
    FROM daily_totals a
    JOIN daily_totals b 
    ON b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
    GROUP BY a.visited_on
    HAVING COUNT(b.visited_on) = 7
)
SELECT 
    visited_on,
    amount,
    average_amount
FROM moving_window
ORDER BY visited_on;