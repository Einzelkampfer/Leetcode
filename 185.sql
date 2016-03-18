# Write your MySQL query statement below
SELECT
	Department. NAME AS Department,
	Employee. NAME AS Employee,
	Employee.Salary AS Salary
FROM
	(
		SELECT
			Salary,
			Department
		FROM
			(
				SELECT DISTINCT
					tempEm.Salary AS Salary,
					tempEm.DepartmentId AS Department,
					@rn := CASE
				WHEN @var_id = tempEm.DepartmentId THEN
					@rn + 1
				ELSE
					1
				END AS rn,
				@var_id := tempEm.DepartmentId
			FROM
				(
					SELECT
						@var_id := NULL,
						@rn := NULL
				) vars,
				(
					SELECT
						*
					FROM
						Employee
					GROUP BY
						DepartmentId,
						Salary
					ORDER BY
						DepartmentId,
						Salary DESC
				) AS tempEm
			JOIN Department ON tempEm.DepartmentId = Department.Id
			GROUP BY
				Salary,
				Department
			) AS subTable
		WHERE
			subTable.rn <= 3
	) AS topThree,
	Department,
	Employee
WHERE
	Department.id = topThree.Department
AND Employee.Salary = topThree.Salary
AND Employee.DepartmentId = Department.Id
ORDER BY
	Department.Id,
	Employee.Salary DESC;