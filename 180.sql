# Write your MySQL query statement below
SELECT DISTINCT
	l1.Num
FROM
	Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
AND l1.Num = l2.Num
JOIN Logs l3 ON l2.id = l3.id - 1
AND l3.Num = l2.Num;