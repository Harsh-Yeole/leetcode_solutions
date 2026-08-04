# Write your MySQL query statement below
select name,bonus
from Employee as e
left join 
Bonus as b
on e.empid=b.empid
WHERE b.bonus is null
or b.bonus<1000