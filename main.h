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
#include <cmath>

class Window : public QWidget {

    public:
        Window(QWidget *parent = 0);

    private slots:
        void CalculateArea();

    private:
        QLineEdit *side1;
        QLineEdit *side2;
        QLineEdit *side3;
        QLabel *lbl;
};
