#include "ContactsModel.h"

#include <QDebug>

#include "Contact.h"

//======================================================================================================================
ContactsModel::ContactsModel(QObject* parent)
  :_Base(parent)
{
  QList<QVariant> rootData;
  rootData << "Title" << "Summary";
  rootItem = new TreeItem(rootData);

  QStringList strings{
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
  };

  setupModelData(strings, rootItem);
}

//----------------------------------------------------------------------------------------------------------------------
ContactsModel::~ContactsModel()
{
  delete rootItem;
}

//----------------------------------------------------------------------------------------------------------------------
QModelIndex ContactsModel::index(int row, int column, const QModelIndex& parent) const
{
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  TreeItem* parentItem;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  TreeItem* childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

//----------------------------------------------------------------------------------------------------------------------
int ContactsModel::rowCount(const QModelIndex& parent) const
{
  int count;
  TreeItem *parentItem;
  if (parent.column() > 0)
    return 0;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  count = parentItem->childCount();

//  qDebug() << __FUNCTION__ << count << parent;

  return count;
}

//----------------------------------------------------------------------------------------------------------------------
int ContactsModel::columnCount(const QModelIndex& parent) const
{
  return 1;

  if (parent.isValid())
      return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
  else
    return rootItem->columnCount();
}

//----------------------------------------------------------------------------------------------------------------------
void ContactsModel::setupModelData(const QStringList& lines, TreeItem* root)
{
  for (auto&& el : lines)
  {
    // Create group item
    QList<QVariant> data;
    data.push_back(QVariant(el));
    auto group = new TreeItem(data, root);
    root->appendChild(group);

    // Create children
    for (auto&& elChild : lines)
    {
      QList<QVariant>childData;
      childData.push_back(elChild);
      group->appendChild(new TreeItem(childData, group));
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
  if (!index.isValid())
      return QVariant();

  if (role != Qt::DisplayRole)
      return QVariant();

  TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

  return item->data(index.column());
}

//----------------------------------------------------------------------------------------------------------------------
Qt::ItemFlags ContactsModel::flags(const QModelIndex& index) const
{
  if (!index.isValid())
    return 0;

  return QAbstractItemModel::flags(index);
}

//----------------------------------------------------------------------------------------------------------------------
QVariant ContactsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return rootItem->data(section);

  return QVariant();
}

//----------------------------------------------------------------------------------------------------------------------
QModelIndex ContactsModel::parent(const QModelIndex& index) const
{
  if (!index.isValid())
    return QModelIndex();

  TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
  TreeItem *parentItem = childItem->parentItem();

  if (parentItem == rootItem)
    return QModelIndex();

  return createIndex(parentItem->row(), 0, parentItem);
}
