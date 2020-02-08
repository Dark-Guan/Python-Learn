# author: Dark
# Data: 2020-2-7
# Detail: This is a test for QT 

import sys,os,time,multiprocessing,requests

from PyQt4.QtGui import QMainWindow , QIcon , \
                 QApplication, QListWidgetItem, \
                 QMessageBox, QDesktopServices, \
                 QFileDialog
from PyQt4.QtCore import pyqtSignal, QUrl ,QThread
from PyQt4 import QtGui
from contextlib import closing

import ui

class Backend(QThread):
    update_date = pyqtSignal()
    def run(self):
        while True:
            self.update_date.emit()
            time.sleep(0.2)
 
class MainWindow(QMainWindow,ui.Ui_MainWindow):    
    def __init__(self):    
        super(MainWindow, self).__init__()
        self.setupUi(self)
        self.pushButton.clicked.connect(self.buttonclicked)
        
    def buttonclicked(self):
        MultiProcess().startwork()
        self.pushButton.setEnabled(False)
        
    def handleDisplay(self):
        self.listWidget.clear()
        if len(percent) > 0 :
            self.pushButton.setEnabled(False)
            for k in range(90) :
                if percent.has_key(k) & use_time.has_key(k) :
                    self.listWidget.addItem('Process%02d : %03d%%    Time:%ds' % (k,percent[k],use_time[k]))
        else :
            self.pushButton.setEnabled(True)
        
class MultiProcess:
    def subPrcess(self,name,percent,use_time):
        time_old = time.time()
        headers = {"User-Agent":"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36"}
        with closing(requests.get('http://www.python.org/ftp/python/2.7.5/Python-2.7.5.tar.bz2',headers=headers,stream=True)) as response:
            chunk_size = 1024  
            content_size = int(response.headers['content-length'])  
            data_count = 0
            with open('download/%d.tar.bz2' % name, "wb") as file:
                for data in response.iter_content(chunk_size=chunk_size):
                    file.write(data)
                    data_count = data_count + len(data)
                    percent[name] = (data_count * 100) / content_size
                    use_time[name] = time.time() - time_old
        del percent[name],use_time[name]
        
    def startwork(self):
        for i in range(90):
            p = multiprocessing.Process(target=self.subPrcess,args=(i,percent,use_time))
            print 'Process %d start.' % i
            p.start() 
        
if __name__ == "__main__":
    percent = multiprocessing.Manager().dict()
    use_time = multiprocessing.Manager().dict()
    app = QApplication(sys.argv)
    app.setOrganizationName(" ")
    app.setOrganizationDomain(" ")
    app.setApplicationName(" ")    
    app.setWindowIcon(QIcon(os.path.join("icon.png")))
    b = Backend()
    form = MainWindow()
    b.update_date.connect(form.handleDisplay)
    b.start()
    form.show()
    app.exec_()    