# Write your MySQL query statement below
select e1.name from employee e1 
Join (
    select managerId ,count(*) from employee
    group by managerId having count(*)>=5
) e2 on  e1.id = e2.managerId