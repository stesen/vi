#include <QtGui>

class QWebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url);

private:
    QWebView *view;
};
