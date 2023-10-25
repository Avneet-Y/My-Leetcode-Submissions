# Write your MySQL query statement below
Select Visits.customer_id , Count(visit_id) as count_no_trans from Visits
where visit_id NOT IN (Select visit_id from Transactions)
Group by customer_id;