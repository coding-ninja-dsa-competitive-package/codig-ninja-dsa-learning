/**
 *  Information about the tables:
 *  -   Given below is a database of a newly established e-commerce website. The database 
 *      contains multiple tables i.e. products, orders, and transactions. The information 
 *      about required tables is given below
 *      
 *      Table transactions:
 *          transaction_id(VARCHAR(20) PRIMARY KEY), transaction_status (VARCHAR(25))
 * 
 *      Table product:
 *          item_id(INT PRIMARY KEY), product_id (INT), pname (VARCHAR(225)), inStock (CHAR),
 *          price (DOUBLE), arrival_days (INT), seller (VARCHAR(225)), youSave (DOUBLE)
 * 
 *      Table orders:
 *          order_id(INT PRIMARY KEY), product_id (INT), customer_id (INT), payment_date 
 *          (DATE), est_delivery_date (DATE), transaction_id (INT)
 *      
 *      Table customer:
 *          customer_id(Primary Key) VARCHAR(20), customer_name (VARCHAR(225)), phone_no                      
 *          (INT), city (VARCHAR(200), pin_code (INT)
 */


/**
 *  Query - 1
 *  -   Problem Statement:
 *      -   Write an SQL query to add a new column “transaction_type”, for the 
 *          transactions table.
 *      Note: Datatype for transaction_type is VARCHAR(225).
 *      Note: Describe the complete table afterwards.
 *              DESC table_name
 *  Ans:    ALTER TABLE transactions ADD COLUMN transaction_type VARCHAR(225);
 *          DESC transactions;
 */

/**
 *  Query - 2
 *  -   Problem Statement:
 *      -   Create the customers table for this database.
 *  Ans:    CREATE TABLE customers (
 *              customer_id VARCHAR(20) PRIMARY KEY,
 *              customer_name VARCHAR(225),
 *              phone_no INT,
 *              city VARCHAR(200),
 *              pin_code INT
 *          );
 *          DESC customers;
 */

/**
 *  Query - 3
 *  -   Problem Statement:
 *      -   Write an SQL query to print all the details of the products whose seller’s 
 *          name ends with ‘n’ and contains only seven alphabets.
 *      -   Output table Structure
 *              item_id, product_id, p_name, inStock, price, arrival_days, seller, youSave
 *  Ans:    SELECT * FROM product WHERE seller LIKE '%n' AND LENGTH(seller) = 7;
 */


/**
 *  Query - 4
 *  -   Problem Statement:
 *      -   How many orders are currently being delivered in December 2021?
 *      -   Output Table Structure
 *              orders_delivered
 *      Note: name total number of orders delivered in December, 2021 as orders_delivered
 *  Ans:    SELECT COUNT(*) FROM orders WHERE est_delivery_date LIKE '2021-12-%';
 */

/**
 *  Query - 5
 *  -   Problem Statement:v
 *      -   Write an SQL query to show only odd rows from the product table.
 *      -   Output table Structure
 *              item_id, product_id, p_name, inStock, price, arrival_days, seller, youSave
 *  Ans:    SELECT * FROM product WHERE item_id % 2 = 1;
 */

/**
 *  Query - 6
 *  -   Problem Statement:
 *      -   Make a Clone of the product table(with complete data) and name it to be 
 *          giftList and print the table schema in ascending order of column name as well.
 *      Note : Command to print table schema:-
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'table_name';
 *  Ans:    CREATE TABLE giftList LIKE product;
 *          INSERT INTO giftList SELECT * FROM product;
 *      
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'giftList'
 *          ORDER BY column_name ASC;
 */

/**
 *  Query - 7
 *  -   Problem Statement:
 *      -   Make a Clone of the product table(without data) and name it to be cloneListPro 
 *          and print the table schema of the table cloneListPro.
 *      Note : Command to print table schema:-
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'table_name';
 *  Ans:    CREATE TABLE cloneListPro LIKE product;
 *      
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'cloneListPro';
 */

/**
 *  Query - 8
 *  -   Problem Statement:
 *      -   Print out the 6 records from the product table after the 3rd row.
 *      -   Output table Structure
 *              item_id, product_id, p_name, inStock, price, arrival_days, seller, youSave
 *  Ans:    SELECT * FROM product LIMIT 3, 6;
 */

/**
 *  Query - 9
 *  -   Problem Statement:
 *      -   Write a Mysql query to fetch the second most expensive item cost/price.
 *      -   Output Table Structure
 *              maximum_price
 *  Ans:    SELECT MAX(price) FROM product WHERE price < (SELECT MAX(price) FROM product);
 */

/**
 *  Query - 10
 *  -   Problem Statement:
 *      -   Fetch out all the product details of the 7th most expensive product.
 *  Ans:    SELECT * FROM product ORDER BY price DESC LIMIT 6, 1;
 */

/**
 *  Query - 11
 *  -   Problem Statement:
 *      -   Fetch the first 33% records from a product table.
 *  Ans:    SELECT * FROM product LIMIT 0, 8;
 */

/**
 *  Query - 12
 *  -   For each seller, find the number of products he/she is selling.
 *  Ans:    SELECT seller, COUNT(*) FROM product GROUP BY seller 
 */

/**
 *  Query - 13
 *  -   Problem Statement:
 *      -   List out the five cheapest prices from the product table. (only need to list 
 *          the prices)
 *  Ans:    SELECT DISTINCT price FROM product ORDER BY price ASC LIMIT 5;
 */


/**
 *  Query - 14
 *  -   Problem Statement:
 *      -   List out the five most expensive prices from the product table. (only need to 
 *          list the prices)
 *  Ans:    SELECT DISTINCT price FROM product ORDER BY price ASC LIMIT 5;
 */

/**
 *  Query - 15
 *  -   Problem Statement:
 *      -   What’s the percentage of the products in stock with savings greater than 4000.
 *  Ans:    SELECT (SELECT COUNT(*) FROM product WHERE youSave > 4000 AND 
 *          INSTOCK = 'Y') * 100 / (SELECT COUNT(*) FROM product WHERE INSTOCK = 'Y') 
 *          AS percentage 
 */

/**
 *  Query - 16
 *  -   Problem Statement:
 *      -   Write a MySQL query to display the last 4 records from the product table.
 *  Ans:    SELECT * FROM product LIMIT 20, 4
 */


/**
 *  Query - 17
 *  -   Problem Statement:
 *      -   Find the product id and seller name along with count of duplicate entries from 
 *          the tables given below considering there is no primary key (item_id).
 *  Ans:    SELECT product_id, seller, COUNT(*) FROM product GROUP BY product_id, seller 
 *          HAVING COUNT(*) > 1;
 */

/**
 *  Query - 18
 *  -   Problem Statement:
 *      -   List down the count of all the similar products available across all its sellers.
 *  Ans:    SELECT DISTINCT p.product_id, p.p_name, p.inStock, p.seller, q.countSame
 *          FROM product p
 *          INNER JOIN (SELECT product_id, p_name, inStock,
 *          COUNT(*) as countSame FROM product GROUP BY product_id, p_name, inStock 
 *          HAVING COUNT(*) > 1) q ON p.product_id = q.product_id AND p.p_name = q.p_name 
 *          AND p.inStock = q.inStock ORDER BY p.product_id, p.p_name, p.inStock, p.seller;
 */

/**
 *  Query - 19
 *  -   Problem Statement:
 *      -   What is an Average total saving amount on the products sold by Maple store or 
 *          Kukreja Telecom Store?
 *  Ans:    SELECT AVG(TOTAL) FROM (SELECT product_id, SUM(youSave) AS TOTAL    
 *          FROM product GROUP BY product_id) AS TOTALS WHERE product_id IN 
 *          (SELECT product_id FROM product WHERE seller = 'Maple store' OR 
 *              seller = 'Kukreja Telecom Store');
 */

/**
 *  Query - 20
 *  -   Problem Statement:
 *      -   For each product, list down the min price of the product and the average 
 *          percentage of savings available across all the sellers who sell more than one 
 *          product.
 *  Ans:    SELECT product_id, p_name, MIN(price), (AVG(youSave)*100)/SUM(youSave) AS avgP 
 *          FROM product GROUP BY product_id, p_name HAVING COUNT(*)>1;
 */

/**
 *  Query - 21
 *  -   Problem Statement:
 *      -   Enlist all the customers_id and their name for all the products names?
 *      -   Output : The result set should have the product name, customer id and customer 
 *              name.
 *  Ans:    SELECT DISTINCT product.p_name, customer.customer_id, customer.customer_name 
 *          FROM product INNER JOIN orders ON product.product_id = orders.product_id 
 *          INNER JOIN customer ON orders.customer_id = customer.customer_id;
 */

/**
 *  Query - 22
 *  -   Problem Statement:
 *      -   Get the product_ID and the total sale of each product ordered?
 *      -   Output: The result set should have product_id , and count of products as attributes.
 *  Ans:    SELECT product_id, COUNT(product_id)  FROM orders GROUP BY product_id;
 */

/**
 *  Query - 23
 *  -   Problem Statement:
 *      -   Enlist the transaction_status for all products ordered?
 *  Ans:    SELECT transactions.transaction_id FROM orders 
 *          LEFT JOIN transactions ON orders.transaction_id = transactions.transaction_id;
 */

/**
 *  Query - 24
 *  -   Problem Statement:
 *      -   List all the product names with their respective payment date and delivery 
 *          date and sort the output table w.r.t to delivery date?
 *      -   Output
 *          The result set should have the product name, payment date and delivery date 
 *          as columns.
 *  Ans:    SELECT distinct product.p_name, orders.payment_date, orders.est_delivery_date 
 *          FROM product INNER JOIN orders ON product.product_id = orders.product_id 
 *          order by est_delivery_date;
 */

/**
 *  Query - 25
 *  -   Problem Statement:
 *      -   List all the not completed transaction_status for all order_id?
 *      -   Output
 *          The result set should have the Id, product's Id, customer's Id and the 
 *          transaction Id's.
 *  Ans:    SELECT o.order_id,o.product_id,o.customer_id,o.transaction_id FROM orders o 
 *          LEFT JOIN transactions t ON o.transaction_id=t.transaction_id 
 *          WHERE t.transaction_status='not completed';
 */

/**
 *  Query - 26
 *  -   Problem Statement:
 *      -   List down the product names along with the details like the time the payment 
 *          for the order was made and delivery date along with the transaction status of 
 *          that product by the customer and sort it according to their respective payment 
 *          date.
 *  Ans:    SELECT distinct product.p_name, orders.payment_date, orders.est_delivery_date , 
 *              transactions.transaction_status
 *          FROM product INNER JOIN orders ON product.product_id = orders.product_id 
 *          INNER JOIN transactions ON orders.transaction_id = transactions.transaction_id
 *          order by est_delivery_date;
 */

/**
 *  Query - 27
 *  -   Problem Statement:
 *      -   Enlist all orders for a customer with a “d” in their name?
 *      -   Output : The result set should have the customer's name and order's id.
 *  Ans:    SELECT customer.customer_name, orders.order_id FROM customer
 *          INNER JOIN orders ON orders.customer_id = customer.customer_id
 *          AND customer.customer_name LIKE '%d%';
 */

/**
 *  Query - 28
 *  -   Problem Statement:
 *      -   List total payments received from all customers of the e-commerce website?
 *      -   Output : The result set should have the Customer's Id and the total payment 
 *          they have made for all the orders.
 *  Ans:    SELECT customer.customer_id,SUM(orders.checkout_price) AS totalpayment 
 *          FROM customer 
 *          LEFT JOIN orders ON customer.customer_id=orders.customer_id 
 *          GROUP BY customer_id;
 */