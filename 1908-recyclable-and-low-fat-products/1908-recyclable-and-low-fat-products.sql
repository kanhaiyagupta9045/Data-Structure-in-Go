# Write your MySQL query statement below
SELECT product_id from Products where FIND_IN_SET('Y',low_fats) and FIND_IN_SET('Y',recyclable);
