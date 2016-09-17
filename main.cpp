#include "main.h"

Window::Window(QWidget *parent) : QWidget(parent) {

    QPushButton *quit = new QPushButton("Quit", this);
    QLineEdit *textBox = new QLineEdit();
    QPushButton *render = new QPushButton("Render", this);
    lbl = new QLabel("0", this);
    lbl->setAlignment(Qt::AlignCenter);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(quit, 0, 0);
    grid->addWidget(textBox, 0, 1);
    grid->addWidget(render, 0, 2);
    grid->addWidget(lbl, 0, 3);

    setLayout(grid);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(render, &QPushButton::clicked, this, &Window::Render);
}

void Window::Render() {
    std::string rawText = textBox->text().toStdString();
    QString text = QString::fromLatin1(rawText.data(), rawText.size());
    lbl->setText(text);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    window.setWindowTitle("Testing");
    window.resize(300, 100);
    window.show();

    return app.exec();
}
