class Container(object):
    """
    A container object is a list and can store elements of any type
    """

    def __init__(self):
        """
        Initializes an empty list
        """
        self.myList = []

    def size(self):
        """
        Returns the length of the container list
        """
        # Your code here
        return len(self.myList)

    def add(self, elem):
        """
        Adds the elem to one end of the container list, keeping the end
        you add to consistent. Does not return anything
        """
        # Your code here
        self.myList.append(elem)

    def __str__(self):
        """A Container's string representation is the elements in myList"""
        # your code here
        return str(self.myList)


class Stack(Container):
    """
    A subclass of Container. Has an additional method to remove elements.
    """

    def remove(self):
        """
        The newest element in the container list is removed
        Returns the element removed or None if the queue contains no elements
        """
        # Your code here
        if len(self.myList) == 0:
            return None
        return self.myList.pop()


s = Stack()
print(s)

print(s.size())
s.add(3)
s.add(5)
s.add(7)
s.add(11)

print(s)
print(s.size())

print(s.remove())
print(s.remove())
print(s)
print(s.size())
