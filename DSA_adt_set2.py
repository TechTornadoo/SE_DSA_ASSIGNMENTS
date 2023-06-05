#DSA_ASSIGNMENT2
class Set:
    def init(self):
        self.elements = set()

    def add(self, element):
        self.elements.add(element)

    def remove(self, element):
        self.elements.discard(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def display(self):
        for element in self.elements:
            print(element, end=' ')
        print()

    def is_subset(self, other_set):
        for element in self.elements:
            if element not in other_set.elements:
                return False
        return True


set1 = Set()
set2 = Set()

n = int(input("Enter the number of elements for set 1: "))
for _ in range(n):
    element = int(input("Enter an element: "))
    set1.add(element)

m = int(input("Enter the number of elements for set 2: "))
for _ in range(m):
    element = int(input("Enter an element: "))
    set2.add(element)

# Intersection
intersection_set = Set()
for element in set1.iterator():
    if set2.contains(element):
        intersection_set.add(element)

# Union
union_set = Set()
for element in set1.iterator():
    union_set.add(element)
for element in set2.iterator():
    union_set.add(element)

# Difference
difference_set = Set()
for element in set1.iterator():
    if not set2.contains(element):
        difference_set.add(element)

# Subset
is_subset = set1.is_subset(set2)

print("Intersection Set:")
intersection_set.display()

print("Union Set:")
union_set.display()

print("Difference Set:")
difference_set.display()

print("Set 1 is a subset of Set 2:", is_subset)