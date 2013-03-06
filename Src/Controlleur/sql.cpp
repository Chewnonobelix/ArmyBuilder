#include "Header/Controlleur/sql.h"

Sql::Sql(QString nom)
{

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(nom);
    if(!QFile::exists(nom))
    {
        QFile file("Data\\Army_builder.sql");

        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(0,"Erreur", "Erreur lors de l'ouverture du fichier");
            return;
        }
        bool ok = true;
        while(ok)
        {
            QString query;

            do
            {
                query += file.readLine();
            }
            while(!query.contains(";"));

            m_requete.push_back(query);
            file.readLine();
            if(file.atEnd())
            {
                ok = false;
            }
        }
    }
    if(!m_db.open())
    {
        QMessageBox::information(0,"Erreur", "Erreur lors de l'ouverture de la base de données");
    }

    QFile fichMaj("Data\\maj.dat");

    if(!fichMaj.exists())
    {
        fichMaj.open(QIODevice::ReadWrite);
        fichMaj.close();
    }
}

Sql::~Sql()
{
    m_db.close();
}

void Sql::initDb()
{

    if(!m_requete.isEmpty())
    {
        foreach(QString query, m_requete)
        {
            m_db.exec(query);
        }
    }
    majJeux();
    majArmee();

    m_query = m_db.exec("SELECT * FROM race WHERE jeux = '1'");
    QString final;
    while(m_query.next())
    {
        final += "Id:"+m_query.value(0).toString() + "\n";
        final += "Nom:"+m_query.value(1).toString() + "\n";
        final += "Jeux:"+m_query.value(2).toString() + "\n";
    }


    QMessageBox::information(0,"",final);

}

QSqlQuery& Sql::getRes(QString query)
{
    m_query.exec(query);
    return m_query;
}

void Sql::majJeux()
{
    QDir dir("Data\\");

    QFileInfoList list = dir.entryInfoList();

    m_query = m_db.exec("SELECT COUNT(id) FROM jeux");
    m_query.next();
    if(m_query.value(0).toInt() != list.size() - 5|| m_query.isNull(0))
    {
        foreach(QFileInfo info, list)
        {
            if(info.isDir() && info.fileName() != "." && info.fileName() != "..")
            {
                m_query = m_db.exec("SELECT COUNT(id) FROM jeux WHERE nom = '"+info.fileName()+"'");
                m_query.next();
                if(m_query.value(0).toInt() < 1)
                {
                    m_query = m_db.exec("INSERT INTO jeux (nom)VALUES ('"+info.fileName()+"');");
                }
            }

        }
    }

}

void Sql::majArmee()
{
    QDir dir("Data\\");
    QFileInfoList list = dir.entryInfoList();
    QFileInfoList::iterator it = list.begin();
    while((*it).fileName() == "." || (*it).fileName() == ".." || (*it).isFile())
    {
        it++;
    }

    dir.cd((*it).fileName()+"\\Armee");
    foreach(QFileInfo info, list)
    {
        if(info.isDir() && info.fileName() != "." && info.fileName() != "..")
        {
            dir.cd("..\\..\\"+info.fileName()+"\\Armee");

            QFileInfoList list2 = dir.entryInfoList();
            m_query =  m_db.exec("SELECT id FROM jeux WHERE nom = '" + info.fileName() + "'");
            m_query.next();
            QString id_jeux = m_query.value(0).toString();

            foreach(QFileInfo info2, list2)
            {
                if(info2.completeSuffix() == "xml")
                {
                    m_query = m_db.exec("SELECT COUNT(id) FROM race WHERE jeux = '" + id_jeux + "' AND nom='"+info2.baseName()+"'");
                    m_query.next();
                    if(m_query.value(0).toInt() < 1 || m_query.value(0).isNull())
                    {
                        m_query = m_db.exec("INSERT INTO race (nom, jeux) VALUES ('"+info2.baseName()+"','" + id_jeux +"')");
                    }
                }
            }
        }
    }
}

void Sql::maj(QString jeux)
{
    QFile fichMaj("Data\\maj.dat");

    if(!fichMaj.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"Erreur", "Erreur lors de l'ouverture du fichier");
        return;
    }

    QRegExp exp(jeux + " (.*)\n");
    exp.setMinimal(true);
    QMessageBox::information(0,"Reg", exp.pattern());
    QString lecture = fichMaj.readAll();
    fichMaj.close();
    QFileInfo info("Data\\" + jeux +"\\maj.sql");

    int index = exp.indexIn(lecture);
    if(index == -1)
    {

        QMessageBox::information(0,"", "Maj");
        majFichMaj(jeux);
    }
    else
    {
        QMessageBox::information(0,"Appart", exp.cap(1));
        QDateTime date = QDateTime::fromString(exp.cap(1));
        if(date < info.lastModified())
        {
            QMessageBox::information(0,"", "Re maj");
            majFichMaj(jeux);
        }
    }
}

void Sql::majFichMaj(QString jeux)
{
    QFile fichMaj("Data\\maj.dat");

    if(!fichMaj.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"Erreur", "Erreur lors de l'ouverture du fichier");
        return;
    }
    QString lecture = fichMaj.readAll();
    fichMaj.close();

    QRegExp exp(jeux + " (.*)\n");
    exp.setMinimal(true);
    lecture.remove(exp);
    QString aEcrire = jeux;
    fichMaj.open((QIODevice::WriteOnly));

    aEcrire += " " + QDateTime::currentDateTime().toString() + "\n";

    fichMaj.write(lecture.toAscii());
    fichMaj.write(aEcrire.toAscii());
    fichMaj.close();

}

void Sql::execMaj(QString jeux)
{
    QSqlQuery query("INSERT INTO regle ('nom','jeux') VALUES (?,?)");
}
