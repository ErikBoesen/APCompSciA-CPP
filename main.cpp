#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    QPushButton *quit = new QPushButton("Quit", this);
    textBox = new QLineEdit();
    QPushButton *render = new QPushButton("Render", this);
    lbl = new QLabel("Enter some text and click \"Render.\"", this);
    lbl->setMinimumWidth(300);
    lbl->setMaximumWidth(300);
    lbl->setWordWrap(true);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(quit, 0, 0);
    grid->addWidget(textBox, 0, 1);
    grid->addWidget(render, 0, 2);
    grid->addWidget(lbl, 1, 0, 1, 3);

    setLayout(grid);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(render, &QPushButton::clicked, this, &Window::Render);
}

void Window::Render() {

    lbl->setText("You typed \"" + textBox->text() + "\".");
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Testing");
    window.resize(200, 200);
    window.show();

    return app.exec();
}
