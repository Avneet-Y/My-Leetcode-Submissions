# Write your MySQL query statement below
Select customer_id, COUNT(visit_id) as count_no_trans 
from Visits
Where visit_id NOT IN (Select visit_id From Transactions)
Group By customer_id