#include "mywidget.h"
#include "ui_mywidget.h"
#include"QFileDialog"
#include"QString"
#include"QIODevice"
#include"QFile"
#include"QDebug"
#include<cctype>
#include"search.h"
#include"iostream"
#include<fstream>
using namespace std;
myWidget::myWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::on_btnOpenFile_clicked()
{
    defaultPath = QCoreApplication::applicationDirPath() + "/../../";
    ui->lePattern->setPlaceholderText("请输入目标单词");
    lines.clear();
    filename = QFileDialog::getOpenFileName(this, tr("打开文件"),defaultPath,tr("文本文件 (*.txt)"));

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        ui->tbLog->append("无法打开文件！");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line =in.readLine();
        lines.push_back(line.toStdString());
    }

    ui->tbLog->append("文件打开完毕");
}
int trans(const string& s) {
    // 预处理：转小写，替换连字符为空格
    string input = s;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    replace(input.begin(), input.end(), '-', ' ');
    // 创建映射表（合并个位和十位）
    const unordered_map<string, int> word_map = {
        {"zero",0}, {"one",1}, {"two",2}, {"three",3}, {"four",4},
        {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9},
        {"ten",10}, {"eleven",11}, {"twelve",12}, {"thirteen",13},
        {"fourteen",14}, {"fifteen",15}, {"sixteen",16}, {"seventeen",17},
        {"eighteen",18}, {"nineteen",19}, {"twenty",20}, {"thirty",30},
        {"forty",40}, {"fifty",50}, {"sixty",60}, {"seventy",70},
        {"eighty",80}, {"ninety",90}
    };

    // 分割单词
    istringstream iss(input);
    string word;
    int result = 0;

    while (iss >> word) {
        auto it = word_map.find(word);
        if (it != word_map.end()) {
            result += it->second;
        }
    }
    return result;
}
bool isNumber(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}


void myWidget::on_btnSearch_clicked()
{

    ui->lePattern->setPlaceholderText("请输入目标单词");
    std::string P=ui->lePattern->text().toStdString();
    headers << "人名/地名" << "页码" << "章节" << "书名"<<"内容";
    ui->tableWidgetResults->setColumnCount(headers.size());
    ui->tableWidgetResults->setHorizontalHeaderLabels(headers);
    ui->tableWidgetResults->clearContents();
    ui->tableWidgetResults->setRowCount(0);
    ui->tableWidgetResults->setColumnCount(5);
    ui->tableWidgetResults->setColumnWidth(0, 80);
    ui->tableWidgetResults->setColumnWidth(1, 80);
    ui->tableWidgetResults->setColumnWidth(2, 50);
    ui->tableWidgetResults->setColumnWidth(3, 380);
    ui->tableWidgetResults->setColumnWidth(4, 50);

    for (int i = 0; i < lines.size(); i++) {
        istringstream iss(lines[i]);
        string word;
        ui->tableWidgetResults->setVisible(true);

        while (iss >> word) {
            string fw;
            int chapter;
            if (word == "Chapter" || word == "CHAPTER") {
                iss >> word;
                chapter = trans(word);
                chapterStr = QString("第%1章").arg(chapter);
            }
            else if (word == "foreword") {
                fw = word;
            }
            else {
                fw = "?";
            }

            if (word == P) {
                int paraNumber = 1;
                for (int j = i; j < lines.size(); j++) {
                    if (lines[j].size() <= 4 && !lines[j].empty() && isNumber(lines[j])) {
                        try {
                            paraNumber = std::stoi(lines[j]);  // 转换字符串为数字
                            para = QString("第 %1 页").arg(paraNumber);
                        } catch (const std::exception &e) {
                            qDebug() << "转换页码时出错:" << e.what();
                            para = "未知页码";
                        }
                        break;  // 找到后立即退出循环
                    }
                }

                // 插入一条结果到表格中
                int row = ui->tableWidgetResults->rowCount();
                ui->tableWidgetResults->insertRow(row);
                // 设置章节、段落、行信息
                ui->tableWidgetResults->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(P)));
                ui->tableWidgetResults->setItem(row, 2, new QTableWidgetItem(chapterStr));
                ui->tableWidgetResults->setItem(row, 1, new QTableWidgetItem(para));
                ui->tableWidgetResults->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(lines[i])));
                if (!filename.isEmpty()) {
                    QFileInfo fileInfo(filename);
                    QString bookTitle = fileInfo.fileName();  // 获取完整文件名（含扩展名）
                    bookTitle.chop(fileInfo.suffix().length() + 1); // 去除扩展名
                    ui->tableWidgetResults->setItem(row, 3, new QTableWidgetItem(bookTitle));
                }

                QTableWidgetItem *lineItem = ui->tableWidgetResults->item(row, 2);
                if (lineItem) {
                    lineItem->setData(Qt::UserRole, i); // i 是原始行号
                }
            }
            // 假设有 5 列


        }
    }

}
void myWidget::on_tableWidgetResults_cellClicked(int row, int column)
{
    QString combinedText;

    // 获取上一行的内容（如果存在）
    if (row > 0) {
        QTableWidgetItem *prevItem = ui->tableWidgetResults->item(row - 1, 4);
        if (prevItem) {
            combinedText.append("上一行: " + prevItem->text() + "\n");
        }
    }

    // 获取当前行的内容
    QTableWidgetItem *currentItem = ui->tableWidgetResults->item(row, 4);
    if (currentItem) {
        combinedText.append("当前行: " + currentItem->text() + "\n");
    }

    // 获取下一行的内容（如果存在）
    if (row < ui->tableWidgetResults->rowCount() - 1) {
        QTableWidgetItem *nextItem = ui->tableWidgetResults->item(row + 1, 4);
        if (nextItem) {
            combinedText.append("下一行: " + nextItem->text());
        }
    }

    // 将合并后的内容显示在日志框中
    ui->tbLog->setPlainText(combinedText);
}

