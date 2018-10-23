#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include <QAbstractItemModel>

#include "ContactsDS.h"

//======================================================================================================================
// TODO Place class description here
class TreeItem;
class ContactsModel : public QAbstractItemModel
{
  using _Base = QAbstractItemModel;
public:
  ContactsModel(QObject* parent);
  virtual ~ContactsModel() override;

  QVariant data(const QModelIndex &index, int role) const override;
  Qt::ItemFlags flags(const QModelIndex &index) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;
  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex &index) const override;
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
  // Disable copying
  ContactsModel(const ContactsModel&) = delete;
  ContactsModel& operator=(const ContactsModel&) = delete;

  void setupModelData(const QStringList &lines, TreeItem* root);

  ContactsDS ds_;
  TreeItem* rootItem = nullptr;
};

#endif // CONTACTSMODEL_H
