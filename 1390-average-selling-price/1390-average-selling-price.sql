# Write your MySQL query statement below
select p.product_id , IFNULL(ROUND(SUM(u.units*p.price)/SUM(u.units),2),0)
 as average_price from prices p left join unitsSold u 
on p.product_id = u.product_id
And u.purchase_date between p.start_date AND p.end_date 
group by p.product_id;
