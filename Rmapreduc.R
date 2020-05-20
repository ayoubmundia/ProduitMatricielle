#chargement du package
library(rmr2)

#fonctionner sans Hadoop
rmr.options(backend="local")

#vecteur de lettres
lettres <- c("A","A","A","B","A","B","B","A","B","B","A","A","A","B","B","B","A","A")

#fonction map()
mon.map <- function(.,data){
    #créer un vecteur de valeur 1 de même longueur que v
    one <- rep(1,length(data))

    #l'associer à v qui joue le rôle de clé
    cle_valeur <- keyval(data,one)
    #renvoyer le tout
    return(cle_valeur)
}

#fonction reduce
mon.reduce <- function(k,v){
    #faire la somme de 1 pour une clé donnée
    somme <- sum(v)
    #renvoyer en sortie la clé et le résultat
    return(keyval(k,somme))
}

#transformation
dfs.lettres <- to.dfs(lettres)

#appel de mapreduce
res.mr <- mapreduce(input=dfs.lettres,map=mon.map,reduce=mon.reduce)
#conversion en R
resultat <- from.dfs(res.mr)
#affichage
print(resultat)
