#include "staffwriter.h"
#include <QFile>
#include <QTextStream>



StaffWriter::StaffWriter(StaffList *sl): staffList{sl}
{

}

bool StaffWriter::writeToFile() const
{
    QFile file("staffFile.txt");
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QTextStream toFile(&file);

    QList<Staff*> list = staffList->getStaffList();

    foreach (Staff *s, list) {

       const QMetaObject *meta = s->metaObject();

        QString result;

        for (int i = meta->propertyOffset(); i < meta->propertyCount(); ++i) {
            const QMetaProperty prop = meta->property(i);
            QString name = prop.name();
            QVariant value = prop.read(s);
            QString strValue = value.toString();

            result += prop.read(s).toString() + " ";
        }
        toFile << result << '\n';

    }

    file.close();

    return true;


}
