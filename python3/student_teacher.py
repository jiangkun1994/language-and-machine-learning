#!/usr/bin/env python3

import sys
from collections import Counter

class Person(object):
    def __init__(self, name):
        self.name = name

    def get_details(self):
        return self.name

    def get_grade(self, grade):
        if  self.name == 'teacher':
            grade_s = Counter(grade).most_common(4)
            #return "{}: {}".format(k, v) for
            #for k, v in grade_s:
                #print("{}: {}".format(k,v), end=', ')
            #print() // can work too
            a = ["{}: {}".format(k,v) for k,v in grade_s]
            print(', '.join(a))
        elif self.name == 'student':
            p = len(grade) - Counter(grade)['D']
            f = Counter(grade)['D']
            print("pass: {}, fail: {}".format(p,f))

class Student(Person):
    def __init__(self, name, branch, year):
        Person.__init__(self, name)
        self.branch = branch
        self.year = year
def get_details(self):
        return "{} studies {} and is in {} year.".format(self.name, self.branch, self.year)

class Teacher(Person):
    def __init__(self, name, papers):
        Person.__init__(self, name)
        self.papers = papers

    def get_details(self):
        return "{} teaches {}".format(self.name, ','.join(self.papers))

#person1 = Person('Sachin')
#person2 = Student('Kushal', 'CSE', 2005)
#person3 = Teacher('Prashad', ['C', 'C++'])

#print(person1.get_details())
#print(person2.get_details())
#print(person3.get_details())

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("wrong arguments")
    else:
        person4 = Person(sys.argv[1])
        person4.get_grade(sys.argv[2])