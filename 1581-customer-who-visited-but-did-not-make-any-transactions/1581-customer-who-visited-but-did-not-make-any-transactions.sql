# Write your MySQL query statement below
select distinct customer_id,COUNT(v.visit_id) as count_no_trans
from Visits as v
LEFT JOIN
Transactions as t
on v.visit_id=t.visit_id
where t.amount IS NULL
group by v.customer_id