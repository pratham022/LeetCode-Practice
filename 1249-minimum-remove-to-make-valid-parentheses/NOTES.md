Here, we will use a stack for checking the validity of parentheses, and later remove the indexes of invalid parentheses from the string s.
​
- First, iterate the string s and mark the index of those characters which need to be removed to make it parentheses string using a special symbol '#'.
- Here, a stack is used for finding the valid pair of parentheses, and while doing so also mark the indexes of invalid parentheses in s.
- Finally, iterate s again and append non-marked symbol (#) to ans.