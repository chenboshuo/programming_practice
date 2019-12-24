/* Write your T-SQL query statement below */
select FirstName, LastName, City, State
from Address
  right outer join Person on Address.PersonId = Person.PersonId
  -- Runtime: 782 ms, faster than 69.19% of MS SQL Server online submissions for Combine Two Tables.
  -- Memory Usage: 0B, less than 100.00% of MS SQL Server online submissions for Combine Two Tables.
