#include "ContactsDS.h"

//======================================================================================================================
ContactsDS::ContactsDS()
{
  groups_.push_back("Избранные контакты");
  groups_.push_back("Сотрудники");
  groups_.push_back("Комнаты конференций");
  groups_.push_back("Личные");
  groups_.push_back("MANGO OFFICE");
  groups_.push_back("Битрикс24");
  groups_.push_back("amoCRM");
  groups_.push_back("Exchange");
  groups_.push_back("GSuite");
  groups_.push_back("iPhone9s");
}

//----------------------------------------------------------------------------------------------------------------------
ContactsDS::ContactGroupsBox::size_type ContactsDS::contactTypesCount() const
{
  return groups_.size();
}

//----------------------------------------------------------------------------------------------------------------------
const ContactsDS::ContactGroup* ContactsDS::contactsGroup(ContactGroupsBox::size_type idx) const
{
  if (idx >= groups_.size())
    return nullptr;

  return &groups_.at(idx);
}

//----------------------------------------------------------------------------------------------------------------------
ContactsDS::ContactsBox::size_type ContactsDS::ContactsCount(int) const
{
  return groups_.size();
}

//----------------------------------------------------------------------------------------------------------------------
const ContactsDS::Contact*ContactsDS::getContact(int idx) const
{
  if (idx >= groups_.size())
    return nullptr;

  return &groups_.at(idx);
}
