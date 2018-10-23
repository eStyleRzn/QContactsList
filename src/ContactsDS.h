#ifndef CONTACTSDS_H
#define CONTACTSDS_H

#include <QVector>
#include <QString>

//======================================================================================================================
// Contacts data source implementation class
class ContactsDS
{
public:
  using ContactGroup = QString;
  using ContactGroupsBox = QVector<ContactGroup>;
  using SizeType = ContactGroupsBox::size_type;

  using Contact = QString;
  using ContactsBox = QVector<QString>;

  ContactsDS();
  virtual ~ContactsDS() {}

  ContactGroupsBox::size_type contactTypesCount() const;
  const ContactGroup* contactsGroup(ContactGroupsBox::size_type) const;

  ContactsBox::size_type ContactsCount(int) const;
  const Contact* getContact(ContactsBox::size_type) const;

private:
  // Disable copying
  ContactsDS(const ContactsDS&) = delete;
  ContactsDS& operator=(const ContactsDS&) = delete;

  ContactGroupsBox groups_;
};

#endif // CONTACTSDS_H
