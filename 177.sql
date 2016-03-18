CREATE FUNCTION getNthHighestSalary (N INT) RETURNS INT
BEGIN
	DECLARE off bigint;
	SELECT N-1 INTO off;
	RETURN (
		SELECT
			(
				SELECT DISTINCT
					Salary
				FROM
					Employee
				ORDER BY
					Salary DESC
				LIMIT 1 OFFSET off
			) AS NTH
	);


END