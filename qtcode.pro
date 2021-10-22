QT       += core gui sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_adding.cpp \
    admin_series_adding.cpp \
    file.cpp \
    genre.cpp \
    genre_series.cpp \
    help.cpp \
    language.cpp \
    language_series.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    movielist.cpp \
    moviemenu.cpp \
    pdeletep.cpp \
    series.cpp \
    series_delete.cpp \
    series_list.cpp \
    userinfo.cpp \
    users.cpp

HEADERS += \
    admin.h \
    admin_adding.h \
    admin_series_adding.h \
    file.h \
    genre.h \
    genre_series.h \
    help.h \
    language.h \
    language_series.h \
    login.h \
    mainwindow.h \
    movie.h \
    movielist.h \
    moviemenu.h \
    pdeletep.h \
    series.h \
    series_delete.h \
    series_list.h \
    userinfo.h \
    users.h

FORMS += \
    admin.ui \
    admin_adding.ui \
    admin_series_adding.ui \
    file.ui \
    genre.ui \
    genre_series.ui \
    help.ui \
    language.ui \
    language_series.ui \
    login.ui \
    mainwindow.ui \
    movie.ui \
    movielist.ui \
    moviemenu.ui \
    pdeletep.ui \
    series.ui \
    series_delete.ui \
    series_list.ui \
    userinfo.ui \
    users.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    resources.qrc

