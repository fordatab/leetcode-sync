# Write your MySQL query statement below
with

-- We need just one CTE to determine the initial "User Type."
users as (
  -- DISTINCT provides us one row per User.
  select distinct
    user_id,
    -- Per User, grab the first "session_type",
    -- ordering sessions by the "session_start" column.
    first_value(session_type) over (partition by user_id order by session_start) as user_type_initial
  from
    sessions
)

select
  user_id,
  count(session_id) as sessions_count
-- Join Users and Sessions.
from
  users
inner join
  sessions
  using(user_id)
-- Only grab "Initially Viewers" with at least one subsequent Streaming session.
where
  user_type_initial = 'Viewer'
  and session_type = 'Streamer'
group by
  user_id
order by
  sessions_count desc,
  user_id desc
;