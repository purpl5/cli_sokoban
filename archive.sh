# Qu'est ce que le code fait : Créer la variable date_maintenant qui est égal à la date au moment du lancement du script
# Il archive : - les dossiers : src, header, doc; - les fichiers : makefile doxyfile; 
# Problème : je n'ai pas reussi a faire cela dans le makefile directement du au variable qui cause des problèmes
date_maintenant=$(date "+%F-%H-%M-%S")
tar -cf ./archive/archive-$date_maintenant.tar ./header ./src ./doc makefile doxyfile