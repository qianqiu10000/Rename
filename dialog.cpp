#include "dialog.h"
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>


#include "myRename.h"

#pragma execution_character_set("UTF-8")

myRename renameObject;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    queryLabel=new QLabel("查找");
    replaceLabel=new QLabel("替换");
    queryLabel->setAlignment(Qt::AlignCenter);
    replaceLabel->setAlignment(Qt::AlignCenter);

    queryLine=new QLineEdit;
    replaceLine=new QLineEdit;
    queryButton=new QPushButton("查找");
    replaceButton=new QPushButton("替换");

    fileCheckBox=new QCheckBox("文件");
    dirCheckBox=new QCheckBox("文件夹");
    fileCheckBox->setChecked(true);

    resultList=new QListWidget;

    QGridLayout*grid=new QGridLayout;
    grid->addWidget(queryLabel,0,0);
    grid->addWidget(queryLine,0,1);
    grid->addWidget(queryButton,0,2);
    grid->addWidget(replaceLabel,1,0);
    grid->addWidget(replaceLine,1,1);
    grid->addWidget(replaceButton,1,2);
    grid->addWidget(fileCheckBox,2,0);
    grid->addWidget(dirCheckBox,2,1);
    grid->addWidget(resultList,3,0,1,3);
    grid->setRowStretch(3,1);
    grid->setColumnStretch(1,1);

    this->setLayout(grid);
    this->setMinimumSize(400,200);
    this->setWindowTitle("批量修改文件名");


    connect(queryButton,&QPushButton::clicked,this,&Dialog::slotQueryFiles);
    connect(replaceButton,&QPushButton::clicked,this,&Dialog::slotReplaceFiles);
}

Dialog::~Dialog()
{
}

//查询文件名
void Dialog::slotQueryFiles()
{
    resultList->clear();
    int filter=0;
    if(!dirCheckBox->isChecked()&&!fileCheckBox->isChecked())
        fileCheckBox->setChecked(true);
    if(fileCheckBox->isChecked())
        filter=QDir::Files|filter;
    if(dirCheckBox->isChecked())
        filter=QDir::Dirs|filter;

    renameObject.queryFileList(queryLine->text(),QDir::Filter(filter));


    if(renameObject.getFileList().isEmpty())
        return;

    resultList->addItems(renameObject.getFileList());

}

//替换文件名
void Dialog::slotReplaceFiles()
{
    QBitArray result=renameObject.replaceFileName(replaceLine->text());
    resultList->clear();
    resultList->addItems(renameObject.getFileList());
    for(int i=0;i<result.count();i++)
    {
        QColor color=result.at(i)?Qt::green:Qt::red;
        resultList->item(i)->setBackground(color);
    }
}

