#include <QtGui>
#include <QtWebKit>
#include "browser.h"

#define URLADDR "http://127.0.0.1:8000"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QUrl url;
    if (argc > 1)
        url = QUrl(argv[1]);
    else
        url = QUrl(URLADDR);
    MainWindow *browser = new MainWindow(url);
    browser->show();
    return app.exec();
}

MainWindow::MainWindow(const QUrl& url)
{
    view = new QWebView(this);
    view->load(url);

    setCentralWidget(view);
}
