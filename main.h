#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

class Window : public QWidget {

    public:
        Window(QWidget *parent = 0);

    private slots:
        void Calculate();

    private:
        QLineEdit *num1;
        QLineEdit *num2;
        QComboBox *operation;
        QLabel *lbl;
};
