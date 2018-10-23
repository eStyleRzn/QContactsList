#include "ContactTreeItemWidget.h"

#include "ui_ContactTreeItemWidget.h"

//======================================================================================================================
ContactTreeItemWidget::ContactTreeItemWidget(QWidget* parent)
  : _Base(parent)
  , wt_(new Ui::ContactTreeItemWidget)
{
  wt_->setupUi(this);
}

//----------------------------------------------------------------------------------------------------------------------
ContactTreeItemWidget::~ContactTreeItemWidget()
{
  if (wt_)
    delete wt_;
}

void ContactTreeItemWidget::setName(const QString& name)
{
  wt_->lblFullName->setText(name);
}
