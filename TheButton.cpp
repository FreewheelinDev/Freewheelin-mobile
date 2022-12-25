
#include <QDebug>

#include "TheButton.h"

int TheButton::index = -1;  // which one is clicked, -1 means none

TheButton::TheButton(QWidget *parent, QUrl *url, QImage *icon, QLabel *title, QLabel *duration) : QWidget(parent) {

    this->url = url;
    this->icon = icon;
    this->title = title;
    // if title is too long, cut it
    if (this->title->text().length() > 15) {
        this->title->setText(this->title->text().left(15) + "...");
    }
    this->duration = duration;
    auto *imageWidget = new QWidget(this);
    auto *image = new QLabel(imageWidget);
    image->setPixmap(QPixmap::fromImage(*icon));
    image->setScaledContents(true);
    image->setFixedSize(95,53);
    imageWidget->setFixedSize(95,53);
    auto *layout = new QVBoxLayout(this);
    this->title->setStyleSheet("color: #a2a2a2;");
    layout->addWidget(this->title);
    layout->addWidget(imageWidget);
    this->duration->setStyleSheet("color: #a2a2a2;");
    layout->addWidget(this->duration);
    layout->setSpacing(0);

    // margin
    layout->setContentsMargins(0,0,0,0);


//    auto *rWidget = new QWidget(this);
//    auto *rLayout = new QVBoxLayout(rWidget);
//    rLayout->addWidget(title);
//    rLayout->addWidget(duration);
//    auto *layout = new QHBoxLayout(this);
//    layout->addWidget(imageWidget);
//    layout->addWidget(rWidget);
    this->setMinimumSize(95, 100);
    this->setMaximumSize(95, 100);
}

void TheButton::mouseReleaseEvent(QMouseEvent *event) {
    emit clicked();
}
