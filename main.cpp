#include <QTextStream>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);

    // Define an example QString for test manipulation
    QString aString = "is a testing QString";
    out << aString << endl;

    // Add to the start of the string
    aString.prepend("This ");
    out << aString << endl;
    // Add a period to the end of the sentence
    aString.append(".");
    out << aString << endl;

    out << "The string is " << aString.count() << " chars long!" << endl;

    out << "In lcase: " << aString.toLower() << endl;
    out << "In ucase: " << aString.toUpper() << endl;

    out << "Third char: " << aString[2] << endl;
}
