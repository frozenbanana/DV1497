/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QSlider *horizontalSlider;
    QLabel *playingLabel;
    QLabel *trackLabel;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QLabel *valenceLabel;
    QLabel *activityLabel;
    QLabel *powerLabel;
    QSpinBox *valenceSpinBox;
    QSpinBox *activitySpinBox;
    QSpinBox *powerSpinBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSlider *verticalSlider;
    QLabel *volumeLabel;
    QSplitter *splitter;
    QLabel *genreLabel;
    QLabel *emtionLabel;
    QLabel *playlistLabel;
    QLabel *tracksLabel;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QLabel *welcomeLabel;
    QListWidget *playlistsList;
    QListWidget *trackList;
    QMenuBar *menuBar;
    QMenu *menuHenry_s_Music_Player;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(920, 367);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(480, 70, 371, 191));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 30, 231, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);
        playingLabel = new QLabel(frame);
        playingLabel->setObjectName(QStringLiteral("playingLabel"));
        playingLabel->setGeometry(QRect(30, 10, 67, 17));
        trackLabel = new QLabel(frame);
        trackLabel->setObjectName(QStringLiteral("trackLabel"));
        trackLabel->setGeometry(QRect(110, 10, 191, 17));
        backButton = new QPushButton(frame);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(20, 30, 31, 27));
        forwardButton = new QPushButton(frame);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setGeometry(QRect(300, 30, 31, 27));
        valenceLabel = new QLabel(frame);
        valenceLabel->setObjectName(QStringLiteral("valenceLabel"));
        valenceLabel->setGeometry(QRect(10, 100, 67, 17));
        activityLabel = new QLabel(frame);
        activityLabel->setObjectName(QStringLiteral("activityLabel"));
        activityLabel->setGeometry(QRect(10, 130, 67, 17));
        powerLabel = new QLabel(frame);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));
        powerLabel->setGeometry(QRect(10, 160, 67, 17));
        valenceSpinBox = new QSpinBox(frame);
        valenceSpinBox->setObjectName(QStringLiteral("valenceSpinBox"));
        valenceSpinBox->setGeometry(QRect(70, 100, 48, 27));
        activitySpinBox = new QSpinBox(frame);
        activitySpinBox->setObjectName(QStringLiteral("activitySpinBox"));
        activitySpinBox->setGeometry(QRect(70, 130, 48, 27));
        powerSpinBox = new QSpinBox(frame);
        powerSpinBox->setObjectName(QStringLiteral("powerSpinBox"));
        powerSpinBox->setGeometry(QRect(70, 160, 48, 27));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 269, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(layoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        pauseButton = new QPushButton(layoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

        verticalSlider = new QSlider(frame);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(330, 20, 29, 131));
        verticalSlider->setOrientation(Qt::Vertical);
        volumeLabel = new QLabel(frame);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        volumeLabel->setGeometry(QRect(310, 160, 67, 17));
        splitter = new QSplitter(frame);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(140, 110, 139, 34));
        splitter->setOrientation(Qt::Vertical);
        genreLabel = new QLabel(splitter);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));
        splitter->addWidget(genreLabel);
        emtionLabel = new QLabel(splitter);
        emtionLabel->setObjectName(QStringLiteral("emtionLabel"));
        splitter->addWidget(emtionLabel);
        playlistLabel = new QLabel(centralWidget);
        playlistLabel->setObjectName(QStringLiteral("playlistLabel"));
        playlistLabel->setGeometry(QRect(40, 40, 111, 16));
        tracksLabel = new QLabel(centralWidget);
        tracksLabel->setObjectName(QStringLiteral("tracksLabel"));
        tracksLabel->setGeometry(QRect(250, 40, 121, 17));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 270, 113, 27));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(370, 270, 99, 27));
        welcomeLabel = new QLabel(centralWidget);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(400, 20, 67, 17));
        playlistsList = new QListWidget(centralWidget);
        playlistsList->setObjectName(QStringLiteral("playlistsList"));
        playlistsList->setGeometry(QRect(10, 70, 211, 192));
        trackList = new QListWidget(centralWidget);
        trackList->setObjectName(QStringLiteral("trackList"));
        trackList->setGeometry(QRect(240, 70, 221, 192));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 28));
        menuHenry_s_Music_Player = new QMenu(menuBar);
        menuHenry_s_Music_Player->setObjectName(QStringLiteral("menuHenry_s_Music_Player"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHenry_s_Music_Player->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        playingLabel->setText(QApplication::translate("MainWindow", "Playing:", 0));
        trackLabel->setText(QApplication::translate("MainWindow", "nothing", 0));
        backButton->setText(QApplication::translate("MainWindow", "<", 0));
        forwardButton->setText(QApplication::translate("MainWindow", ">", 0));
        valenceLabel->setText(QApplication::translate("MainWindow", "Valence:", 0));
        activityLabel->setText(QApplication::translate("MainWindow", "Activity:", 0));
        powerLabel->setText(QApplication::translate("MainWindow", "Power:", 0));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        volumeLabel->setText(QApplication::translate("MainWindow", "Volume", 0));
        genreLabel->setText(QApplication::translate("MainWindow", "Genre: aGenre", 0));
        emtionLabel->setText(QApplication::translate("MainWindow", "Emotion: anEmotion", 0));
        playlistLabel->setText(QApplication::translate("MainWindow", "Your playlists:", 0));
        tracksLabel->setText(QApplication::translate("MainWindow", "Tracks:", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        welcomeLabel->setText(QApplication::translate("MainWindow", "Welcome ", 0));
        menuHenry_s_Music_Player->setTitle(QApplication::translate("MainWindow", "Henry's Music Player", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
