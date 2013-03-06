#ifndef SQL_H
#define SQL_H

#include<QtSql>
#include<QMessageBox>
#include<QFile>
#include<QFileInfo>
#include<QDir>
#include<QVector>
#include <QtXml>
#include <QDateTime>
#include <QRegExp>

class Sql
{
public:
    Sql(QString);
    ~Sql();
    void initDb();
    QSqlQuery& getRes(QString = QString());
    void maj(QString);

private:
    QSqlDatabase m_db;
    QSqlQuery m_query;
    void majJeux();
    void majArmee();
    QVector<QString> m_requete;
    void majFichMaj(QString);
    void execMaj(QString);
};

#endif // SQL_H
