#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QRect>

class Window : public QWidget {

    public:
        Window(QWidget *parent = 0);

    private slots:
        void Render();

    private:
        QLineEdit *textBox;
        QLabel *lbl;
};
