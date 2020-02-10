def decorator(func):
    def wrapper(*args, **kw):
        print " run here args " + str(args) + " kw " + str(kw)
        return func()
    return wrapper

@decorator
def function():
    print("hello, decorator")

if __name__ == "__main__":
    print "run hallo decorator"
    function()