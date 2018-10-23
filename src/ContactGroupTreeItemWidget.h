#ifndef CONTACTGROUPTREEITEMWIDGET_H
#define CONTACTGROUPTREEITEMWIDGET_H

#include <QFrame>

namespace Ui {
    class ContactGroupTreeItemWidget;
}

//======================================================================================================================
// TODO Place class description here
class ContactGroupTreeItemWidget : public QFrame
{
  using _Base = QFrame;
  Q_OBJECT
public:
  ContactGroupTreeItemWidget(QWidget* parent = nullptr);
  virtual ~ContactGroupTreeItemWidget();

  void setExpanded(bool);
  void setCaption(const QString&);
  const QRect& rectExpandButton() const;

private:
  // Disable copying
  ContactGroupTreeItemWidget(const ContactGroupTreeItemWidget&) = delete;
  ContactGroupTreeItemWidget& operator=(const ContactGroupTreeItemWidget&) = delete;

  Ui::ContactGroupTreeItemWidget* wt_ = nullptr;
};

#endif // CONTACTGROUPTREEITEMWIDGET_H
