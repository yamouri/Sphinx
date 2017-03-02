/********************************************************************************
** Form generated from reading UI file 'SphinxClient.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHINXCLIENT_H
#define UI_SPHINXCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SphinxClient
{
public:
    QPushButton *boutonConnexion;
    QTextBrowser *messageBox;

    void setupUi(QDialog *SphinxClient)
    {
        if (SphinxClient->objectName().isEmpty())
            SphinxClient->setObjectName(QString::fromUtf8("SphinxClient"));
        SphinxClient->resize(531, 418);
        boutonConnexion = new QPushButton(SphinxClient);
        boutonConnexion->setObjectName(QString::fromUtf8("boutonConnexion"));
        boutonConnexion->setGeometry(QRect(210, 0, 99, 27));
        messageBox = new QTextBrowser(SphinxClient);
        messageBox->setObjectName(QString::fromUtf8("messageBox"));
        messageBox->setGeometry(QRect(0, 40, 531, 371));

        retranslateUi(SphinxClient);

        QMetaObject::connectSlotsByName(SphinxClient);
    } // setupUi

    void retranslateUi(QDialog *SphinxClient)
    {
        SphinxClient->setWindowTitle(QApplication::translate("SphinxClient", "SphinxClient", 0, QApplication::UnicodeUTF8));
        boutonConnexion->setText(QApplication::translate("SphinxClient", "Connexion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SphinxClient: public Ui_SphinxClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHINXCLIENT_H
