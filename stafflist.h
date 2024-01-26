#ifndef STAFFLIST_H
#define STAFFLIST_H
#include "staff.h"


class StaffList
{
public:
    StaffList();
    void addStaff(Staff s);
    QList<Staff> getStaffList() const;

private:
    QList<Staff> staffList;
};

#endif // STAFFLIST_H
