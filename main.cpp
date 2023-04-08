#include "main.h"
#include "QApplication"
#include "QLabel"
#include "QDialog"
#include "QLineEdit"
#include "QPushButton"
#include "QVBoxLayout"


#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Prompt the user to enter their name in a dialog box
    QDialog dialog;
    dialog.setWindowTitle("Enter your name");
    dialog.setFixedSize(300, 100);
    QLineEdit *lineEdit = new QLineEdit(&dialog);
    lineEdit->setPlaceholderText("Enter your name");
    QPushButton *button = new QPushButton("OK", &dialog);
    QObject::connect(button, &QPushButton::clicked, &dialog, &QDialog::accept);
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    dialog.setLayout(layout);
    dialog.exec();

    // Get the user's name and display it in a label
    QString name = lineEdit->text();
    QLabel *label = new QLabel("Hi! It's " + name);
    label->setWindowTitle("My Demo Application");
    label->setStyleSheet("font-size: 25pt;");
    label->resize(400, 400);
    label->show();

    return app.exec();
}
