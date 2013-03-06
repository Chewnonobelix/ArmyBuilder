#include "Header/Controlleur/controlleursauvegarde.h"

ControlleurSauvegarde::ControlleurSauvegarde()
{
}

void ControlleurSauvegarde::sauvegarder()
{
    /*if(!m_nomListe.isEmpty())
    {
        QDir dir;
        QFileInfoList list = dir.entryInfoList(QStringList("Liste"));
        if(list.count() == 0)
        {
            dir.mkdir("Liste");
        }

        QFile fichier("Liste\\"+m_nomListe+".xml");
        fichier.open(QIODevice::WriteOnly);

        QXmlStreamWriter stream(&fichier);

        stream.setAutoFormatting(true);
        stream.setCodec("ISO8859-1");

        stream.writeStartDocument();
        stream.writeStartElement("armee");
        stream.writeAttribute("nom" , dex::m_nomCodex);
        stream.writeAttribute("jeux", getJeux());
        for(QMap<QString, QMap<int, unite> >::iterator i = m_liste->getCategorie().begin(); i != m_liste->getCategorie().end(); i++)
        {
            stream.writeStartElement("categorie");
            stream.writeAttribute("id", i.key());
            foreach (unite it, i.value())
            {
                stream.writeStartElement("unite");
                stream.writeAttribute("type", it.getNomUs());
                stream.writeAttribute("nom", it.getNomDon());
                stream.writeAttribute("place", QString::number(it.getPlace()));
                stream.writeAttribute("nombre", QString::number(it.getNombreAct()));
                stream.writeAttribute("id", QString::number(it.getId()));
                for(QMultiMap<QString, QMultiMap<QString, int> >::iterator it3 = it.getEquipementAct().begin(); it3 != it.getEquipementAct().end(); it3++)
                {
                    for(QMultiMap<QString, int>::iterator it2 = it3.value().begin(); it2 != it3.value().end(); it2++)
                    {
                        stream.writeStartElement("equipement");
                        stream.writeAttribute("nom", it2.key());
                        stream.writeAttribute("cat", it3.key());
                        stream.writeEndElement();
                    }
                }

                for(QMap<QString,QVector<int> >::iterator it2 = it.getEditable().begin(); it2 != it.getEditable().end(); it2++)
                {
                    stream.writeStartElement("accompagnants");
                    stream.writeAttribute("nom", it2.key());
                    foreach (int j, it2.value())
                    {
                        stream.writeStartElement("accompagnant");
                        stream.writeAttribute("id", QString::number(j));
                        stream.writeEndElement();
                    }
                    stream.writeEndElement();
                }
                stream.writeEndElement();
            }
            stream.writeEndElement();
        }
        stream.writeEndElement();
        stream.writeEndDocument();

        fichier.close();
    }*/
}

