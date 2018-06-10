#!/usr/bin/env python3
"""
请在 /home/shiyanlou/Code写出一个 MinutesToHours.py 脚本文件，实现一个函数 Hours()，将用户输入的分钟数转化为小时数和分钟数，
并要求小时数尽量大。将结果以 XX H, XX M 的形式打印出来。(注意打印格式中的空格).
要求：

用户能够通过命令行参数输入分钟数，例如程序执行为 python3 MinutesToHours.py 80，传入的参数 80 就是分钟数，程序需要打印出相应的小时数和分钟数，输出为 1 H, 20 M。
如果用户输入的是一个负值，程序需要打印 ValueError。
需要进行 try...except 操作来控制异常。如果异常，在屏幕上打印打印出 ValueError： Input number cannot be negative 提示用户输入的值有误。

"""
import sys

def minutes2hours(value):
    hours, minutes = divmod(value, 60)
    print("{} H, {} M".format(hours, minutes))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("arguments error")
    else:
        try:
            if int(sys.argv[1]) < 0:
                raise ValueError("Input number cannot be negative")
            else:
                minutes2hours(int(sys.argv[1]))
        except ValueError:
            print("ValueError: Input number cannot be negative")
        #hours, minutes = minutes2hours(sys.argv[1])
        #print("{} H, {} M".format(hours, minutes))
