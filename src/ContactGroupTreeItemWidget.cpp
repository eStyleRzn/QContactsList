#include "ContactGroupTreeItemWidget.h"

#include "ui_ContactGroupTreeItemWidget.h"

//======================================================================================================================
ContactGroupTreeItemWidget::ContactGroupTreeItemWidget(QWidget* parent)
  : _Base(parent)
  , wt_(new Ui::ContactGroupTreeItemWidget)
{
  wt_->setupUi(this);
}

//----------------------------------------------------------------------------------------------------------------------
ContactGroupTreeItemWidget::~ContactGroupTreeItemWidget()
{
  if (wt_)
    delete wt_;
}

//----------------------------------------------------------------------------------------------------------------------
void ContactGroupTreeItemWidget::setExpanded(bool v)
{
  wt_->btnExpand->setProperty("expanded", v);
  style()->unpolish(wt_->btnExpand);
  style()->polish(wt_->btnExpand);
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void ContactGroupTreeItemWidget::setCaption(const QString& s)
{
  wt_->txtCaption->setText(s);
}

//----------------------------------------------------------------------------------------------------------------------
const QRect& ContactGroupTreeItemWidget::rectExpandButton() const
{
  return wt_->btnExpand->geometry();
}
