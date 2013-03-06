#-------------------------------------------------
#
# Project created by QtCreator 2013-01-10T22:10:45
#
#-------------------------------------------------

QT       += core gui xml sql

TARGET = Army_builder
TEMPLATE = app


SOURCES += main.cpp \
    Src/Vue/widgetpageeditable.cpp \
    Src/Vue/widgetpage.cpp \
    Src/Vue/widgetcouple.cpp \
    Src/Vue/tableau.cpp \
    Src/Vue/nouveau.cpp \
    Src/Vue/mainwindow.cpp \
    Src/Vue/liste.cpp \
    Src/Vue/info.cpp \
    Src/Vue/export.cpp \
    Src/Vue/charger.cpp \
    Src/Vue/categorie.cpp \
    Src/Vue/affichage.cpp \
    Src/Model/unite.cpp \
    Src/Model/modif.cpp \
    Src/Model/item.cpp \
    Src/Model/equipement.cpp \
    Src/Model/entreecodex.cpp \
    Src/Model/codex.cpp \
    Src/Model/arme.cpp \
    Src/Model/accompagnant.cpp \
    Src/Controlleur/sql.cpp \
    Src/Controlleur/controlleur.cpp \
    Src/Controlleur/controlleurmain.cpp \
    Src/Controlleur/controlleursauvegarde.cpp \
    Src/Controlleur/controlleurchargement.cpp \
    Src/Controlleur/controlleurnouveau.cpp \
    Src/Model/model.cpp \
    Module/Warhammer40KV5/unitewarhammer40kv5.cpp \
    Module/Warhammer40KV5/unite40kv5factory.cpp \
    Src/Model/unitefactory.cpp

HEADERS  += \
   Header/Vue/widgetpageeditable.h \
    Header/Vue/widgetpage.h \
    Header/Vue/widgetcouple.h \
    Header/Vue/tableau.h \
    Header/Vue/nouveau.h \
    Header/Vue/mainwindow.h \
    Header/Vue/liste.h \
    Header/Vue/info.h \
    Header/Vue/export.h \
    Header/Vue/charger.h \
    Header/Vue/categorie.h \
    Header/Vue/affichage.h \
    Header/Model/unite.h \
    Header/Model/modif.h \
    Header/Model/item.h \
    Header/Model/equipement.h \
    Header/Model/enum.h \
    Header/Model/entreecodex.h \
    Header/Model/codex.h \
    Header/Model/arme.h \
    Header/Model/accompagnant.h \
    Header/Controlleur/sql.h \
    Header/Controlleur/controlleurmain.h \
    Header/Controlleur/controlleursauvegarde.h \
    Header/Controlleur/controlleurchargement.h \
    Header/Controlleur/controlleurnouveau.h \
    Header/Model/model.h \
    Module/Warhammer40KV5/unitewarhammer40kv5.h \
    Module/Warhammer40KV5/unite40kv5factory.h \
    Header/Model/unitefactory.h

FORMS    += \
    Ui/nouveau.ui \
    Ui/mainwindow.ui \
    Ui/info.ui \
    Ui/export.ui \
    Ui/charger.ui \
    Ui/categorie.ui \
    Ui/affichage.ui
