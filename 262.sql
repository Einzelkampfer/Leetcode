# Write your MySQL query statement below
SELECT
	Trips.Request_at AS `Day`,
	round(
		SUM(

			IF (
				Trips. STATUS = "completed",
				0,
				1
			)
		) / count(Trips.id),
		2
	) AS `Cancellation Rate`
FROM
	Trips
JOIN Users ON Trips.Client_Id = Users.Users_id
AND Users.Banned = "No"
WHERE
	Trips.Request_at BETWEEN "2013-10-01"
AND "2013-10-03"
GROUP BY
	Trips.Request_at;