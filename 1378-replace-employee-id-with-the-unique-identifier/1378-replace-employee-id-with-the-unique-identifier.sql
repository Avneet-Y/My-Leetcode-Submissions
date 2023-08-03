# Write your MySQL query statement below
Select Employees.name, EmployeeUNI.unique_id FROM Employees
Left Join EmployeeUNI
On Employees.id = EmployeeUNI.id
