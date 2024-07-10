#ifndef MYRENAME_H
#define MYRENAME_H

#include <QDir>
#include <QBitArray>
#include <QStringList>


class myRename
{
public:
    myRename();

    void queryFileList(const QString&query,QDir::Filter filter);
    const QStringList&getFileList();
    QBitArray replaceFileName(const QString&repalce);

private:
    QStringList queriedFiles;
    QString queryString;
};

#endif // MYRENAME_H
