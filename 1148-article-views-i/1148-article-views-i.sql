# Write your MySQL query statement below
select author_id as id
from Views
where author_id=viewer_id
GROUP BY author_id
ORDER BY author_id asc