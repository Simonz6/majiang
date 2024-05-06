#include "mainwidget.h"
#include "appinit.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>

#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

    //加载样式表
    QFile file(":/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

//    a.setFont(QFont("Microsoft Yahei", 9));
    AppInit::Instance()->start();


//    LoginDialog dlg;
//    UIMainWindows w;
    //    if (dlg.exec() == QDialog::Accepted) {
    //        w.show();
    //        return a.exec();
    //    } else {
    //        return 0;
    //    }
        //dlg.show();



    LoginDialog dlg;
    UIMainWindows w;
    //临时
    w.show();

//    //登陆到主界面
//    QObject::connect(&dlg, &LoginDialog::mainwidgetShow,
//                       &w, &UIMainWindows::show);
//    //主界面到登陆
//    QObject::connect(&w, &UIMainWindows::logoutdialogShow,
//                      &dlg, &LoginDialog::show);
//    //重新加载记住的账号
//    QObject::connect(&w, &UIMainWindows::accountShow,
//                     &dlg, &LoginDialog::initUsernameList);
//    //重写播放背景音乐
//    QObject::connect(&w, &UIMainWindows::onPlayBackgroundMusic,
//                     &dlg, &LoginDialog::playBackgroundMusic);

//    dlg.exec();



//    QApplication::setQuitOnLastWindowClosed(false);
//    QApplication::setQuitOnLastWindowClosed(true);

    //废弃
//    &LoginDialog::mainwidgetShow
//    QObject::connect(&dlg, SIGNAL(mainwidgetShow()), &w, SLOT(receiverLogin()));
//    QObject::connect(&w, SIGNAL(logoutdialogShow()), &dlg, SLOT(receiverLogout()));

//   QObject::connect(dlg, &LoginDialog::mainwidgetShow, w, &UIMainWindows::receiverLogin);

    return a.exec();

}
