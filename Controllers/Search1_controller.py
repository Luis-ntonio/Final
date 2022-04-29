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

mylib.search_S_Fifa.restype = None
mylib.search_S_Fifa.argtypes = [ctypes.c_char_p,ctypes.c_char_p]

aux = ""
mylib.search_S_Fifa(str("Pele").encode('utf-8'), str(aux).encode('utf-8'))
print(aux)

class Search1():
    def __init__(self,tabla):
        self.conn = select(connection,tabla)
    def search1(self, valor, close):
        close.hide()