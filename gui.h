#ifndef GUI_H
#define GUI_H

#include "stafflist.h"
#include <QWidget>


class QLineEdit;
class QCalendarWidget;
class QComboBox;
class QPushButton;


class gui : public QWidget
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr);
    ~gui();

private slots:
    void enableProcessButton();
    void process();
    void writeTofile();


private:
    void setUpGui();

    StaffList  *staffList;
    QLineEdit *nameEdit;
    QCalendarWidget *calenda;
    QComboBox *typeCombo;
    QPushButton *processButton;
    QPushButton *writeButton;
};
#endif // GUI_H
