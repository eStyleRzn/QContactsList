TEMPLATE = app
TARGET = ContactsList

CONFIG -= debug_and_release
CONFIG += rtti exceptions
CONFIG += c++11

QT += core gui widgets svg

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG_NAME = release

CONFIG(debug, debug|release){
  CONFIG_NAME = debug
  MY_PLATFORM_PLUGINS += $$[QT_INSTALL_PLUGINS]/platforms/qwindowsd.dll

  MY_IMAGE_PLUGINS += $$[QT_INSTALL_PLUGINS]/imageformats/qsvgd.dll

  MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Cored.dll
  MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Guid.dll
  MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Widgetsd.dll
}

DESTDIR = $$absolute_path($$PWD/bin/$$CONFIG_NAME)

OBJECTS_DIR = $${OUT_PWD}/$$CONFIG_NAME/gen/obj
MOC_DIR     = $${OUT_PWD}/$$CONFIG_NAME/gen/moc
RCC_DIR     = $${OUT_PWD}/$$CONFIG_NAME/gen/res
UI_DIR      = $${OUT_PWD}/$$CONFIG_NAME/gen/uic

# Define what files are 'extra_libs' and where to put them
ExtraLibs.files = $$MY_LIB_FILES
ExtraLibs.path = $${DESTDIR}

ExtraPlatforms.files += $$MY_PLATFORM_PLUGINS
ExtraPlatforms.path += $${DESTDIR}/platforms

ExtraImageFormats.files += $$MY_IMAGE_PLUGINS
ExtraImageFormats.path += $${DESTDIR}/imageformats

# Tell qmake to add the moving of them to the 'install' target
INSTALLS += ExtraLibs \
    ExtraPlatforms \
    ExtraImageFormats \

HEADERS += \
    src/MainWindow.h \
    src/ContactsView.h \
    src/ContactsModel.h \
    src/ContactsDS.h \
    src/Contact.h \
    src/ContactItemDelegate.h \
    src/ContactGroupTreeItemWidget.h \
    src/ContactTreeItemWidget.h

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/ContactsView.cpp \
    src/ContactsModel.cpp \
    src/ContactsDS.cpp \
    src/Contact.cpp \
    src/ContactItemDelegate.cpp \
    src/ContactGroupTreeItemWidget.cpp \
    src/ContactTreeItemWidget.cpp

FORMS += \
    src/MainWindow.ui \
    src/ContactGroupTreeItemWidget.ui \
    src/ContactTreeItemWidget.ui

RESOURCES += \
    src/res/styles.qrc

DISTFILES += \
    src/res/styles.qss

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# This must be always the last string in the file, since it prints the final values
include($$PWD/CommonMessages.pri)

