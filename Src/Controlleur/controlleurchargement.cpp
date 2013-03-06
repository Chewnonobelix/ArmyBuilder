#include "Header/Controlleur/controlleurchargement.h"

ControlleurChargement::ControlleurChargement()
{
}

bool ControlleurChargement::chargerNouveau(QString nom, QString jeux)
{
    nom.replace(" ","_");
    jeux.replace(" ","_");
    QString nomFich = ("Data\\"+ jeux + "\\Armee\\"+nom+".xml");
    //m_bd->maj(jeux);
    QList<QString> nomCategorie;
    QDomDocument *dom = new QDomDocument;
    QFile xml_doc(nomFich);
    if(!xml_doc.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0,"Erreur à l'ouverture du fichier XML ","Le fichier XML n'a pas pu être ouvert. Vérifiez que le nomest le bon et que le document est bien placé");
        return false;
    }
    if(!dom->setContent(&xml_doc))
    {
        xml_doc.close();
        QMessageBox::warning(0,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return false;
    }

    QDomElement dom_element = dom->documentElement();
    QDomNode noeud = dom_element.firstChild();

    getModel()->getListe()->setNomArmee(dom_element.attribute("nom"));

    while(!noeud.isNull())
    {
        QDomElement element = noeud.toElement();
        if(!element.isNull() && element.tagName().contains("categorie"))
        {
            QString categorie = element.attribute("id");
            getModel()->getLimite().insert(categorie, element.attribute("max").toInt());
            if(!element.attribute("affichage").contains("false"))
            {
                nomCategorie<<categorie;
            }
            QDomNodeList unite = element.elementsByTagName("unite");
            QMultiMap<QString, EntreeCodex*> entreCat;
            for(int i = 0; i < unite.count(); i++)
            {
                QDomNode it = unite.at(i);
                element = it.toElement();
                EntreeCodex* entree = new EntreeCodex;
                entree->setNomUs(element.attribute("nom"));
                entree->setNombreMin(element.attribute("min").toInt());
                entree->setNombreMax(element.attribute("max").toInt());
                entree->setCoutUnit(element.attribute("cout").toInt());
                entree->setCoutBase(element.attribute("base").toInt());
                entree->setCategorie(categorie);
                if(element.attribute("genre").contains("unique"))
                {
                    entree->setUnique(true);
                }

                QDomNodeList equipements = element.elementsByTagName("equipements");
                QMap<QString, Equipement> map1;
                for(int j = 0; j < equipements.count(); j++)
                {
                    QDomNode it2 = equipements.at(j);
                    QDomElement elem2= it2.toElement();
                    Equipement equip;
                    switch(elem2.attribute("cles").toInt())
                    {
                    case ab::si:
                        equip.setCles(ab::si);
                        break;
                    case ab::par:
                        equip.setCles(ab::par);
                        break;
                    case ab::unique:
                        equip.setCles(ab::unique);
                        break;
                    case ab::tous:
                        equip.setCles(ab::tous);
                        break;
                    case ab::pourtous:
                        equip.setCles(ab::pourtous);
                        break;
                    case ab::sup:
                        equip.setCles(ab::sup);
                        break;
                    case ab::inf:
                        equip.setCles(ab::inf);
                        break;
                    default:
                        equip.setCles(ab::defaut);
                        break;
                    }

                    equip.setNom(elem2.attribute("nom"));
                    QPair<int, int> pair;

                    switch(equip.getCles())
                    {
                    case ab::si:
                        if(elem2.attribute("n").contains("max"))
                        {
                            pair.first = entree->getNombreMax();
                        }
                        else if(elem2.attribute("n").contains("min"))
                        {
                            pair.first = entree->getNombreMin();
                        }
                        else
                        {
                            pair.first = elem2.attribute("n").toInt();
                        }

                        if(elem2.attribute("m").contains("max"))
                        {
                            pair.second = entree->getNombreMax();
                        }
                        else if(elem2.attribute("m").contains("min"))
                        {
                            pair.second = entree->getNombreMin();
                        }
                        else
                        {
                            pair.second = elem2.attribute("m").toInt();
                        }
                        break;
                    case ab::par:
                        if(elem2.attribute("n").contains("max"))
                        {
                            pair.first = entree->getNombreMax();
                        }
                        else if(elem2.attribute("n").contains("min"))
                        {
                            pair.first = entree->getNombreMin();
                        }
                        else
                        {
                            pair.first = elem2.attribute("n").toInt();
                        }

                        if(elem2.attribute("m").contains("max"))
                        {
                            pair.second = entree->getNombreMax();
                        }
                        else if(elem2.attribute("m").contains("min"))
                        {
                            pair.second = entree->getNombreMin();
                        }
                        else
                        {
                            pair.second = elem2.attribute("m").toInt();
                        }
                        break;
                    case ab::defaut:
                        if(elem2.attribute("n").contains("max"))
                        {
                            pair.first = entree->getNombreMax();
                            pair.second = entree->getNombreMin();
                        }
                        else if(elem2.attribute("n").contains("min"))
                        {
                            pair.first = entree->getNombreMin();
                            pair.second = entree->getNombreMin();
                        }
                        else
                        {
                            pair.first = elem2.attribute("n").toInt();
                            pair.second = entree->getNombreMin();
                        }
                        break;
                    case ab::tous:
                        if(elem2.attribute("n").contains("max"))
                        {
                            pair.first = entree->getNombreMax();
                        }
                        else if(elem2.attribute("n").contains("min"))
                        {
                            pair.first = entree->getNombreMin();
                        }
                        else
                        {
                            pair.first = elem2.attribute("n").toInt();
                        }
                        break;
                    default:
                        pair.first = entree->getNombreMax();
                        pair.second = entree->getNombreMin();
                        break;

                    }

                    equip.setNDansM(pair);

                    QSet<QString> set;
                    QDomNodeList membre2 = elem2.elementsByTagName("exclus");
                    for(int l = 0; l < membre2.count(); l++)
                    {
                        set.insert(membre2.at(l).toElement().attribute("nom"));
                    }

                    equip.setExclus(set);

                    QDomNodeList membre = elem2.elementsByTagName("equipement");
                    QMultiMap<int, QString> map;
                    for(int k = 0; k < membre.count(); k++)
                    {
                        elem2 = membre.at(k).toElement();
                        map.insert(elem2.attribute("pts").toInt(), elem2.attribute("nom"));
                    }




                    equip.setMembre(map);
                    map1.insert(equip.getNom(), equip);
                }
                entree->setEquipementDisp(map1);
                equipements = element.elementsByTagName("accompagnants");

                for(int j = 0; j < equipements.count(); j++)
                {
                    QDomElement elem2 = equipements.at(j).toElement();
                    QMap<QString, QPair<ab::cles, int> > set;
                    Accompagnant a;
                    a.setNom(elem2.attribute("nom"));
                    a.setNb(elem2.attribute("nb").toInt());
                    QDomNodeList list = elem2.elementsByTagName("accompagnant");
                    for(int k = 0; k < list.count(); k++)
                    {
                        QDomElement elem3 = list.at(k).toElement();

                        if(elem3.hasAttribute("cles"))
                        {

                            switch(elem3.attribute("cles").toInt())
                            {
                            case ab::si:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::si, elem3.attribute("nb").toInt()));
                                break;
                            case ab::par:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::par, elem3.attribute("nb").toInt()));
                                break;
                            case ab::unique:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::unique, elem3.attribute("nb").toInt()));
                                break;
                            case ab::tous:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::tous, elem3.attribute("nb").toInt()));
                                break;
                            case ab::pourtous:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::pourtous, elem3.attribute("nb").toInt()));
                                break;
                            case ab::sup:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::sup, elem3.attribute("nb").toInt()));
                                break;
                            case ab::inf:
                                set.insert(elem3.attribute("nom"), qMakePair(ab::inf, elem3.attribute("nb").toInt()));
                                break;
                            default:
                                break;
                            }

                        }
                        else
                        {
                            set.insert(elem3.attribute("nom"), qMakePair(ab::defaut, 0));
                        }
                    }
                    a.setMembre(set);

                    entree->ajouteAccompagnant(a);
                }

                QSet<Modif> set2;

                equipements = element.elementsByTagName("modif");
                for(int j = 0; j < equipements.size(); j++)
                {
                    QDomElement elem2 = equipements.at(j).toElement();
                    Modif mod;
                    mod.setNom(elem2.attribute("nom"));
                    mod.setDepuis(elem2.attribute("depuis"));
                    mod.setVers(elem2.attribute("vers"));
                    switch(elem2.attribute("cles").toInt())
                    {
                    case ab::copier:
                        mod.setCles(ab::copier);
                        break;
                    case ab::deplace:
                        mod.setCles(ab::deplace);
                        break;
                    }
                    set2.insert(mod);
                }

                entree->setModif(set2);
                entreCat.insert(entree->getNomUs(), entree);
            }
            getModel()->getCodex().insert(categorie, entreCat);
        }
        noeud = noeud.nextSibling();
    }
    QMessageBox::information(0,"",QString::number(getModel()->getCodex().size()));
    xml_doc.close();

    return true;
}

void ControlleurChargement::exec()
{
    /*if(m_liste != NULL)
    {
        delete m_liste;
        dex::m_codex.clear();
    }

    Charger* load = new Charger();
    load->setModal(false);
    int i = load->exec();

    QString nom;
    if(i == QDialog::Accepted)
    {
        nom = load->recup();
    }

    if(!nom.isEmpty())
    {
        QFile fichier("Liste\\" + nom + ".xml");
        if(fichier.open(QIODevice::ReadOnly))
        {
            QString nomListe = nom;
            QDomDocument dom(nomListe);
            m_nomListe = nomListe;
            if(dom.setContent(&fichier))
            {
                QDomElement domElement = dom.documentElement();
                QString nomCodex = domElement.attribute("nom");
                m_jeux = domElement.attribute("jeux");
                m_liste = new Codex;
                chargerNouveau(nomCodex, m_jeux);
                m_liste->setNomListe(m_nomListe);

                QDomNode noeud = domElement.firstChild();
                while(!noeud.isNull())
                {
                    QDomElement element = noeud.toElement();
                    QDomNodeList list1 = element.elementsByTagName("unite");
                    QMultiMap<QString, EntreeCodex>* map1 = &(dex::m_codex.find(element.attribute("id")).value());
                    QMap<int, unite>& map2 = m_liste->getCategorie(element.attribute("id"));

                    for(int i = 0; i < list1.count(); i++)
                    {
                        QDomElement element2 = list1.at(i).toElement();
                        unite unit(map1->find(element2.attribute("type")).value());
                        unit.setNombre(element2.attribute("nombre").toInt());
                        unit.setNomDon(element2.attribute("nom"));
                        unit.setPlace((element2.attribute("place").toInt()));
                        unit.setId(element2.attribute("id").toInt());
                        m_liste->getListId().insert(unit.getId());
                        QDomNodeList list2 = element2.elementsByTagName("equipement");
                        for(int j = 0; j < list2.count(); j++)
                        {
                            QDomElement element3 = list2.at(j).toElement();

                            unit.ajoutEquipement(qMakePair(element3.attribute("nom"), unit.getEquipementDisp().find(element3.attribute("cat")).value().getMembre().key(element3.attribute("nom"))), element3.attribute("cat"));

                        }
                        map2.insert(unit.getId(), unit);
                        if(unit.getModif().size() != 0)
                        {
                            modif(element.attribute("id"), unit.getId(), true);
                        }
                    }

                    noeud = noeud.nextSibling();
                }
            }
            fichier.close();
            point();
        }
        else
        {
            QMessageBox::warning(0,"Erreur", "Impossible d'ouvrir le fichier " + nom + ".xml");
        }
    }*/
}
