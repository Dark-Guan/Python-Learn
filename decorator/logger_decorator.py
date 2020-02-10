# -*- coding: utf-8 -*-

# 这是装饰器函数，参数 func 是被装饰的函数
def logger(func):
    def wrapper(*args, **kw):
        print('run '+str(func.__name__))

        # 真正执行的是这行。
        func(*args, **kw)

        print('run finished')
    return wrapper

@logger
def add(x, y):
    print('{} + {} = {}'.format(x, y, x+y))

if __name__ == "__main__":
    add(10,100)