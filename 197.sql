SELECT
	w2.Id
FROM
	`Weather` AS w1
JOIN Weather AS w2 ON DATEDIFF(w1.Date, w2.Date) = -1
WHERE
	w1.Temperature < w2.Temperature;