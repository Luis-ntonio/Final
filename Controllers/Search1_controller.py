import sys
import os
import ctypes
import glob
myDir = os.getcwd()
sys.path.append(myDir)

from PyQt5 import QtWidgets
from Database.Connection import connection
from Models.Select import select

libfile =  glob.glob('build/*/menuSequential*.so')[0]
mylib = ctypes.CDLL(libfile)

mylib.search_S_Fifa.restype = ctypes.c_char_p
mylib.search_S_Fifa.argtypes = [ctypes.c_char_p,ctypes.c_char_p]




class Search1():
    def __init__(self,tabla,table):
        self.table = table
        self.conn = select(connection,tabla)
    def search1(self, valor, close):
        aux = ctypes.create_string_buffer(100)
        x = mylib.search_S_Fifa(str("Pele").encode('utf-8'),aux)
        x = x.decode('utf-8')
        x = x.split(',')
        tabla = self.table
        tabla.setRowCount(0)
        for column_number, data in x:
            tabla.setItem(0,column_number,QtWidgets.QTableWidgetItem(data))
        close.hide()