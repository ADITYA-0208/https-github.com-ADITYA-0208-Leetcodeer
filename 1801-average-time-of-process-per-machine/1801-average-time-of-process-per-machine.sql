SELECT 
    a.machine_id,
    ROUND(AVG(a.timestamp - s.timestamp),3) AS processing_time
FROM Activity a
JOIN Activity s 
    ON a.machine_id = s.machine_id 
   AND a.process_id = s.process_id 
   AND s.activity_type = 'start'
   and a.activity_type = 'end'
GROUP BY a.machine_id;
