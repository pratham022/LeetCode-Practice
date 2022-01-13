### Initial Thinking
- Can we apply something similar to merging intervals here?
- But while dry running this, we found that it would not work
​
### Approach
- Sort the intervals according to start position
- Now observe: If the start of current inerval lies within previous balloon's end, then there is no need to increment arrow count
- This is because the current balloon can be bursted with the previous one.
```
if(interval[i][0] > prevEnd) {
prevEnd = interval[i][1];
count++;
}
else {
prevEnd = min(prevEnd, interval[i][1])
}
```