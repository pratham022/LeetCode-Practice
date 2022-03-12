- Basically, for each element `nums[i]` in the array that we are about to insert, we first check whether the leftmost index in the sliding window is out of bound. If so, we remove it by `pop_front()` in constant time.
​
- Then we continuously remove the rightmost indices if their corresponding elements are less than nums[i] (the element we are about to insert). The idea is that the elements that are less than the element we'll insert won't have any contributions to the maximum element of the sliding window. So it is safe to remove them.
​
- After removal pollLast() and insertion offerLast(i) (the element nums[i]), we can say that the leftmost element in the window is maximum. Think about it why. Notice that the maximum element could be the one we just insert.