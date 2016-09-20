#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    QPushButton *quit = new QPushButton("Quit", this);
    num1 = new QLineEdit();
    num1->setMinimumWidth(50);
    num2 = new QLineEdit();
    num2->setMinimumWidth(50);
    operation = new QComboBox();
    operation->addItem("+");
    operation->addItem("-");
    operation->addItem("*");
    operation->addItem("/");
    QPushButton *render = new QPushButton("Render", this);
    lbl = new QLabel(this);
    lbl->setWordWrap(true);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(quit, 0, 0);
    grid->addWidget(num1, 0, 1);
    grid->addWidget(operation, 0, 2);
    grid->addWidget(num2, 0, 3);
    grid->addWidget(render, 0, 4);
    grid->addWidget(lbl, 0, 5);

    setLayout(grid);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(render, &QPushButton::clicked, this, &Window::Calculate);
}

void Window::Calculate() {

    switch (operation->currentIndex()) {
        case 0:
            lbl->setText(QString::number(num1->text().toDouble() + num2->text().toDouble()));
            break;
        case 1:
            lbl->setText(QString::number(num1->text().toDouble() - num2->text().toDouble()));
            break;
        case 2:
            lbl->setText(QString::number(num1->text().toDouble() * num2->text().toDouble()));
            break;
        case 3:
            lbl->setText(QString::number(num1->text().toDouble() / num2->text().toDouble()));
            break;
    }
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Calculator");
    window.resize(200, 50);
    window.show();

    return app.exec();
}
