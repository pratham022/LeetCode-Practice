### x^n
- if n if even, x^n = x^(n/2) * x^(n/2)
- else: x^n = x^(n-1) * x^1 = x^(n-1) * x
​
### More optimised approach
- if n if even, x^n = x^(n/2) * x^(n/2) = (x*x)^(n/2)
- else: x^n = x^(n-1) * x^1 = x^(n-1) * x = x^(n/2) * x^(n/2) * x
- because while computing, (n/2) and (n-1)/2 will give the same result
- Thus, x^n = (xx)^(n/2)  x