import sys
import os
myDir = os.getcwd()
sys.path.append(myDir)

from PyQt5 import QtWidgets
from Database.Connection import connection
from Models.Select import select

class Insertar_fifa():
    def __init__(self,tabla):
        self.conn = select(connection,tabla)

    def Insertar(self, _id, _foot, _position, _awr, _dwr, _ovr, _pac, _sho, _pas,
                _dri, _def, _phy, _sm, _div, _pos, _han, _ref, _kic, _spd, close):
        
        close.hide()