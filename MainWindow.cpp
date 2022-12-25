//
// Created by pangyu on 2022/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>

#include <QDir>
#include <QDirIterator>
#include <QImageReader>
#include <QMediaPlaylist>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>
#include <QThread>

#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setWindowTitle("FreeWheelin Studio");

    // set the window size
    this->setMinimumSize(414, 736);  // 414 * 736 is the size of iPhone 8 plus
    this->setMaximumSize(428, 926);  // 428 * 926 is the size of iPhone 13 pro max

    ui->playArea->setFixedHeight(PLAY_AREA_HEIGHT);

    // initPic for welcome page
    setInitPic();

    ui->topBar->setMaximumHeight(TOP_BAR_HEIGHT);
    ui->progressWidget->setFixedHeight(PROGRESS_WIDGET_HEIGHT);
    ui->controlBar->setFixedHeight(CONTROL_BAR_HEIGHT);

    // initialize the setting button
    initSettingButton();

    // ///////////// play related buttons ///////////////

    ui->previousVideoButton->setIcon(QIcon(":/res/image/prev-video.png"));
    ui->previousVideoButton->setIconSize(QSize(12, 12));
    ui->previousVideoButton->setStyleSheet("QPushButton{border-color:none;"
                                           "border-radius: 5px; background-color:#454545;margin-right: 3px;width:36px;height:21px;}"
                                           "QPushButton:hover{border-color:none;"
                                           "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width:36px;height:21px;}");
    ui->previousVideoButton->setCursor(Qt::PointingHandCursor);

    // set the bg img for play button
    ui->playVideoButton->setIcon(QIcon(":/res/image/play.png"));
    // set the icon size
    ui->playVideoButton->setIconSize(QSize(12, 12));
    ui->playVideoButton->setStyleSheet("QPushButton{border-color:none;"
                                       "border-radius: 5px; background-color:#454545;margin-right: 3px;width:36px;height:21px;}"
                                       "QPushButton:hover{border-color:none;"
                                       "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width:36px;height:21px;}");
    ui->playVideoButton->setCursor(Qt::PointingHandCursor);

    ui->nextVideoButton->setIcon(QIcon(":/res/image/next-video.png"));
    ui->nextVideoButton->setIconSize(QSize(12, 12));
    ui->nextVideoButton->setStyleSheet("QPushButton{border-color:none;"
                                       "border-radius: 5px; background-color:#454545;margin-right: 3px;width:36px;height:21px;}"
                                       "QPushButton:hover{border-color:none;"
                                       "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width:36px;height:21px;}");
    ui->nextVideoButton->setCursor(Qt::PointingHandCursor);

    // volume button is a square
    ui->volumeButton->setIcon(QIcon(":/res/image/volume-on.png"));
    ui->volumeButton->setIconSize(QSize(12, 12));
    ui->volumeButton->setStyleSheet("QPushButton{border-color:none;"
                                    "border-radius: 5px; background-color:#454545;margin-right: 3px;width: 20px;height: 20px;}"
                                    "QPushButton:hover{border-color:none;"
                                    "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width: 20px;height: 20px;}");
    ui->volumeButton->setCursor(Qt::PointingHandCursor);

    ui->speedButton->setStyleSheet("QPushButton{"
                                   "color: #a2a2a2; border-color:none;"
                                   "border-radius: 5px; background-color:#454545;margin-right: 3px; min-width: 38px; min-height: 20px;}"
                                   "QPushButton::menu-indicator{image: none;}"
                                   "QPushButton:hover{"
                                   "color: #a2a2a2; border-color:none;"
                                   "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px; min-width: 38px; min-height: 20px;}");
    ui->speedButton->setCursor(Qt::PointingHandCursor);
    ui->forwardButton->setIcon(QIcon(":/res/image/forward.png"));
    ui->forwardButton->setIconSize(QSize(12, 12));
    ui->forwardButton->setStyleSheet("QPushButton{border-color:none;"
                                     "border-radius: 5px; background-color:#454545;margin-right: 3px;width:36px;height:21px;}"
                                     "QPushButton:hover{border-color:none;"
                                     "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width:36px;height:21px;}");
    ui->forwardButton->setIcon(QIcon(":/res/image/forward.png"));
    ui->forwardButton->setIconSize(QSize(15, 15));
    ui->forwardButton->setStyleSheet("QPushButton{border-color:none;"
                                     "border-radius: 5px; background-color:#454545;margin-right: 3px;width:36px;height:21px;}"
                                     "QPushButton:hover{border-color:none;"
                                     "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px;width:36px;height:21px;}");
    ui->forwardButton->setCursor(Qt::PointingHandCursor);
    // ///////////// play related buttons ///////////////

    ui->toolButton->setStyleSheet("QPushButton{"
                                  "color: #a2a2a2; border-color:none;"
                                  "border-radius: 5px; background-color:#454545;margin-right: 3px; min-width: 38px; min-height: 20px;}"
                                  "QPushButton::menu-indicator{image: none;}"
                                  "QPushButton:hover{"
                                  "color: #a2a2a2; border-color:none;"
                                  "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px; min-width: 38px; min-height: 20px;}");
    ui->pushButton_2->setStyleSheet("QPushButton{"
                                    "color: #a2a2a2; border-color:none;"
                                    "border-radius: 5px; background-color:#454545;margin-right: 3px; min-width: 38px; min-height: 20px;}"
                                    "QPushButton::menu-indicator{image: none;}"
                                    "QPushButton:hover{"
                                    "color: #a2a2a2; border-color:none;"
                                    "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px; min-width: 38px; min-height: 20px;}");
    ui->settingButton->setIconSize(QSize(20, 20));
    // set the icon
    ui->settingButton->setIcon(QIcon(":res/image/more.png"));
    ui->settingButton->setIconSize(QSize(20, 20));
    // set the icon
    ui->settingButton->setIcon(QIcon(":res/image/more.png"));
    // set the style
    ui->settingButton->setStyleSheet("QPushButton{"
                                     "color: #a2a2a2; border-color:none;"
                                     "border-radius: 5px; background-color:#454545;margin-right: 3px; min-width: 38px; min-height: 20px;}"
                                     "QPushButton::menu-indicator{image: none;}"
                                     "QPushButton:hover{"
                                     "color: #a2a2a2; border-color:none;"
                                     "border-radius: 5px; background-color:rgb(61, 62, 62);margin-right: 3px; min-width: 38px; min-height: 20px;}");
    // initialize the tool button
    auto *menu = new QMenu(this);
    menu->setStyleSheet("QMenu{background-color:#454545; color:#a2a2a2; border:1px solid #454545;}"
                          "QMenu::item:selected{background-color:#696969; color:#a2a2a2;}");
    menu->addAction("1080P", this, [=]() {
        ui->toolButton->setText("1080P");
    });
    menu->addAction("720P", this, [=]() {
        ui->toolButton->setText("720P");
    });
    menu->addAction("480P", this, [=]() {
        ui->toolButton->setText("480P");
    });
    menu->addAction("360P", this, [=]() {
        ui->toolButton->setText("360P");
    });
    ui->toolButton->setMenu(menu);

    // video progress slider
    ui->videoProgressSlider->setRange(0, 100);
    ui->videoProgressSlider->setValue(0);
    // Adobe PR style slider
    ui->videoProgressSlider->setStyleSheet(
            "QSlider::groove:horizontal {"
            "height: 5px;"
            "border:1px;"
            "border-radius: 6px;"
            "background: #3D3E3E;"
            "}"
            "QSlider::handle:horizontal {"
            "background:#E7E5E8;"
            "border: 1px solid #5c5c5c;"
            "width: 2px;"
            "margin-top: -18px;"
            "margin-bottom: -18px;"
            "border-radius: 1px;"

            "}"
            "QSlider::sub-page:horizontal {"
            //           more white than the groove
            "background:#565656;"
            "height: 5px;"
            "border:1px;"
            "border-radius: 6px;"
            // radius does not work
            "}"
    );

    // volume slider
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setValue(50);

    // volume slider
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setValue(50);

    // speed list
    auto *speedList = new QMenu(ui->speedButton);
//    auto *actionSpeed1 = new QAction("0.5x", this);
//    auto *actionSpeed2 = new QAction("1.0x", this);
//    auto *actionSpeed3 = new QAction("1.5x", this);
//    auto *actionSpeed4 = new QAction("2.0x", this);
    speedList->addAction("0.5x", this, [=]() {
        ui->speedButton->setText("0.5x");
        player->setPlaybackRate(0.5);
    });
    speedList->addAction("1.0x", this, [=]() {
        ui->speedButton->setText("1.0x");
        player->setPlaybackRate(1.0);
    });
    speedList->addAction("1.5x", this, [=]() {
        ui->speedButton->setText("1.5x");
        player->setPlaybackRate(1.5);
    });
    speedList->addAction("2.0x", this, [=]() {
        ui->speedButton->setText("2.0x");
        player->setPlaybackRate(2.0);
    });

    // speed button
    ui->speedButton->setCursor(Qt::PointingHandCursor);
    ui->speedButton->setMenu(speedList);

    // video progress text
    ui->videoProgressText->setText("00:00 / 00:00");

    // initialize the video list widget
    videoListWidget = new QWidget(this);
    videoListWidget->setStyleSheet("background-color: #1D1D1D;");
    videoListWidget->setGeometry(0, TOP_BAR_HEIGHT + ui->playArea->height() + PROGRESS_WIDGET_HEIGHT + CONTROL_BAR_HEIGHT, this->width(), VIDEO_LIST_WIDGET_HEIGHT);
    // add a widget to left side of the video list widget
    videoListWidgetLeftWidget = new QWidget(videoListWidget);
    videoListWidgetLeftWidget->setStyleSheet("background-color: #232323;");
    videoListWidgetLeftWidget->setGeometry(0, 0, 40, videoListWidget->height());
    // add 3 buttons to the left widget vertically
    auto *cycleVideoButton = new QPushButton(videoListWidgetLeftWidget);
    cycleVideoButton->setGeometry(10, 15, 20, 20);
    // set icon
    cycleVideoButton->setIcon(QIcon(":/res/image/cycle.png"));
    cycleVideoButton->setIconSize(QSize(14, 14));
    cycleVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                    "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px; background-color: #565656;}"
                                    "QPushButton:hover{background-color:#565656;}"
                                    "QPushButton:pressed{background-color:#454545;}");
    auto *randomVideoButton = new QPushButton(videoListWidgetLeftWidget);
    randomVideoButton->setGeometry(10, 52, 20, 20);
    // set the icon and style
    randomVideoButton->setIcon(QIcon(":/res/image/shuffle.png"));
    randomVideoButton->setIconSize(QSize(14, 14));

    randomVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                     "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px;}"
                                     "QPushButton:hover{background-color:#565656;}"
                                     "QPushButton:pressed{background-color:#454545;}");
    auto *clearAllButton = new QPushButton(videoListWidgetLeftWidget);
    clearAllButton->setGeometry(10, 89, 20, 20);
    clearAllButton->setIcon(QIcon(":/res/image/clear-list.png"));
    clearAllButton->setIconSize(QSize(14, 14));
    // the icon initally is just with icon,
    // hovering or press will show a bg color
    clearAllButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                  "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px;}"
                                  "QPushButton:hover{background-color:#565656;}"
                                  "QPushButton:pressed{background-color:#454545;}");
    // add a scroll area to the right side of the video list widget
    videoListWidgetScrollArea = new QScrollArea(videoListWidget);
    videoListWidgetScrollArea->setStyleSheet("background-color: #1D1D1D;");
    videoListWidgetScrollArea->setGeometry(40, 0, videoListWidget->width()-40, videoListWidget->height());

    // init the player
    player = new ThePlayer;
    player->setParent(ui->playArea);
    player->mTimer = new QTimer(this);
    player->mTimer->setInterval(100);
    player->mTimer->start();
    connect(player->mTimer, &QTimer::timeout, this, [=](){
        if (player->state() == QMediaPlayer::PlayingState) {
            ui->videoProgressSlider->setValue(player->position()*100/player->duration());
        }
    });
    player->setVideoOutput(ui->playArea);

    playlist = new QMediaPlaylist(player);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    // random play
    connect(randomVideoButton, &QPushButton::clicked, this, [=]() {
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        cycleVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                        "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px;}"
                                        "QPushButton:hover{background-color:#565656;}"
                                        "QPushButton:pressed{background-color:#454545;}");
        randomVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                         "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px; background-color: #565656;}"
                                         "QPushButton:hover{background-color:#565656;}"
                                         "QPushButton:pressed{background-color:#454545;}");
    });
    // cycle play
    connect(cycleVideoButton, &QPushButton::clicked, this, [=]() {
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        cycleVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                        "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px; background-color: #565656;}"
                                        "QPushButton:hover{background-color:#565656;}"
                                        "QPushButton:pressed{background-color:#454545;}");
        randomVideoButton->setStyleSheet("QPushButton{border-style:solid; border-width:1px; border-color:none;"
                                         "border-radius: 5px; ;margin-right: 3px;width: 30 px;height: 30px;}"
                                         "QPushButton:hover{background-color:#565656;}"
                                         "QPushButton:pressed{background-color:#454545;}");
    });

    // set the text of the progress label when the video is playing
    // format: mm:ss / mm:ss
    connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
        ui->videoProgressText->setText(QString("%1 / %2").arg(
                QTime(0, 0, 0).addMSecs(position).toString("mm:ss"),
                QTime(0, 0, 0).addMSecs(player->duration()).toString("mm:ss")
        ));
    });

    // set the initial volume
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setMaximumWidth(120);
    ui->volumeSlider->setValue(50);
    ui->volumeSlider->setFixedWidth(60);
    // set the style sheet of volume slider with macOS style
    ui->volumeSlider->setStyleSheet(
            "QSlider::groove:horizontal {"
            "height: 6px;"
            "border:1px;"
            "border-radius: 2px;"
            "background: #3D3E3E;"
            "}"
            "QSlider::handle:horizontal {"
            "background:#E7E5E8;"

            "width: 2px;"
            "height: 13px;"
            "margin-top: -18px;"
            "margin-bottom: -18px;"
            "border-radius: 6px;"
            "}"
            "QSlider::sub-page:horizontal {"
            "background:#565656;"
            "height: 6px;"
            "border: 1px;"
            "border-radius: 2px;"
            "}"
    );
    player->setVolume(ui->volumeSlider->value());

    // the style of slider in the work space
    ui->horizontalSlider->setStyleSheet(
            "QSlider::groove:horizontal {"
            "height: 3px;"
            "border:1px;"
            "border-radius: 5px;"
            "background: #3D3E3E;"
            "}"
            "QSlider::handle:horizontal {"
            "background:#E7E5E8;"
            "border: 1px solid #5c5c5c;"
            "width: 2px;"
            "margin-top: -5px;"
            "margin-bottom: -5px;"
            "border-radius: 5px;"
            "}"
            "QSlider::sub-page:horizontal {"
            "background:rgb(175, 177, 179);"
            "height: 3px;"
            "border:1px;"
            "border-radius: 5px;"
            "}"
    );
    ui->horizontalSlider_2->setStyleSheet(
            "QSlider::groove:horizontal {"
            "height: 3px;"
            "border:1px;"
            "border-radius: 5px;"
            "background: #3D3E3E;"
            "}"
            "QSlider::handle:horizontal {"
            "background:#E7E5E8;"
            "border: 1px solid #5c5c5c;"
            "width: 2px;"
            "margin-top: -5px;"
            "margin-bottom: -5px;"
            "border-radius: 5px;"
            "}"
            "QSlider::sub-page:horizontal {"
            "background:rgb(175, 177, 179);"
            "height: 3px;"
            "border:1px;"
            "border-radius: 5px;"
            "}"
    );

    // when the volume button is clicked, the volume will be muted
    connect(ui->volumeButton, &QPushButton::clicked, this, [=]() {
        if (player->isMuted()) {
            player->setMuted(false);
            ui->volumeButton->setIcon(QIcon(":/res/image/volume-on.png"));
            ui->volumeSlider->setValue(lastVolume);
        } else {
            lastVolume = ui->volumeSlider->value();
            player->setMuted(true);
            ui->volumeButton->setIcon(QIcon(":/res/image/volume-off.png"));
            ui->volumeSlider->setValue(0);
        }
    });

    // set the volume of the video
    connect(ui->volumeSlider, &QSlider::valueChanged, this, [=](int value) {
        player->setVolume(value);
        if (value == 0) {
            ui->volumeButton->setIcon(QIcon(":/res/image/volume-off.png"));
        } else {
            ui->volumeButton->setIcon(QIcon(":/res/image/volume-on.png"));
        }
    });

    // the fileDialog
    auto *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setOption(QFileDialog::ShowDirsOnly);

    auto *videoListScrollAreaWidget = new QWidget(videoListWidgetScrollArea);
    videoListScrollAreaWidget->setStyleSheet("background-color: rgb(29, 29, 29);");
    auto *videoButtonsLayout = new QHBoxLayout(videoListScrollAreaWidget);
    videoListScrollAreaWidget->setLayout(videoButtonsLayout);
    videoListScrollAreaWidget->setFixedHeight(120);
    videoListWidgetScrollArea->setWidget(videoListScrollAreaWidget);

    // clear widget in the scroll area widget
    QLayoutItem *child;
    while ((child = videoButtonsLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    videoListScrollAreaWidget->setMinimumWidth(0);
    videoListScrollAreaWidget->setMaximumWidth(0);

    // set the style of the scroll bar invisible
    videoListWidgetScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    videoListWidgetScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set the style of the openFileButton
    openFileButton->setStyleSheet("QPushButton{"
                                  "border: none; background-color: #1373E6; color: white; height: 30px; border-radius: 5px;"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-color: #0F66d0;"
                                  "}");

    // open folder button clicked
    connect(openFileButton, &QPushButton::clicked, this, [=]() {
        if (fileDialog->exec()) {
            player->setVideoOutput(ui->playArea);
            QString path = fileDialog->selectedFiles()[0];
            string pathString = path.toStdString();
            cout << pathString << endl;
            outVideoList = getVideoList(pathString);
            vector<QUrl*> outVideoUrlList;
            for (auto &i : outVideoList) {
                outVideoUrlList.push_back(i->url);
            }
            playlist->clear();
            for (auto &i : outVideoUrlList) {
                playlist->addMedia(*i);
            }
            // cout the playlist
            player->setPlaylist(playlist);
//            playlist->setCurrentIndex(0);

            for (int i = 0; i < outVideoList.size(); i++) {
                videoButtonsLayout->addWidget(outVideoList[i]);
                connect(outVideoList[i], &TheButton::clicked, this, [=]() {
                    playlist->setCurrentIndex(i);
                    player->play();
                    QTimer::singleShot(70, this, [=]() {
                        player->play();
                    });
                    TheButton::index = playlist->currentIndex();
                    QThread::msleep(50);
                    // hide the initPic
                    this->initPic->hide();
                });
                videoListScrollAreaWidget->setMinimumWidth(111 * (i + 1));
                videoListScrollAreaWidget->setMaximumWidth(111 * (i + 1));
            }

            QTimer::singleShot(70, this, [=]() {
                player->play();
                ui->playVideoButton->setIcon(QIcon(":/res/image/pause.png"));
            });

            // show the video list
            videoListWidget->show();
        }
    });

    // clear video list button clicked
    connect(clearAllButton, &QPushButton::clicked, this, [=]() {
        if (outVideoList.empty()) {
            auto *msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("background-color:#232323; color: #A2A2A2;");
            msgBox->setText("No video in the list");
            msgBox->setWindowTitle("Tip");
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->exec();

            return;
        }


        // a model dialog to ensure the user's operation
        QMessageBox::StandardButton reply;
        auto *messageBox = new QMessageBox(this);
        messageBox->setStyleSheet("background-color:#232323; color: #A2A2A2;");
        messageBox->setWindowTitle("Clear Video List");
        messageBox->setText("Are you sure to clear the video list?");
        messageBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageBox->setDefaultButton(QMessageBox::No);
        // set style of the button
        messageBox->button(QMessageBox::Yes)->setStyleSheet("background-color:#616161;"
                                                            "border-radius:5px;"
                                                            "color:#DDDDDD;"
                                                            "width:68px;"
                                                            "height:17px;"
                                                            "}"
                                                            "QPushButton:hover{"
                                                            "background-color: rgb(61, 62, 62);"
                                                            "border-radius:5px;"
                                                            "color:#DDDDDD;"
                                                            "width:68px;"
                                                            "height:17px;"
        );
        messageBox->button(QMessageBox::No)->setStyleSheet("background-color:#1373E6;"
                                                           "border-radius:5px;"
                                                           "color:white;"
                                                           "width:68px;"
                                                           "height:17px;"
                                                           "}"
                                                           "QPushButton:hover{"
                                                           "background-color:#0F66d0;"
                                                           "border-radius:5px;"
                                                           "color:#DDDDDD;"
                                                           "width:68px;"
                                                           "height:17px;");
        reply = static_cast<QMessageBox::StandardButton>(messageBox->exec());
        if (reply == QMessageBox::Yes) {
            playlist->clear();
            outVideoList.clear();
            // clear widget in the scroll area widget
            QLayoutItem *child;
            while ((child = videoButtonsLayout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }
            videoListScrollAreaWidget->setMinimumWidth(0);
            videoListScrollAreaWidget->setMaximumWidth(0);
            TheButton::index = -1;

            // show the initPic
            this->initPic->show();

            // set the video progress bar to 0
            ui->videoProgressSlider->setValue(0);

            // set the video progress text to 00:00 / 00:00
            ui->videoProgressText->setText(QString("00:00 / 00:00"));
        } else {
            return;
        }
    });

    // when the pause button is clicked, the video will be paused
    connect(ui->playVideoButton, &QPushButton::clicked, this, [=]() {
        if (player->state() == QMediaPlayer::PlayingState) {
            player->pause();
            ui->playVideoButton->setIcon(QIcon(":/res/image/play.png"));
        } else {
            // if has no video in the list, show a message box
            if (outVideoList.empty()) {
                return;
            }
            if (playlist->currentIndex() == -1) {
                playlist->setCurrentIndex(0);
            }
            this->initPic->hide();
            player->play();
            ui->playVideoButton->setIcon(QIcon(":/res/image/pause.png"));
        }
    });

    // if the video is playing, the pause icon will be shown
    connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state) {
        if (state == QMediaPlayer::PlayingState) {
            ui->playVideoButton->setIcon(QIcon(":/res/image/pause.png"));
        } else {
            ui->playVideoButton->setIcon(QIcon(":/res/image/play.png"));
        }
    });

    // once the TheButton::index is changed, the video will be played
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, [=](int index) {
        if (index != -1) {
            this->initPic->hide();
        }
        if (TheButton::index != -1 && TheButton::index != index) {
            outVideoList[TheButton::index]->title->setStyleSheet("background-color: rgb(29, 29, 29); color: #a2a2a2;");
            outVideoList[TheButton::index]->duration->setStyleSheet("background-color: rgb(29, 29, 29); color: #a2a2a2;");
        }
        TheButton::index = index;
        outVideoList[index]->duration->setStyleSheet("background-color: rgb(69, 69, 69); color: #a2a2a2; border-bottom-left-radius: 5px; border-bottom-right-radius: 5px;");
        outVideoList[index]->title->setStyleSheet("background-color: rgb(69, 69, 69); color: #a2a2a2; border-top-left-radius: 5px; border-top-right-radius: 5px;");
    });

    // next video button clicked
    connect(ui->nextVideoButton, &QPushButton::clicked, this, [=]() {
        playlist->next();
        player->stop();
        // wait for the resource to be released
        QTimer::singleShot(70, this, [=]() {
            player->play();
        });
        TheButton::index = playlist->currentIndex();
        // disable the bottom bar
        ui->bottomBar->setEnabled(false);
        QTimer::singleShot(70, this, [=]() {
            ui->bottomBar->setEnabled(true);
        });
    });

    // previous video button clicked
    connect(ui->previousVideoButton, &QPushButton::clicked, this, [=]() {
        playlist->previous();
        player->stop();
        QTimer::singleShot(70, this, [=]() {
            player->play();
        });
        TheButton::index = playlist->currentIndex();
        // disable the bottom bar
        ui->bottomBar->setEnabled(false);
        QTimer::singleShot(70, this, [=]() {
            ui->bottomBar->setEnabled(true);
        });
    });

    connect(ui->videoProgressSlider, &QSlider::valueChanged, this, [=](float value) {
        if (value > 98.5) {
            playlist->next();
            player->stop();

            QTimer::singleShot(70, this, [=](){
                player->play();
            });
        }
    });

    // when the video progress slider is moved, the video will be moved to the position
    connect(ui->videoProgressSlider, &QSlider::sliderMoved, this, [=](int value) {
        player->mTimer->stop();
        player->setPosition(ui->videoProgressSlider->value()*player->duration()/100);
    });
    connect(ui->videoProgressSlider, &QSlider::sliderReleased, this, [=]() {
        player->mTimer->start();
    });
    connect(ui->videoProgressSlider, &QSlider::sliderPressed, this, [=]() {
        player->setPosition(ui->videoProgressSlider->value()*player->duration()/100);
    });

    // forward 15 seconds button clicked
    connect(ui->forwardButton, &QPushButton::clicked, this, [=]() {
        player->setPosition(player->position() + 15000);
    });


    // picture of label
    QPixmap pixmap(":/res/image/warm.png");
    QPixmap fitpixmap = pixmap.scaled(80, 53, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap finalPixmap(80, 53);
    finalPixmap.fill(Qt::transparent);
    QPainter painter(&finalPixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawPixmap(0, 0, 80, 53, fitpixmap);
    ui->label_11->setPixmap(finalPixmap);

    // picture of label
    QPixmap pixmap2(":/res/image/cool.png");
    QPixmap fitpixmap2 = pixmap2.scaled(80, 53, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap finalPixmap2(80, 53);
    finalPixmap2.fill(Qt::transparent);
    QPainter painter2(&finalPixmap2);
    painter2.setRenderHint(QPainter::Antialiasing);
    painter2.setRenderHint(QPainter::SmoothPixmapTransform);
    painter2.drawPixmap(0, 0, 80, 53, fitpixmap2);
    ui->label_16->setPixmap(finalPixmap2);

    // picture of label
    QPixmap pixmap3(":/res/image/silvertone.png");
    QPixmap fitpixmap3 = pixmap3.scaled(80, 53, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap finalPixmap3(80, 53);
    finalPixmap3.fill(Qt::transparent);
    QPainter painter3(&finalPixmap3);
    painter3.setRenderHint(QPainter::Antialiasing);
    painter3.setRenderHint(QPainter::SmoothPixmapTransform);
    painter3.drawPixmap(0, 0, 80, 53, fitpixmap3);
    ui->label_17->setPixmap(finalPixmap3);

    // picture of label
    QPixmap pixmap4(":/res/image/dramatic.png");
    QPixmap fitpixmap4 = pixmap4.scaled(80, 53, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap finalPixmap4(80, 53);
    finalPixmap4.fill(Qt::transparent);
    QPainter painter4(&finalPixmap4);
    painter4.setRenderHint(QPainter::Antialiasing);
    painter4.setRenderHint(QPainter::SmoothPixmapTransform);
    painter4.drawPixmap(0, 0, 80, 53, fitpixmap4);
    ui->label_18->setPixmap(finalPixmap4);

    // picture of label
    QPixmap pixmap5(":/res/image/test.png");
    QPixmap fitpixmap5 = pixmap5.scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap finalPixmap5(60, 60);
    finalPixmap5.fill(Qt::transparent);
    QPainter painter5(&finalPixmap5);
    painter5.setRenderHint(QPainter::Antialiasing);
    painter5.setRenderHint(QPainter::SmoothPixmapTransform);
    painter5.drawPixmap(0, 0, 60, 60, fitpixmap5);
    ui->label_3->setPixmap(finalPixmap5);
    ui->label_4->setPixmap(finalPixmap5);
    ui->label_5->setPixmap(finalPixmap5);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    int heightIncrement = this->height() - 736;
    // resize the play area
    ui->playArea->setFixedHeight(PLAY_AREA_HEIGHT + heightIncrement);
    this->videoListWidget->setGeometry(0, TOP_BAR_HEIGHT + ui->playArea->height() + PROGRESS_WIDGET_HEIGHT + CONTROL_BAR_HEIGHT, this->width(), VIDEO_LIST_WIDGET_HEIGHT);
    initPic->setGeometry(0, TOP_BAR_HEIGHT - 6, this->width(), ui->playArea->height());
    initLabel->setGeometry(initPic->width() / 2 - 200, initPic->height() / 2 - 200 - 15, 400, 400);
    openFileButton->setGeometry(initPic->width() / 2 - 60, initPic->height() / 2 + 45, 120, 25);
}

void MainWindow::setInitPic() {
    // set the initial picture when the program starts
    initPic = new QWidget(this);
    initPic->setStyleSheet("background-color: rgb(26, 26, 26);");
    initLabel = new QLabel(initPic);
    initLabel->setPixmap(QPixmap(":/res/image/banner-area.png"));
    openFileButton = new QPushButton(initPic);
    openFileButton->setText("Open File");
    openFileButton->setCursor(Qt::PointingHandCursor);
    initLabel->setScaledContents(true);
    initPic->setGeometry(0, TOP_BAR_HEIGHT - 6, this->width(), ui->playArea->height());
    initLabel->setGeometry(initPic->width() / 2 - 200, initPic->height() / 2 - 200 - 15, 400, 400);
    openFileButton->setGeometry(initPic->width() / 2 - 60, initPic->height() / 2 + 45, 120, 25);
}

void MainWindow::initSettingButton() {
    ui->settingButton->setCursor(Qt::PointingHandCursor);
    ui->settingButton->setToolTip("Settings");
    ui->settingButton->setToolTipDuration(1000);
    // menu list
    auto *menu = new QMenu(ui->settingButton);
    menu->setStyleSheet("QMenu{background-color:#454545; color:#a2a2a2; border:1px solid #454545;}"
                        "QMenu::item:selected{background-color:#696969; color:#a2a2a2;}");
    auto *languageMenu = new QMenu("Set Language", menu);
    languageMenu->addAction("English(US)");
    languageMenu->addSeparator();
    languageMenu->addAction("English(UK)");
    languageMenu->addSeparator();
    languageMenu->addAction("Chinese(Simplified)");
    languageMenu->addSeparator();
    languageMenu->addAction("Chinese(Traditional)");
    languageMenu->addSeparator();
    languageMenu->addAction("Japanese");
    languageMenu->addSeparator();
    languageMenu->addAction("French");
    languageMenu->addSeparator();
    auto *moreOptionMenu = new QMenu("More Options", menu);
    languageMenu->addMenu(moreOptionMenu);
    menu->addMenu(languageMenu);
    menu->addSeparator();
    auto *subTitlesMenu = new QMenu("Add Subtitles", menu);
    subTitlesMenu->addAction("Add Subtitle File...");
    subTitlesMenu->addSeparator();
    auto *textSizeMenu = new QMenu("Text Size", subTitlesMenu);
    textSizeMenu->addAction("Smaller");
    textSizeMenu->addSeparator();
    textSizeMenu->addAction("Small");
    textSizeMenu->addSeparator();
    textSizeMenu->addAction("Normal");
    textSizeMenu->addSeparator();
    textSizeMenu->addAction("Large");
    textSizeMenu->addSeparator();
    textSizeMenu->addAction("Larger");
    subTitlesMenu->addMenu(textSizeMenu);
    subTitlesMenu->addSeparator();
    auto *textColorMenu = new QMenu("Text Color", subTitlesMenu);
    textColorMenu->addAction("Black");
    textColorMenu->addSeparator();
    textColorMenu->addAction("Gray");
    textColorMenu->addSeparator();
    textColorMenu->addAction("Silver");
    textColorMenu->addSeparator();
    textColorMenu->addAction("White");
    textColorMenu->addSeparator();
    textColorMenu->addAction("Maroon");
    textColorMenu->addSeparator();
    textColorMenu->addAction("Red");
    subTitlesMenu->addMenu(textColorMenu);
    subTitlesMenu->addSeparator();
    auto *outlineThicknessMenu = new QMenu("Outline Thickness", subTitlesMenu);
    outlineThicknessMenu->addAction("None");
    outlineThicknessMenu->addSeparator();
    outlineThicknessMenu->addAction("Thin");
    outlineThicknessMenu->addSeparator();
    outlineThicknessMenu->addAction("Normal");
    outlineThicknessMenu->addSeparator();
    outlineThicknessMenu->addAction("Thick");
    subTitlesMenu->addMenu(outlineThicknessMenu);
    subTitlesMenu->addSeparator();
    auto *backgroundColorMenu = new QMenu("Background Color", subTitlesMenu);
    backgroundColorMenu->addAction("Black");
    backgroundColorMenu->addSeparator();
    backgroundColorMenu->addAction("Gray");
    backgroundColorMenu->addSeparator();
    backgroundColorMenu->addAction("Silver");
    backgroundColorMenu->addSeparator();
    backgroundColorMenu->addAction("White");
    backgroundColorMenu->addSeparator();
    backgroundColorMenu->addAction("Maroon");
    backgroundColorMenu->addSeparator();
    backgroundColorMenu->addAction("Red");
    subTitlesMenu->addMenu(backgroundColorMenu);
    menu->addMenu(subTitlesMenu);

    menu->addSeparator();
    auto *colorEnhancementMenu = new QMenu("Color Enhancement", menu);
    colorEnhancementMenu->addAction("Increase Contrast");
    colorEnhancementMenu->addSeparator();
    colorEnhancementMenu->addAction("Differentiate Without Color");
    colorEnhancementMenu->addSeparator();
    colorEnhancementMenu->addAction("Classic Invert");
    colorEnhancementMenu->addSeparator();
    colorEnhancementMenu->addAction("Reduce White Point");
    colorEnhancementMenu->addSeparator();
    auto *colorFiltersMenu = new QMenu("Color Filters", colorEnhancementMenu);
    colorFiltersMenu->addAction("Red/Green Filter");
    colorFiltersMenu->addSeparator();
    colorFiltersMenu->addAction("Green/Red Filter");
    colorFiltersMenu->addSeparator();
    colorFiltersMenu->addAction("Blue/Yellow Filter");
    colorFiltersMenu->addSeparator();
    colorEnhancementMenu->addMenu(colorFiltersMenu);
    menu->addMenu(colorEnhancementMenu);
    menu->addSeparator();
    auto *dictationMenu = new QMenu("Dictation", menu);
    dictationMenu->addAction("Live Caption");
    dictationMenu->addSeparator();
    dictationMenu->addAction("Mono Audio");
    dictationMenu->addSeparator();
    dictationMenu->addAction("Hearing Aid Compatibility");
    menu->addMenu(dictationMenu);
    menu->addSeparator();
    menu->addAction("Search");
    ui->settingButton->setMenu(menu);
}

std::vector<TheButton*> MainWindow::getVideoList (std::string loc) {
//    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    auto *out = new std::vector<TheButton*>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

        if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

                QString thumb = f.left( f .length() - 4) +".png";
                if (QFile(thumb).exists()) { // if a png thumbnail exists
                    auto *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QUrl* iconUrl = new QUrl(thumb);
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        // get the title of the video
                        QString title = f.mid(f.lastIndexOf('/') + 1);
                        title = title.left(title.length());
                        auto* label = new QLabel(title);
                        // get the duration of the video
                        auto* playerTmp = new QMediaPlayer();
                        playerTmp->setMedia(*url);
                        playerTmp->play();
                        // wait for the video to load
                        while (playerTmp->duration() == 0) {
                            QCoreApplication::processEvents();
                        }
                        playerTmp->pause();
                        QString duration = QTime(0, 0, 0).addMSecs(playerTmp->duration()).toString("mm:ss");
                        auto* durationLabel = new QLabel(duration);
                        out->push_back(new TheButton(videoListWidgetScrollArea, url, &sprite, label, durationLabel));

                        delete playerTmp;
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
                }
                else
                    qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
            }
    }

    return *out;
}
