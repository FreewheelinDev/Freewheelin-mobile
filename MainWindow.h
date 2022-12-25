//
// Created by pangyu on 2022/12/22.
//

#ifndef FREEWHEELIN_MOBILE_MAINWINDOW_H
#define FREEWHEELIN_MOBILE_MAINWINDOW_H

#include <QWidget>
#include <QScrollArea>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QMainWindow>

#include "TheButton.h"
#include "ThePlayer.h"

#define TOP_BAR_HEIGHT 50
#define PROGRESS_WIDGET_HEIGHT 20
#define PLAY_AREA_HEIGHT 180
#define VIDEO_LIST_WIDGET_HEIGHT 122
#define CONTROL_BAR_HEIGHT 50


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;

    QWidget *videoListWidget;

    QScrollArea *videoListWidgetScrollArea;

    QWidget *initPic;

    QLabel *initLabel;

    int lastVolume = 0;

    QPushButton *openFileButton;

    QWidget *videoListWidgetLeftWidget;

    ThePlayer *player;

    std::vector<TheButton *> outVideoList = std::vector<TheButton *>();

    std::vector<TheButton *> getVideoList(std::string loc);

    QMediaPlaylist *playlist;

    void setInitPic();

    void initSettingButton();
};



#endif //FREEWHEELIN_MOBILE_MAINWINDOW_H
