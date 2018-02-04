idea 1: a prime is non divisible by all primes smaller than it. actually, smaller than ceil(n/2). so loop all numbers before n, and check whether divisible by primes smaller than ceil(n/2). O(n^2) time, O(n) space
   
idea 2: initialize first few primes (known). reverse idea 1, if i is a prime, i * 2, i * 3, ..., i * m are not primes. O(n) space

idea 3: improvement on idea 2. when i is a prime, i * 2, i * 3, i * 5, ... i * (i - 1) are not prime, but they have been updated when we are looping at 2, 3, 5,..., i - 1, i.e. we can start updating at i * i, i * (i + 1), ... that are not primes. 