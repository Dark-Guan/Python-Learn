import time
from multiprocessing import Process,Manager

def subPrcess(name,d):
    for j in range(100):
        time.sleep(0.2)
        d['process%d'%name] = j

def showmsg(d):
    while 1:
        time.sleep(1)
        for k in range(5):
          print 'Process%d:%d%%' % (k,d['process%d'%k])

if __name__ == '__main__':
    d = Manager().dict()
    p_list = []
    
    for i in range(5):
        p = Process(target=subPrcess,args=(i,d))
        print 'Process %d start.' % i
        p.start()    
        p_list.append(p)        

    sm = Process(target=showmsg,args=(d,))
    sm.start()

    for res in p_list:
        res.join()
    
    sm.terminate()     