# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Search2.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_search2(object):
    def setupUi(self, search2):
        search2.setObjectName("search2")
        search2.resize(217, 184)
        self.layoutWidget = QtWidgets.QWidget(search2)
        self.layoutWidget.setGeometry(QtCore.QRect(10, 70, 191, 98))
        self.layoutWidget.setObjectName("layoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.layoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.btn_search = QtWidgets.QPushButton(self.layoutWidget)
        self.btn_search.setObjectName("btn_search")
        self.gridLayout.addWidget(self.btn_search, 2, 0, 1, 2)
        self.btn_valor_1 = QtWidgets.QPushButton(self.layoutWidget)
        self.btn_valor_1.setObjectName("btn_valor_1")
        self.gridLayout.addWidget(self.btn_valor_1, 0, 0, 1, 1)
        self.input_valor_1 = QtWidgets.QLineEdit(self.layoutWidget)
        self.input_valor_1.setStyleSheet("")
        self.input_valor_1.setText("")
        self.input_valor_1.setObjectName("input_valor_1")
        self.gridLayout.addWidget(self.input_valor_1, 0, 1, 1, 1)
        self.btn_valor_2 = QtWidgets.QPushButton(self.layoutWidget)
        self.btn_valor_2.setObjectName("btn_valor_2")
        self.gridLayout.addWidget(self.btn_valor_2, 1, 0, 1, 1)
        self.input_valor_2 = QtWidgets.QLineEdit(self.layoutWidget)
        self.input_valor_2.setStyleSheet("")
        self.input_valor_2.setText("")
        self.input_valor_2.setObjectName("input_valor_2")
        self.gridLayout.addWidget(self.input_valor_2, 1, 1, 1, 1)
        self.titulo = QtWidgets.QTextBrowser(search2)
        self.titulo.setGeometry(QtCore.QRect(0, 10, 211, 171))
        self.titulo.setStyleSheet("background: rgba(6,187,176,1)")
        self.titulo.setObjectName("titulo")
        self.titulo.raise_()
        self.layoutWidget.raise_()

        self.retranslateUi(search2)
        QtCore.QMetaObject.connectSlotsByName(search2)

    def retranslateUi(self, search2):
        _translate = QtCore.QCoreApplication.translate
        search2.setWindowTitle(_translate("search2", "Form"))
        self.btn_search.setText(_translate("search2", "Search"))
        self.btn_valor_1.setText(_translate("search2", "Valor_inicial"))
        self.input_valor_1.setPlaceholderText(_translate("search2", "ej. 1"))
        self.btn_valor_2.setText(_translate("search2", "Valor_final"))
        self.input_valor_2.setPlaceholderText(_translate("search2", "ej. 3"))
        self.titulo.setHtml(_translate("search2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600;\">UTEC</span></p></body></html>"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    search2 = QtWidgets.QWidget()
    ui = Ui_search2()
    ui.setupUi(search2)
    search2.show()
    sys.exit(app.exec_())
