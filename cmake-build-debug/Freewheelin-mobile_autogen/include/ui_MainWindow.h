/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *settingButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *toolButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_9;
    QVideoWidget *playArea;
    QWidget *bottomBar;
    QVBoxLayout *verticalLayout_2;
    QWidget *progressWidget;
    QHBoxLayout *horizontalLayout_2;
    QSlider *videoProgressSlider;
    QLabel *videoProgressText;
    QWidget *controlBar;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *volumeButton;
    QSlider *volumeSlider;
    QPushButton *previousVideoButton;
    QPushButton *playVideoButton;
    QPushButton *nextVideoButton;
    QPushButton *speedButton;
    QPushButton *forwardButton;
    QWidget *blankBar;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_2;
    QWidget *workPlace;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_4;
    QLabel *label_7;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QSlider *horizontalSlider_2;
    QLabel *label_10;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_13;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_17;
    QLabel *label_14;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QLabel *label_15;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(527, 734);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topBar = new QWidget(MainWindow);
        topBar->setObjectName(QString::fromUtf8("topBar"));
        topBar->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);color:#A2A2A2"));
        horizontalLayout = new QHBoxLayout(topBar);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        settingButton = new QPushButton(topBar);
        settingButton->setObjectName(QString::fromUtf8("settingButton"));

        horizontalLayout->addWidget(settingButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QPushButton(topBar);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(toolButton);

        pushButton_2 = new QPushButton(topBar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(90, 0));
        pushButton_2->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(topBar);

        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_9 = new QVBoxLayout(widget);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        playArea = new QVideoWidget(widget);
        playArea->setObjectName(QString::fromUtf8("playArea"));

        verticalLayout_9->addWidget(playArea);


        verticalLayout->addWidget(widget);

        bottomBar = new QWidget(MainWindow);
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        bottomBar->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);color:#A2A2A2"));
        verticalLayout_2 = new QVBoxLayout(bottomBar);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        progressWidget = new QWidget(bottomBar);
        progressWidget->setObjectName(QString::fromUtf8("progressWidget"));
        horizontalLayout_2 = new QHBoxLayout(progressWidget);
#ifndef Q_OS_MAC
        horizontalLayout_2->setSpacing(-1);
#endif
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        videoProgressSlider = new QSlider(progressWidget);
        videoProgressSlider->setObjectName(QString::fromUtf8("videoProgressSlider"));
        videoProgressSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(videoProgressSlider);

        videoProgressText = new QLabel(progressWidget);
        videoProgressText->setObjectName(QString::fromUtf8("videoProgressText"));
        videoProgressText->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(videoProgressText);


        verticalLayout_2->addWidget(progressWidget);

        controlBar = new QWidget(bottomBar);
        controlBar->setObjectName(QString::fromUtf8("controlBar"));
        horizontalLayout_3 = new QHBoxLayout(controlBar);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        volumeButton = new QPushButton(controlBar);
        volumeButton->setObjectName(QString::fromUtf8("volumeButton"));

        horizontalLayout_3->addWidget(volumeButton);

        volumeSlider = new QSlider(controlBar);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeSlider);

        previousVideoButton = new QPushButton(controlBar);
        previousVideoButton->setObjectName(QString::fromUtf8("previousVideoButton"));

        horizontalLayout_3->addWidget(previousVideoButton);

        playVideoButton = new QPushButton(controlBar);
        playVideoButton->setObjectName(QString::fromUtf8("playVideoButton"));

        horizontalLayout_3->addWidget(playVideoButton);

        nextVideoButton = new QPushButton(controlBar);
        nextVideoButton->setObjectName(QString::fromUtf8("nextVideoButton"));

        horizontalLayout_3->addWidget(nextVideoButton);

        speedButton = new QPushButton(controlBar);
        speedButton->setObjectName(QString::fromUtf8("speedButton"));

        horizontalLayout_3->addWidget(speedButton);

        forwardButton = new QPushButton(controlBar);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));

        horizontalLayout_3->addWidget(forwardButton);


        verticalLayout_2->addWidget(controlBar);


        verticalLayout->addWidget(bottomBar);

        blankBar = new QWidget(MainWindow);
        blankBar->setObjectName(QString::fromUtf8("blankBar"));
        verticalLayout_8 = new QVBoxLayout(blankBar);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_2 = new QSpacerItem(20, 269, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);


        verticalLayout->addWidget(blankBar);

        workPlace = new QWidget(MainWindow);
        workPlace->setObjectName(QString::fromUtf8("workPlace"));
        workPlace->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);color:#A2A2A2"));
        verticalLayout_3 = new QVBoxLayout(workPlace);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 15, -1, 6);
        label = new QLabel(workPlace);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        widget_2 = new QWidget(workPlace);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_7 = new QHBoxLayout(widget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(3, 0, 3, 0);
        horizontalSlider = new QSlider(widget_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider);


        verticalLayout_3->addWidget(widget_2);

        label_2 = new QLabel(workPlace);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        widget_3 = new QWidget(workPlace);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_10 = new QVBoxLayout(widget_10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(-1, 3, -1, 0);
        label_3 = new QLabel(widget_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_3);

        label_6 = new QLabel(widget_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_6);


        horizontalLayout_4->addWidget(widget_10);

        widget_11 = new QWidget(widget_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        verticalLayout_11 = new QVBoxLayout(widget_11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 3, -1, 0);
        label_4 = new QLabel(widget_11);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_4);

        label_7 = new QLabel(widget_11);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_7);


        horizontalLayout_4->addWidget(widget_11);

        widget_12 = new QWidget(widget_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        verticalLayout_12 = new QVBoxLayout(widget_12);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(-1, 3, -1, 0);
        label_5 = new QLabel(widget_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_5);

        label_8 = new QLabel(widget_12);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_8);


        horizontalLayout_4->addWidget(widget_12);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(workPlace);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        horizontalSlider_2 = new QSlider(widget_4);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_2);


        verticalLayout_3->addWidget(widget_4);

        label_10 = new QLabel(workPlace);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        widget_5 = new QWidget(workPlace);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 0);
        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_7 = new QVBoxLayout(widget_9);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 10, -1, 6);
        label_11 = new QLabel(widget_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_11);

        label_12 = new QLabel(widget_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_12);


        horizontalLayout_6->addWidget(widget_9);

        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_6 = new QVBoxLayout(widget_8);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 10, -1, -1);
        label_16 = new QLabel(widget_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_16);

        label_13 = new QLabel(widget_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_13);


        horizontalLayout_6->addWidget(widget_8);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 10, -1, -1);
        label_17 = new QLabel(widget_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_17);

        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_14);


        horizontalLayout_6->addWidget(widget_6);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 10, -1, -1);
        label_18 = new QLabel(widget_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_18);

        label_15 = new QLabel(widget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_15);


        horizontalLayout_6->addWidget(widget_7);


        verticalLayout_3->addWidget(widget_5);


        verticalLayout->addWidget(workPlace);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        settingButton->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "1080P", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", " Export ", nullptr));
        videoProgressText->setText(QCoreApplication::translate("MainWindow", "00:00 / 00:00", nullptr));
        volumeButton->setText(QString());
        previousVideoButton->setText(QString());
        playVideoButton->setText(QString());
        nextVideoButton->setText(QString());
        speedButton->setText(QCoreApplication::translate("MainWindow", "1.0x", nullptr));
        forwardButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Time Line", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "VideoEffect", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Luminance", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sensation", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Range", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Warm", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Cool", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Silvertone", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Dramatic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
