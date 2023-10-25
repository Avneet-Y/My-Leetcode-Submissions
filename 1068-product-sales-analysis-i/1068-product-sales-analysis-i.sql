# Write your MySQL query statement below
Select Product.product_name, Sales.year, Sales.price from Sales
Join Product ON Product.product_id = Sales.product_id;