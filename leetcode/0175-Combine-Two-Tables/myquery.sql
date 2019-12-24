/* Write your T-SQL query statement below */
select FirstName, LastName, City, State
from Address
  right join Person on Address.PersonId = Person.PersonId

  -- Runtime: 935 ms, faster than 50.09% of MS SQL Server online submissions for Combine Two Tables.
  -- Memory Usage: 0B, less than 100.00% of MS SQL Server online submissions for Combine Two Tables.
