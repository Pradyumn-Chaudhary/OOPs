class Circle:
    def __init__(self,radius):
        self.radius = radius

    def Area(self):
        return (22/7)*self.radius**2

    def Perimeter(self):
        return self.radius*2*(22/7)


c1 = Circle(21)
print(c1.Area())
print(c1.Perimeter())


class Employee:
    def __init__(self,role,salary,department):
        self.role = role
        self.salary = salary
        self.department = department

    def show_detail(self):
        print("Role :",self.role,"\nSalary : Rs.",self.salary,"\nDepartmennt :",self.department)

em1 = Employee("SWE","72,00,000 LPA","Business Administartion")
em1.show_detail()

class Engineer(Employee):
    def __init__(self,name,age):
        self.name = name
        self.age = age

        super().__init__("Engineer","7,20,00,000 LPA","Business Administartion")

em2 = Engineer("Alex Farday",21)

print("Name :",em2.name)
print("Age :",em2.age)
em2.show_detail()


class Order:
    def __init__(self,item,price):
        self.item = item 
        self.price = price
    
    def __gt__(self,item):
        return self.price > item.price

order1 = Order("Pizza",160)
order2 = Order("Cold Coffee",140)

print(order1>order2)
print(order2>order1)