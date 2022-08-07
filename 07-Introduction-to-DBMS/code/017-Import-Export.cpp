/**
 *  MCQ - 1
 *  -   Out of the following, what data file can mysql workbench import data from?
 *      1. csv
 *      2. json
 *      3. ORC
 *      4. Protocol
 *      5. Parquet
 *  Options
 *      a.  1,3,5
 *      b.  only 2,4
 *      c.  1,2,3
 *      d.  1,2 
 *  Ans:    d
 *  -   MySQL files can import Data from CSV or JSON files. 
 */

/**
 *  MCQ - 2
 *  -    Choose the correct query for importing data, from the following.
 *  Options
 *      a.  LOAD DATA INFILE 'c:/tmp/football.csv' INTO TABLE Zaltan FIELDS TERMINATED 
 *          BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS; 
 *      b.  LOAD DATA INFILE 'c:/tmp/football.csv' INTO TABLE Zaltan
 *      c.  LOAD DATA INFILE 'c:/tmp/football.csv' INTO Zaltan FIELDS ENCLOSED BY '"' 
 *          LINES TERMINATED BY '\n' IGNORE 1 ROWS;
 *      d.  LOAD INFILE “c:/tmp/football.csv” INTO DATABASE Zaltan AS TABLE his_goals 
 *          FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS;
 *  Ans:    a
 *  -   When importing from a local computer, the client program reads the file on the 
 *      client and sends it to the MySQL server. The file will be uploaded into the 
 *      database server operating system. Query: - LOAD DATA LOCAL INFILE 'c:/tmp/xyz.csv' 
 *      INTO TABLE T_name FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' 
 *      IGNORE 1 ROWS; 
 *  -   In the above Query, FIELDS TERMINATED BY, ENCLOSED BY, LINES TERMINATED BY, 
 *      IGNORE ROWS is a part of the File and Line handling process. FIELDS TERMINATED BY 
 *      is used when the text file we are importing is having values separated by commas. 
 *      “, “.
 *  -   ENCLOSED BY is used when we want to specify that we want to load the files under 
 *      these symbols
 *  -   LINES TERMINATED BY is to terminate the specific line while importing the data.
 *  -   IGNORE ROWS is used to ignore the specific row from a CSV file.
 */

/**
 *  MCQ - 3
 *  -    Before exporting data, we must ensure that:
 *  Options
 *      a.  write access should be provided to the target folder that contains the target 
 *          DATA file.
 *      b.  The target DATA file must not exist.
 *      c.  Both a and b 
 *      d.  None.
 *  Ans:    c
 *  -   To export our data in CSV file we must ensure that
 *      1.  The write access should be provided to the folder containing the target data 
 *          file.
 *      2.  The Target data file must not already exist.
 *      3.  Also, The query should be properly written and the target filename should be 
 *          unique which we are writing in the query.
 */

/**
 *  MCQ - 4
 *  -    Choose the correct query for Exporting data, from the following.
 *  Options
 *      a.  SELECT * FROM UFC WHERE id = 1 INTO OUTFILE 'C:/tmp/conner_vs_khabib2.csv' ;
 *      b.  SELECT * FROM UFC WHERE id = 1 INTO OUTFILE 'C:/tmp/conner_vs_khabib2.csv' 
 *          FIELDS ENCLOSED BY '"' TERMINATED BY ';' ESCAPED BY '"' LINES 
 *          TERMINATED BY '\r\n';
 *      c.  SELECT * FROM UFC WHERE id = 1 INTO OUTFILE 'C:/tmp/conner_vs_khabib2.csv' 
 *          FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS;
 *      d.  SELECT * FROM UFC WHERE id = 1 LOAD DATA OUTFILE 'C:/tmp/conner_vs_khabib2.csv' 
 *          FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS;
 *  Ans:    b
 *  -   To export our data into a CSV file.
 *  -   Query:- SELECT column_name(s) FROM T_name WHERE id = 1 INTO OUTFILE 
 *      'C:/tmp/xyz_exported.csv' FIELDS ENCLOSED BY '"' TERMINATED BY ';' 
 *      ESCAPED BY '"' LINES TERMINATED BY '\r\n';
 *  -   In the above Query, FIELDS ENCLOSED BY, ESCAPES BY, LINES TERMINATED BY, 
 *      TERMINATED BY is a part of the File and Line handling process
 *      1.  FIELDS ENCLOSED BY is used when we have to export the data from the specific 
 *          field
 *      2.  TERMINATED BY is used when we have to terminate the data after export.
 *      3.  LINES TERMINATED BY is to terminate the specific line after exporting the data. 
 */