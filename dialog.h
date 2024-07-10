#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QCheckBox;
class QLineEdit;
class QPushButton;
class QListWidget;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void slotQueryFiles();
    void slotReplaceFiles();

private:
    QLabel*queryLabel;
    QLabel*replaceLabel;
    QLineEdit*queryLine;
    QLineEdit*replaceLine;
    QPushButton*queryButton;
    QPushButton*replaceButton;
    QListWidget*resultList;
    QCheckBox*fileCheckBox;
    QCheckBox*dirCheckBox;

};
#endif // DIALOG_H
