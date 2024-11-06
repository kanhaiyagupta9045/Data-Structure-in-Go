# Write your MySQL query statement below
-- group by id count(email)

SELECT email as Email From Person Group BY email HAVING Count(email)>1;