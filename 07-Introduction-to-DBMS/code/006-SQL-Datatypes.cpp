/**
 *  MCQ-1
 *  -   Data Type for strings can be stored as:
 *  Options
 *      a.  Fixed length
 *      b.  Variable length
 *      c.  Both A and B 
 *      d.  None of the above
 *  Ans:    d
 *  -   Data Type Char for fixed length and Varchar for variable length can be used 
 *      for strings.
 */

/**
 *  MCQ-2
 *  -   To store the City for the students in the table ‘Student_details’ we should:
 *  Options
 *      a.  Declare City as Char(5)
 *      b.  Declare City as BIGINT
 *      c.  Declare City as Varchar 
 *      d.  All of the above
 *  Ans:    c
 *  -   Since, we do not know the length of City names which are to be stored in the table, 
 *      hence we cannot fix it. Also, City cannot be in integers, therefore we should use 
 *      Varchar.
 */

/**
 *  MCQ-3
 *  -   Which of the following is true:
 *  Options
 *      a.  Boolean or Bool data type is inbuilt in MySQL
 *      b.  Bool data type can be implemented using TINYINT data type 
 *      c.  Bool data type cannot be implemented in MySQL
 *  Ans:    b
 *  -   Bool data type is not provided as in built datatype in MySQL but can be 
 *      implemented using the TINYINT.
 */

/**
 *  MCQ-4
 *  -   How will DECIMAL (7,2) be stored in MySQL?
 *  Options
 *      a.  A number having minImum 2 digit and maximum 7 digits
 *      b.  Total of 9 digits where 7 digits are significant digits/value and 2 digits 
 *          after decimal 
 *      c.  Total of 7 digits, having 2 digits after decimal
 *      d.  None of the above
 *  Ans:    For DECIMAL(7,2), the significant digits would be 7, then the decimal point, 
 *      after which we can specify 2 digits. So, the total digits that can be specified 
 *      are 7+2= 9. Eg: we can store 2364571.75.
 */

/**
 *  MCQ-5
 *  -   Which of the following is true:
 *  Options
 *      a.  By default INT stores signed value
 *      b.  Unsigned INT can store only positive values or 0
 *      c.  Signed INT can be used to store the temperature of a city
 *      d.  All of the above 
 *  Ans:    INT data type is used to store the integer values in SQL. It consists of two 
 *      types i.e., signed INT and unsigned INT. The signed range is from -2147483648 to 
 *      2147483647. Signed INT is used to store values that can be negative or positive 
 *      for example Temperature, Velocity, etc. The unsigned range is from 0 to 4294967295. 
 *      It stores only positive values. By default, the INT data type stores values as 
 *      signed INT. 
 */

/**
 *  MCQ-6
 *  -   Which of the following data type stores the value in format “0000-00-00”
 *  Options
 *      a.  Time
 *      b.  Date 
 *      c.  Datetime
 *      d.  Timestamp
 *  Ans:    b
 *  -   The DATE data type is stored in the format: YYYY-MM-DD. The supported range is 
 *      from '1000-01-01' to '9999-12-31'.
 */

/**
 *  MCQ-7
 *  -   Timestamp data type provides both the date and the time value.
 *  Options
 *      a.  True 
 *      b.  False
 *  Ans:    a
 *  -   TIMESTAMP values include the date plus the time .. The Format is: YYYY-MM-DD 
 *      hh:mm:ss. The supported range is from '1970-01-01 00:00:01' UTC to 
 *      '2038-01-09 03:14:07' UTC.
 */