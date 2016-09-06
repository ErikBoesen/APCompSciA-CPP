#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget window;

    window.resize(500, 400);
    window.setWindowTitle("Assignment 1");
    window.show();

    return app.exec();
}