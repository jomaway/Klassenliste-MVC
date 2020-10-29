#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QAbstractListModel>

class StudentListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    StudentListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    void addStudent(QString name);
    void removeStudent(int index);
private:
    QStringList studentList;
};

#endif // STUDENTMODEL_H
