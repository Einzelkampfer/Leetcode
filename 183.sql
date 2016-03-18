SELECT
	grt. NAME as Customers
FROM
	(
		SELECT
			count(Orders.id) AS num,
			Customers. NAME
		FROM
			Customers
		LEFT JOIN Orders ON Orders.customerid = Customers.id
		GROUP BY
			Customers.id
	) AS grt
WHERE
	num = 0;