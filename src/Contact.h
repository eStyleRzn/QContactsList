#ifndef CONTACT_H
#define CONTACT_H

#include <QList>
#include <QVariant>

//======================================================================================================================
class Contact
{
public:
  Contact();
};

//======================================================================================================================
class TreeItem
{
public:
    explicit TreeItem(const QList<QVariant> &data, TreeItem* parentItem = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem* parentItem();

private:
    QList<TreeItem*> m_childItems;
    QList<QVariant> m_itemData;
    TreeItem *m_parentItem;
};

#endif // CONTACT_H
