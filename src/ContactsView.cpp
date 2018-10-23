#include "ContactsView.h"

#include "ContactItemDelegate.h"
#include "ContactsModel.h"

//======================================================================================================================
ContactsView::ContactsView(QWidget* parent)
  : _Base(parent)
  , model_(new ContactsModel(this))
  , delegate_(new ContactItemDelegate(this))
{
  setItemDelegate(delegate_);
  connect(delegate_, SIGNAL(expand(const QModelIndex&)), this, SLOT(onDeledateExpand(const QModelIndex&)));

  setModel(model_);
}

//----------------------------------------------------------------------------------------------------------------------
void ContactsView::onDeledateExpand(const QModelIndex& index)
{
  if (isExpanded(index))
    collapse(index);
  else
    expand(index);
}
