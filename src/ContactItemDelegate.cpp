#include "ContactItemDelegate.h"

#include <QPainter>
#include <QApplication>
#include <QMouseEvent>
#include <QRect>
#include <QDebug>

//======================================================================================================================
ContactItemDelegate::ContactItemDelegate(QObject*)
{
//  qDebug() << __FUNCTION__;

  groupWidget_.setAttribute(Qt::WA_DontShowOnScreen, true);
  groupWidget_.show();

  itemWidget_.setAttribute(Qt::WA_DontShowOnScreen, true);
  itemWidget_.show();
}

//----------------------------------------------------------------------------------------------------------------------
void ContactItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
  // qDebug() << __FUNCTION__;
  if (index.parent().isValid()) // This is for contact item
  {
    itemWidget_.setName(index.data().toString());

    painter->save();
    painter->translate(option.rect.topLeft());
    itemWidget_.render(painter, QPoint(), QRegion(), QWidget::DrawChildren);
    painter->restore();
  }
  else // This is for contact group item
  {
    groupWidget_.setCaption(index.data().toString());
    const bool isExpanded = QStyle::State_Open & option.state;
    groupWidget_.setExpanded(isExpanded);

//    qDebug() << __FUNCTION__ << " " << index  << " " << isExpanded;

    painter->save();
    painter->translate(option.rect.topLeft());
    groupWidget_.render(painter, QPoint(), QRegion(), QWidget::DrawChildren);
    painter->restore();
  }
}

//----------------------------------------------------------------------------------------------------------------------
QSize ContactItemDelegate::sizeHint(const QStyleOptionViewItem&, const QModelIndex& index) const
{
  if (index.parent().isValid()) // This is for contact item
    return itemWidget_.size();

  return groupWidget_.size();
}

//----------------------------------------------------------------------------------------------------------------------
bool ContactItemDelegate::editorEvent(QEvent* event, QAbstractItemModel*, const QStyleOptionViewItem& option, const QModelIndex& index)
{
  // Emit a signal when the icon is clicked
  if (!index.parent().isValid() && QEvent::MouseButtonRelease == event->type())
  {
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
    auto r = groupWidget_.rectExpandButton().translated(option.rect.topLeft());
    if(r.contains(mouseEvent->pos()))
    {
      // qDebug() << __FUNCTION__ << option.rect << " " << groupWidget_.rectExpandButton() << " " << r << " " << mouseEvent->pos();
      emit expand(index);
    }

//    qDebug() << __FUNCTION__ << option.rect << " " << groupWidget_.rectExpandButton() << " " << r << " " << mouseEvent->pos();
  }
  return false;
}
