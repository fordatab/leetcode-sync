# Find Users With Valid E-Mails

**Difficulty:** Easy
**Tags:** sql, regex, pattern-matching, string-validation

## Problem

Given a table of users with their email addresses, identify which users have valid emails according to specific rules. A valid email must have a prefix starting with a letter and containing only letters, digits, underscores, periods, or dashes, followed by the exact domain '@leetcode.com'. Users with emails that violate these constraints (wrong domain, invalid characters, or prefix not starting with a letter) should be excluded.

## Approach

The solution uses a regular expression pattern to filter valid emails directly in the SQL WHERE clause. The regex pattern `^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$` enforces all validation rules: `^` anchors to the start, `[a-zA-Z]` ensures the first character is a letter, `[a-zA-Z0-9_.-]*` allows zero or more valid prefix characters (letters, digits, underscore, period, dash), `@leetcode[.]com` matches the exact required domain (with the period escaped using brackets), and `$` anchors to the end. The REGEXP operator in MySQL evaluates this pattern against each email, returning only rows where the mail column matches the complete pattern.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 04:56 UTC
- Runtime: 655 ms
- Memory: 0B
- Language: MySQL
