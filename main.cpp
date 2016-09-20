#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    QLabel *lowlbl = new QLabel("Lower Limit (noninclusive):", this);
    QLabel *highlbl = new QLabel("Higher Limit:", this);
    low = new QLineEdit();
    high = new QLineEdit();
    low->setMinimumWidth(50);
    high->setMinimumWidth(50);
    QPushButton *choose = new QPushButton("Choose", this);
    lbl = new QLabel(this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(lowlbl, 0, 0);
    grid->addWidget(low, 0, 1);
    grid->addWidget(highlbl, 0, 2);
    grid->addWidget(high, 0, 3);
    grid->addWidget(choose, 0, 4);
    grid->addWidget(lbl, 0, 5);

    setLayout(grid);

    connect(choose, &QPushButton::clicked, this, &Window::GenerateRandom);
}

void Window::GenerateRandom() {

    int lowNum = low->text().toInt();
    int highNum = high->text().toInt();
    if (lowNum < highNum) {
        lbl->setText(QString::number(rand() % (highNum - lowNum) + lowNum + 1));
    } else {
        lbl->setText("Error.");
    }
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Random Number Chooser");
    window.resize(200, 50);
    window.show();

    return app.exec();
}
