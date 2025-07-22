t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    c = sorted(a)
    possible = False
    best_k = -1
    best_d = []

    # Check the original array first
    derangement = True
    for bi, ci in zip(a, c):
        if bi == ci:
            derangement = False
            break
    if derangement and n >= 1:
        possible = True
        best_k = n
        best_d = a.copy()
    else:
        # Check all possible subarrays by removing some elements
        # The minimal case is when the array has at least one element not matching in the sorted version
        # So the idea is to find a subset where none of the elements match the sorted subset's elements
        # The optimal way is to find if there exists any subset where the minimal element is not in the first position, etc.
        # But with n up to 100, we can try removing elements one by one and check

        # Try to remove elements that cause conflicts in the original array
        # Alternatively, the minimal solution is to have all elements not equal to their sorted counterparts
        # So we can try to find the smallest k where this is possible
        found = False
        for k in range(n, 0, -1):
            # Generate all possible subarrays of size k (but since order is preserved, it's combinations)
            # But with n=100, this is not feasible (100 choose 50 is huge)
            # So we need a smarter approach
            # The only way is to check if there's a subarray where the sorted version doesn't match any position
            # So the minimal requirement is that the original array has at least one element not in its sorted position
            # But perhaps the only way is to have the entire array as a derangement or a subset where all elements are not in their sorted positions
            # So for the original array, if there's at least one element not in its sorted position, then perhaps we can find a subset
            # But this is not straightforward
            # Hence, for small n, we can try all possible subarrays (but it's O(2^n))
            # So for n=100, it's impossible
            # Hence, we need a different approach

            # Another observation: if all elements are the same, then any non-empty subarray will have all elements same, and sorted array is same as original. So it's impossible.
            if all(x == a[0] for x in a):
                break
            # Else, there exists at least two different elements in the array
            # The solution is to take the entire array except possibly one element that causes a conflict
            # Or take the entire array if possible
            pass

        # Alternative approach: the only way a derangement is possible is if the array has at least one element that is not in its original position in the sorted array
        # So if the array is not already sorted, then there exists some derangement
        # But the sample input shows that [2,2,3] is not a derangement (sorted is [2,2,3], so positions 2 and 3 match)
        # So the condition is more strict: after sorting, no element in the original array matches the sorted array's element at any position

        # So the solution is to find any subarray (with order preserved) where none of the elements match the sorted subarray's elements
        # So for the sample input 2: [4,5,5,2,4], sorted is [2,4,4,5,5]. Comparing:
        # Original: 4 5 5 2 4
        # Sorted:  2 4 4 5 5
        # Positions: 1:4!=2, 2:5!=4, 3:5!=4, 4:2!=5,5:4!=5 → all different, so it's a derangement
        # So the answer is YES, and the original array is acceptable

        # So the first step is to check if the original array is a derangement
        # If not, then we need to see if removing some elements can make it a derangement
        # So for the array a, we can try to find a subset of size k (1 <=k <=n) where the property holds

        # Now, let's try to find such a subset by checking possible candidates
        # Since the problem requires any possible solution, we can try to find the minimal changes

        # Let's try to find a subarray where the sorted version has no elements in the same position
        # We can try for all possible k from n down to 1
        max_possible_k = -1
        answer_d = []
        for k in range(n, 0, -1):
            # Generate all possible subarrays of size k (order preserved)
            # We can use combinations of indices, but for n=100, it's computationally expensive
            # But since the problem allows any valid solution, maybe we can find one greedily
            # So perhaps the first such subarray found can be returned
            # So for example, we can try to exclude elements that are in their correct positions in the sorted array
            pass

        # Alternative idea: the answer is YES if the array contains at least one element that is not the smallest element
        # But the first sample input has elements [2,2,3], which includes 3 (not smallest), but the entire array's sorted version is [2,2,3], which has the third element matching. So the entire array is not a derangement. But if we remove one 2, the array becomes [2,3], sorted is [2,3], which has 2 in the first position matching. So no derangement possible. Hence, the answer is NO.

        # So perhaps the only way is to find if there's any subset of the array where, when sorted, no element matches the original's elements
        # This seems hard to check without brute force for small n

        # Given the constraints (t=100, n=100), we can afford an O(n^2) solution per test case
        # So for each test case, we can try all possible subarrays by excluding some elements and checking the condition

        # So for the current array a, we can try different deletions
        # Let's try to find any subarray (order preserved) that meets the condition
        found_solution = False
        # We'll try all possible subarrays, starting from the largest possible
        for mask in range((1 << n) - 1, 0, -1):
            d = []
            for i in range(n):
                if mask & (1 << i):
                    d.append(a[i])
            k = len(d)
            if k == 0:
                continue
            c_d = sorted(d)
            valid = True
            for i in range(k):
                if d[i] == c_d[i]:
                    valid = False
                    break
            if valid:
                found_solution = True
                best_k = k
                best_d = d
                break
        if found_solution:
            possible = True

    if possible:
        print("YES")
        print(best_k)
        print(' '.join(map(str, best_d)))
    else:
        print("NO")
