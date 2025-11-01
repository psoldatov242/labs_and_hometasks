SELECT SUM(sales.quantity_sold * products.price)
FROM sales 
JOIN products ON sales.product_id = products.id
WHERE sales.sale_date BETWEEN '2024-01-15' AND '2024-01-18'