# Write your MySQL query statement below
select a1.machine_id,
round(AVG(a1.timestamp-a2.timestamp),3) as processing_time
from Activity as a1
INNER JOIN
Activity as a2
ON a1.machine_id=a2.machine_id
AND a1.process_id=a2.process_id
AND a1.activity_type='end'
AND a2.activity_type='start'
GROUP BY a1.machine_id