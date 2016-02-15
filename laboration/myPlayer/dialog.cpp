#include "dialog.h"
#include "ui_dialog.h"
#include <QFileInfo>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    player = new QMediaPlayer;

    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void Dialog::on_horizontalSlider_2_sliderMoved(int position)
{
    player->setVolume(position);
}

void Dialog::on_pushButton_clicked()
{
    // load the file
    player->setMedia(QUrl::fromLocalFile(QFileInfo("Trouble_on_my_mind.mp3").absoluteFilePath()));
    player->play();
    qDebug() << player->errorString();
}

void Dialog::on_pushButton_2_clicked()
{
    player->stop();
}

void Dialog::on_positionChanged(qint64 position)
{
    ui->horizontalSlider->setValue(position);
}

void Dialog::on_durationChanged(qint64 position)
{
    ui->horizontalSlider_2->setMaximum(position);
}
