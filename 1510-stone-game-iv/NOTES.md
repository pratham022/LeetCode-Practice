### Using the given hint:
Use dynamic programming to keep track of winning and losing states. Given some number of stones, Alice can win if she can force Bob onto a losing state.

- So, we start with a DP array of size n
- dp[i] indicates whether the current player can win if the initial number is `i`
- Corner cases: `dp[0] = false` and `dp[1] = true`
- Start from 2 to n
- Now, as each player plays optimally, we have to check if we can go to a losing index from  `i`
- So, start with variable `k` from 1 to sqrt(i)
- Now, if `dp[i - k * k] == false`, this means that we have forced the other player to go on losing index
- So, current player wins! Thus `dp[i] = true` in this case
