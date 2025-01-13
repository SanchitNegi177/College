-- 1
create table table_customer (customer_id number primary key,Name varchar2(10) not null,Age number,Address varchar2(10));
INSERT ALL
INTO table_customer  VALUES (1, 'Sanchit', 21, 'Kotdwar')
INTO table_customer  VALUES (2, 'Pokhriyal', 21, 'Kotdwar')
INTO table_customer  VALUES (3, 'Harshit', 25, 'Tanakpur')
INTO table_customer  VALUES (4, 'Tomar', 30, 'Dehradun')
INTO table_customer  VALUES (5, 'Shukla', 22, 'Kanpur')
select * from dual;

create table table_order (customer_id number references table_customer(customer_id) on delete cascade,order_id number ,order_date varchar2(10));
INSERT INTO table_order VALUES (1, 101, '27-11-2024');
INSERT INTO table_order VALUES (2, 102, '30-11-2024');
INSERT INTO table_order VALUES (4, 104, '5-12-2024');



-- 2 Apply the full join and the full outer join to the schema and review the results. 
select * from table_customer c full join table_order o on c.customer_id=o.customer_id;
select * from table_customer c full outer join table_order o on c.customer_id=o.customer_id;

-- 3 Display the name of the city as "destination" for customers who have placed orders. 
select Address as Destination from table_customer c right join table_order o on c.customer_id=o.customer_id ;

--4 Apply the cross join and check the results. 
select * from table_customer cross join table_order;

--5 Display the customer names and order IDs for customers who have placed orders from the same city.
SELECT c.name, o.order_id FROM table_customer c RIGHT JOIN table_order o ON c.customer_id = o.customer_id WHERE c.address IN 
(
    SELECT address
    FROM table_customer
    GROUP BY address
    HAVING COUNT(*) > 1
);

