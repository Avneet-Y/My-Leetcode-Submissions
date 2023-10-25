# Write your MySQL query statement below
Select Employee.name, Bonus.bonus from Employee
Left Join Bonus
On Employee.empId = Bonus.empId
where bonus < 1000 Or bonus Is NULL;