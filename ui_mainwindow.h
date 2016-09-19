/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *bStart;
    QPushButton *bPause;
    QPushButton *bStop;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *eProcCount;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *ePageCount;
    QProgressBar *progressBar;
    QLabel *label_8;
    QLabel *label_7;
    QTableView *tFoundURLs;
    QTextEdit *eURL;
    QTextEdit *eText;
    QLabel *label_2;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("View"));
        View->resize(675, 524);
        View->setMinimumSize(QSize(675, 524));
        View->setMaximumSize(QSize(675, 524));
        QFont font;
        font.setUnderline(true);
        View->setFont(font);
        centralWidget = new QWidget(View);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(210, 250, 247, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bStart = new QPushButton(horizontalLayoutWidget);
        bStart->setObjectName(QStringLiteral("bStart"));
        bStart->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/data/res/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        bStart->setIcon(icon);

        horizontalLayout->addWidget(bStart);

        bPause = new QPushButton(horizontalLayoutWidget);
        bPause->setObjectName(QStringLiteral("bPause"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/data/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPause->setIcon(icon1);

        horizontalLayout->addWidget(bPause);

        bStop = new QPushButton(horizontalLayoutWidget);
        bStop->setObjectName(QStringLiteral("bStop"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/data/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        bStop->setIcon(icon2);

        horizontalLayout->addWidget(bStop);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(170, 200, 111, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        font1.setUnderline(false);
        label_5->setFont(font1);

        horizontalLayout_3->addWidget(label_5);

        eProcCount = new QLineEdit(horizontalLayoutWidget_2);
        eProcCount->setObjectName(QStringLiteral("eProcCount"));
        QFont font2;
        font2.setUnderline(false);
        eProcCount->setFont(font2);
        eProcCount->setInputMethodHints(Qt::ImhPreferNumbers);
        eProcCount->setMaxLength(100);

        horizontalLayout_3->addWidget(eProcCount);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(400, 200, 120, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_4->addWidget(label_6);

        ePageCount = new QLineEdit(horizontalLayoutWidget_3);
        ePageCount->setObjectName(QStringLiteral("ePageCount"));
        ePageCount->setFont(font2);
        ePageCount->setInputMethodHints(Qt::ImhPreferNumbers);
        ePageCount->setMaxLength(100);

        horizontalLayout_4->addWidget(ePageCount);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 460, 651, 20));
        progressBar->setFont(font2);
        progressBar->setValue(24);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 350, 131, 91));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/data/res/Developex.jpg")));
        label_8->setScaledContents(true);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 20, 141, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Book Antiqua"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(75);
        label_7->setFont(font3);
        tFoundURLs = new QTableView(centralWidget);
        tFoundURLs->setObjectName(QStringLiteral("tFoundURLs"));
        tFoundURLs->setGeometry(QRect(10, 321, 511, 121));
        eURL = new QTextEdit(centralWidget);
        eURL->setObjectName(QStringLiteral("eURL"));
        eURL->setGeometry(QRect(110, 80, 511, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(11);
        font4.setUnderline(false);
        eURL->setFont(font4);
        eText = new QTextEdit(centralWidget);
        eText->setObjectName(QStringLiteral("eText"));
        eText->setEnabled(true);
        eText->setGeometry(QRect(110, 140, 511, 31));
        eText->setFont(font4);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 140, 31, 31));
        label_2->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 51, 31));
        label->setFont(font1);
        View->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(View);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        View->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(View);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        View->setStatusBar(statusBar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QApplication::translate("View", "Find text on WEB", 0));
        bStart->setText(QString());
        bPause->setText(QString());
        bStop->setText(QString());
        label_5->setText(QApplication::translate("View", "N(Proc)", 0));
        label_6->setText(QApplication::translate("View", "N(Pages)", 0));
        label_8->setText(QString());
        label_7->setText(QApplication::translate("View", "TextFinder", 0));
        label_2->setText(QApplication::translate("View", "Text ", 0));
        label->setText(QApplication::translate("View", "URL ", 0));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
