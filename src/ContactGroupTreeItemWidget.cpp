#include "ContactGroupTreeItemWidget.h"

#include <QDebug>

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
    auto pic = v ? QPixmap(":/images/arrow-up.svg") : QPixmap(":/images/arrow-down.svg");
    wt_->btnExpand->setPixmap(pic);
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
