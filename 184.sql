# Write your MySQL query statement below
SELECT
	Department. NAME AS Department,
	Employee. NAME AS Employee,
	Employee.Salary AS Salary
FROM
	Employee,
	Department,
	(
		SELECT
			max(Employee.Salary) AS Salary,
			Employee.DepartmentId AS Department
		FROM
			Employee
		JOIN Department ON Employee.DepartmentId = Department.Id
		GROUP BY
			Department.Id
	) AS Maxval
WHERE
	Employee.DepartmentId = Department.Id
AND Employee.DepartmentId = Maxval.Department
AND Employee.Salary = Maxval.Salary;