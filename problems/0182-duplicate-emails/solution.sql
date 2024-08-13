# Please upvote, if you like my solution
# 1
SELECT email from Person
group by email
having count(email) > 1;

