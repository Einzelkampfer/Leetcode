# Write your MySQL query statement below
SELECT e1.Name FROM Employee as e1, Employee as e2 WHERE e1.ManagerId = e2.id and e1.Salary > e2.Salary;