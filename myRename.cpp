#include "myRename.h"
#include <QFile>



myRename::myRename()
{

}



//查询包含filter的文件名
void myRename::queryFileList(const QString&query,QDir::Filter filter)
{
    queriedFiles.clear();
    queryString=query;
    if(queryString.isEmpty())
        return;

    QDir dir;
    QStringList allFiles= dir.entryList(filter);
    foreach(QString file,allFiles)
    {
        if(file.contains(query))
            queriedFiles.append(file);
    }

}

//获取查询的文件列表
const QStringList &myRename::getFileList()
{
    return queriedFiles;
}

//使用使用replace替换文件名中的query
QBitArray myRename::replaceFileName(const QString&repalce)
{
    QBitArray result(queriedFiles.count());
    for(int i=0;i<queriedFiles.count();i++)
    {
        QString before=queriedFiles.at(i);
        QString after=QString(before).replace(queryString,repalce);
        bool ok=QFile::rename(before,after);
        result[i]=ok;
        if(ok)
            queriedFiles.replace(i,after);
    }

    return result;
}

