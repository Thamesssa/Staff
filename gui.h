#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QTextEdit>

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


private:
    void setUpGui();
    QTextEdit *nameEdit;
    QCalendarWidget *calenda;
    QComboBox *typeCombo;
    QPushButton *processButton;
    QPushButton *writeButton;
};
#endif // GUI_H
