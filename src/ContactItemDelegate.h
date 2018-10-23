#ifndef CONTACTITEMDELEGATE_H
#define CONTACTITEMDELEGATE_H

#include <QStyledItemDelegate>
#include "ContactGroupTreeItemWidget.h"
#include "ContactTreeItemWidget.h"

//======================================================================================================================
// TODO Place class description here
class ContactItemDelegate : public QStyledItemDelegate
{
  using _Base = QStyledItemDelegate;
  Q_OBJECT
public:
  ContactItemDelegate(QObject *parent);
  virtual ~ContactItemDelegate() override {}

  virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
  virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

protected:
  virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

signals:
  void expand(const QModelIndex &index);

private:
  // Disable copying
  ContactItemDelegate(const ContactItemDelegate&) = delete;
  ContactItemDelegate& operator=(const ContactItemDelegate&) = delete;

  mutable ContactGroupTreeItemWidget  groupWidget_;
  mutable ContactTreeItemWidget       itemWidget_;
};

#endif // CONTACTITEMDELEGATE_H
