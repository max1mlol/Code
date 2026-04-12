class Circle:
    def __init__(self, radius):
        """Initializes self with radius"""
        # your code here
        self.radius = radius

    def get_radius(self):
        """Returns the radius of self"""
        # your code here
        return self.radius

    def set_radius(self, radius):
        """radius is a number
        Changes the radius of self to radius"""
        # your code here
        self.radius = radius

    def get_area(self):
        """Returns the area of self using pi = 3.14"""
        # your code here
        return 3.14 * self.radius ** 2

    def equal(self, c):
        """c is a Circle object
        Returns True if self and c have the same radius value"""
        # your code here
        return self.radius == c.radius

    def bigger(self, c):
        """c is a Circle object
        Returns self or c, the Circle object with the bigger radius"""
        # your code here
        if self.radius >= c.radius:
            return self
        else:
            return c
    def __add__(self, c):
        """c is a Circle object
        Returns a new Circle object whose radius is
        the sum of self and c's radius"""
        # your code here
        return Circle(self.radius + c.radius)

    def __str__(self):
        """A Circle's string representation is the radius"""
        # your code here
        return str(self.radius)


c1 = Circle(4)
print("r =", c1.get_radius())
c1.set_radius(5)
print("area =", c1.get_area())

c2 = Circle(3)
c3 = Circle(5)
print(c1, c2, c3)

print("c1.equal(c2) ?", c1.equal(c2))
print("c1.equal(c3) ?", c1.equal(c3))

print("c1.bigger(c3) ?", c1.bigger(c3))
print("c2.bigger(c1) ?", c2.bigger(c1))

print("c1 == c2 ?", c1 == c2)
print("c1 == c3 ?", c1 == c3)

print(c1 + c2)
