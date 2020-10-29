#include "studentlistmodel.h"

StudentListModel::StudentListModel()
{
    this->studentList.append({"Jan", "Piere", "Björn", "Ted"});
}

int StudentListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return studentList.length();
}

QVariant StudentListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return studentList.at(index.row());
    }
    return QVariant();
}

void StudentListModel::addStudent(QString name)
{
    beginInsertRows(QModelIndex(), 0, 0);
    this->studentList.append(name);
    endInsertRows();
}

void StudentListModel::removeStudent(int index)
{
    // Remove a student from the model.
    // we need to notify the view about the change, before and after!
    // Before:
    beginRemoveRows(QModelIndex(), index, index);
    this->studentList.removeAt(index);
    endRemoveRows();
}

