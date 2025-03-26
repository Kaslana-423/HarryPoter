#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>//窗口类头文件
#include<vector>
#include<string>

QT_BEGIN_NAMESPACE
namespace Ui {
class myWidget;
}
QT_END_NAMESPACE

class myWidget : public QMainWindow
{
    Q_OBJECT//允许类使用信号和槽

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private slots:
    void on_btnOpenFile_clicked();

    void on_btnSearch_clicked();


    void on_tableWidgetResults_cellClicked(int row, int column);

private:
    Ui::myWidget *ui;
    std::vector<int> result_;
    std::vector<std::string> lines;
    QString chapterStr;
    QString paragraphStr;
    QString para;
    QString filename;
    QStringList headers;
    QString bookTitle;
    QString defaultPath;
};
#endif // MYWIDGET_H
