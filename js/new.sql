
-- INNER JOIN
SELECT column_list
FROM table1
INNER JOIN table2
  ON table1.common_column = table2.common_column;

-- LEFT JOIN / LEFT OUTER JOIN
SELECT column_list
FROM table1
LEFT JOIN table2
  ON table1.common_column = table2.common_column;

-- RIGHT JOIN / RIGHT OUTER JOIN
SELECT column_list
FROM table1
RIGHT JOIN table2
  ON table1.common_column = table2.common_column;

-- FULL JOIN / FULL OUTER JOIN
SELECT column_list
FROM table1
FULL JOIN table2
  ON table1.common_column = table2.common_column;

-- CROSS JOIN
SELECT column_list
FROM table1
CROSS JOIN table2;

-- SELF JOIN
SELECT a.column_list, b.column_list
FROM table_name a
JOIN table_name b
  ON a.common_column = b.other_column;

-- UNION
SELECT column_list
FROM table1
UNION
SELECT column_list
FROM table2;

-- UNION ALL
SELECT column_list
FROM table1
UNION ALL
SELECT column_list
FROM table2;

-- INTERSECT
SELECT column_list
FROM table1
INTERSECT
SELECT column_list
FROM table2;

-- EXCEPT / MINUS
SELECT column_list
FROM table1
EXCEPT
SELECT column_list
FROM table2;
