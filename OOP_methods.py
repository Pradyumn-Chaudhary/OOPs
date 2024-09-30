#super method ->super()
class Car:
    def __init__(self,type):
        self.type = type

    @staticmethod
    def start():
        print("Car Start..")
    
    @staticmethod
    def stop():
        print("Car Stop.")

class Toyato_Car(Car):
    def __init__(self,name,type):
        self.name = name
        super().__init__(type)
        super().start()

Car1 = Toyato_Car("Supra","Racing")
print(Car1.name,Car1.type)


class Person:
    name = "Anonymous"

    # def __init__(self,name):
    #     self.name = name              #change object name only......can't change the class name
    #     self.__class__.name = name    #also change the class name and can also be written as Person.name = name

    @classmethod     #decorator
    def changename(cls,name):
        cls.name = name

# # P1 = Person("Shradha")
# # print(P1.name)
# print(Person.name)                    #print(P1.__class__.name)

Person.changename("Shradha")
print(Person.name)



    


