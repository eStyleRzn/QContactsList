#ifndef CONTACTTREEITEMWIDGET_H
#define CONTACTTREEITEMWIDGET_H

#include <QFrame>

namespace Ui {
    class ContactTreeItemWidget;
} // namespace Ui

//======================================================================================================================
// TODO Place class description here
class ContactTreeItemWidget : public QFrame
{
  using _Base = QFrame;
  Q_OBJECT
public:
  ContactTreeItemWidget(QWidget* parent = nullptr);
  virtual ~ContactTreeItemWidget();

  void setName(const QString& name);

private:
  // Disable copying
  ContactTreeItemWidget(const ContactTreeItemWidget&) = delete;
  ContactTreeItemWidget& operator=(const ContactTreeItemWidget&) = delete;

  Ui::ContactTreeItemWidget* wt_ = nullptr;
};

#endif // CONTACTTREEITEMWIDGET_H
