#include "gui.h"
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QComboBox>
#include <QPushbutton>
#include <QGridLayout>
#include <QMessageBox>
#include "staffwriter.h"


gui::gui(QWidget *parent)
    : QWidget{parent}, nameEdit{new QLineEdit},calenda(new QCalendarWidget),
    typeCombo{new QComboBox}, processButton{new QPushButton("Process Button")},
    writeButton{new QPushButton("Write to file")}, staffList{new StaffList}

{
    setUpGui();
    typeCombo->addItem("Permanent");
    typeCombo->addItem("Part-time");
    typeCombo->addItem("Contract");

    connect(nameEdit, &QLineEdit::textChanged, this, &gui::enableProcessButton);
    connect(processButton, &QPushButton::clicked, this, &gui::process);
    connect(writeButton, &QPushButton::clicked, this, &gui::writeTofile);
}

gui::~gui()
{
    delete staffList;
}


void gui::enableProcessButton()
{
    if (nameEdit->text().size()!=0)
    {
        processButton->setEnabled(true);
    }
}

void gui::process()
{
    QString name{nameEdit->text()};
    QDate date{calenda->selectedDate()};
    int typeIndex{typeCombo->currentIndex()};

    Staff::StaffType type{static_cast<Staff::StaffType>(typeIndex)};

    Staff *staff{new Staff(name, date, type)};
    staffList->addStaff(staff);

    nameEdit->clear();
    nameEdit->setFocus();
    calenda->setSelectedDate(QDate::currentDate());
    typeCombo->setCurrentIndex(0);
    processButton->setEnabled(false);
    writeButton->setEnabled(true);
    QMessageBox::information(this, "Staff detail", "Staff detail added");

}

void gui::writeTofile()
{
    StaffWriter writer(staffList);
    if(writer.writeToFile())
        QMessageBox::information(this, "Output", "Staff detail saved and written to file ");
    else
        QMessageBox::information(this, "Output", "Staff detail and not written to file");


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


