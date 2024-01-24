#include "gui.h"

#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QComboBox>
#include <QPushbutton>
#include <QGridLayout>
#include <QMessageBox>


gui::gui(QWidget *parent)
    : QWidget(parent), nameEdit{new QTextEdit},calenda(new QCalendarWidget),
    typeCombo{new QComboBox}, processButton{new QPushButton("Process Button")},
    writeButton{new QPushButton("Write to file")}

{
    setUpGui();
    typeCombo->addItem("Permanent");
    typeCombo->addItem("Part-time");
    typeCombo->addItem("Contract");
}

gui::~gui()
{
}

void gui::setUpGui()
{
    setWindowTitle("Staff");

    QLabel * nameLabel(new QLabel("Name"));
    QLabel * dateLabel(new QLabel("Birth Date"));
    QLabel * typeLabel(new QLabel( "Staff Type"));

    QGridLayout * layout{new QGridLayout(this)};
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);
    layout->addWidget(dateLabel);
    layout->addWidget(calenda);
    layout->addWidget(typeLabel);
    layout->addWidget(typeCombo);
    layout->addWidget(processButton);
    layout->addWidget(writeButton);

    processButton->setEnabled(false);
    writeButton->setEnabled(false);
    this->setLayout(layout);
    this->adjustSize();




}
