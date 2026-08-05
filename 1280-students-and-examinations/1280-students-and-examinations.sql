# Write your MySQL query statement below
select s.student_id as student_id,s.student_name as student_name,sub.subject_name as subject_name,
COUNT(e.student_id) as attended_exams
from Students as s
cross join subjects as sub
left join examinations as e
on s.student_id=e.student_id
and sub.subject_name=e.subject_name
GROUP BY s.student_id,s.student_name,sub.subject_name
ORDER BY s.student_id,sub.subject_name
