#include "Header/Controlleur/controlleurnouveau.h"

ControlleurNouveau::ControlleurNouveau(QObject * parent): Controlleur(parent)
{
    m_vue = new Nouveau;
}

Nouveau* ControlleurNouveau::getVue()
{
    return m_vue;
}

void ControlleurNouveau::setVue(Nouveau * v)
{
    m_vue = v;
}

void ControlleurNouveau::exec()
{
    int ret = getVue()->exec();

    if(ret == QDialog::Accepted)
    {
        emit s_enable(true);

        int limite_pts;
        bool limite_nb;
        QString jeux, armee, liste;
        getVue()->get(limite_nb, limite_pts, jeux, armee, liste);


        if(hasModel())
        {
            destroyModel();
        }

        getModel()->setliste(new Codex);
        getModel()->getListe()->setNomListe(liste);
        getModel()->setNomJeux(jeux);

        jeux.replace(" ", "_");
        armee.replace(" ", "_");

        ControlleurChargement c;
        if(c.chargerNouveau(armee, jeux))
        {

            if(!limite_nb)
            {
                for(QMap<QString, int>::iterator it = getModel()->getLimite().begin(); it != getModel()->getLimite().end(); it++)
                {
                    it.value() = 0;
                }
            }
            emit s_max(limite_pts);
        }
    }
}
