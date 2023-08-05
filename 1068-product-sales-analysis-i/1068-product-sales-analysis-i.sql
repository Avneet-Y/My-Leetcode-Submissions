# Write your MySQL query statement below
Select P.product_name , S.year , S.price 
from Sales S
Left Join Product P
On S.product_id = P.product_id 