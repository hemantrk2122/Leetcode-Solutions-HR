class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        dq = deque()
        mp = {}
        for n in nums:
            mp[n] = mp.get(n, 0) + 1
            
        for i, n in enumerate(nums):
            if i + 1 not in mp:
                # missing element
                dq.append(i+1)
            elif mp[n] == 2:
                dq.appendleft(n)
                mp[n] = 1  # update the frequency of n or next time code will again count it as 2 and add in the list
                
        return dq
        