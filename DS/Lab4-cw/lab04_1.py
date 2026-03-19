import math
def count_sqrts(nums_list):
    """
    nums_list: a list
    Assumes that nums_list only contains positive numbers and that there are no duplicates.
    Returns how many elements in nums_list are exact squares of elements in the same list, including itself.
    """
    # Your code here
    count = 0
    for number in nums_list:
        root = int(math.sqrt(number))
        if root ** 2 == number and root in nums_list:
            count += 1
    return count
# Examples:
print(count_sqrts([3, 4, 2, 1, 9, 25]))  # prints 3
