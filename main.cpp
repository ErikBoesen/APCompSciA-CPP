#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    num1 = new QLineEdit();
    num1->setMinimumWidth(40);
    num2 = new QLineEdit();
    num2->setMinimumWidth(40);
    operation = new QComboBox();
    operation->addItem("+");
    operation->addItem("-");
    operation->addItem("*");
    operation->addItem("/");
    QPushButton *render = new QPushButton("Render", this);
    lbl = new QLabel(this);
    lbl->setWordWrap(true);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(num1, 0, 0);
    grid->addWidget(operation, 0, 1);
    grid->addWidget(num2, 0, 2);
    grid->addWidget(render, 0, 3);
    grid->addWidget(lbl, 0, 4);

    setLayout(grid);

    connect(render, &QPushButton::clicked, this, &Window::Render);
}

void Window::Render() {

    switch (operation->currentIndex()) {
        case 0:
            lbl->setText(QString::number(num1->text().toInt() + num2->text().toInt()));
            break;
        case 1:
            lbl->setText(QString::number(num1->text().toInt() - num2->text().toInt()));
            break;
        case 2:
            lbl->setText(QString::number(num1->text().toInt() * num2->text().toInt()));
            break;
        case 3:
            lbl->setText(QString::number(num1->text().toInt() / num2->text().toInt()));
            break;
    }
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Testing");
    window.resize(200, 50);
    window.show();

    return app.exec();
}
