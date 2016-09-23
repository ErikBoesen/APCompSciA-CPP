#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    QLabel *instructions = new QLabel("Enter the three sides of your triangle:", this);
    side1 = new QLineEdit();
    side2 = new QLineEdit();
    side3= new QLineEdit();
    side1->setMinimumWidth(50);
    side2->setMinimumWidth(50);
    side3->setMinimumWidth(50);
    QPushButton *calculate = new QPushButton("Calculate Area", this);
    lbl = new QLabel(this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(instructions, 0, 0);
    grid->addWidget(side1, 0, 1);
    grid->addWidget(side2, 0, 2);
    grid->addWidget(side3, 0, 3);
    grid->addWidget(calculate, 0, 4);
    grid->addWidget(lbl, 0, 5);

    setLayout(grid);

    connect(calculate, &QPushButton::clicked, this, &Window::CalculateArea);
}

void Window::CalculateArea() {

    double a = side1->text().toDouble();
    double b = side2->text().toDouble();
    double c = side3->text().toDouble();

    double s = (a + b + c) / 2.0;
    if (a >= b + c || b >= a + c || c >= a + b || a == 0 || b == 0 || c == 0) {
        lbl->setText("Invalid triangle.");
    } else {
        lbl->setText(QString::number( sqrt(s * (s - a) * (s - b) * (s - c)) ));
    }

}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Heron's Formula Calculator");
    window.resize(200, 50);
    window.show();

    return app.exec();
}
