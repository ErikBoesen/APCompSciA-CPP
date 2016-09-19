#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QRect>

class Window : public QWidget {

    public:
        Window(QWidget *parent = 0);

    private slots:
        void Render();

    private:
        QLineEdit *num1;
        QLineEdit *num2;
        QComboBox *operation;
        QLabel *lbl;
};
