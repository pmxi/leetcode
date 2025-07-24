# Key observation: we can solve this by replacing the right
# contiguous sequence of 9's with 0's and incrementing the next
# num.


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        # loop completed without returning means all nines.
        digits.insert(0, 1)
        return digits
