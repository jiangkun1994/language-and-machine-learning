#!/usr/bin/env python3
"""在/home/shiyanlou/Code创建一个名为 FindDigits.py 的Python 脚本，请读取一串字符串并且把其中所有的数字组成一个新的字符串，并且打印出来。我们提供的字符串可以通过在命令行中输入如下代码来获取。
wget http://labfile.oss.aliyuncs.com/courses/790/String.txt"""

f = open("String.txt")
x = f.read()
f.close()
z = []
for c in x:
    if(c.isdigit()):
        z.append(c)
for i in z:
    print(i, end='')
print()
