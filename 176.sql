# Write your MySQL query statement below
SELECT (SELECT DISTINCT Salary From Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1) AS second;