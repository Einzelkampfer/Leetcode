# Write your MySQL query statement below
SELECT DISTINCT
	p1.Email
FROM
	Person p1
JOIN Person p2 ON p1.Email = p2.Email
AND p1.id != p2.id;