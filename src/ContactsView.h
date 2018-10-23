#ifndef CONTACTSVIEW_H
#define CONTACTSVIEW_H

#include <QTreeView>

//======================================================================================================================
// TODO Place class description here
class ContactsModel;
class ContactItemDelegate;
class ContactsView : public QTreeView
{
  using _Base = QTreeView;
  Q_OBJECT
public:
  ContactsView(QWidget* parent);
  virtual ~ContactsView() {}

private slots:
  void onDeledateExpand(const QModelIndex&);

private:
  // Disable copying
  ContactsView(const ContactsView&) = delete;
  ContactsView& operator=(const ContactsView&) = delete;

  ContactsModel* model_ = nullptr;
  ContactItemDelegate* delegate_ = nullptr;
};

#endif // CONTACTSVIEW_H
