Maintain a map<int, int>. key is each element in list, value is the index of each element in list

Loop through the list. 
If the element is already in map's keys, ignore it.
If (target - element) is in map's keys, report (target - element's index, current index). terminate program
Otherwise, add the current element to map.

complexity: O(n)

Perforamce:
C++: beat 100% of submissions