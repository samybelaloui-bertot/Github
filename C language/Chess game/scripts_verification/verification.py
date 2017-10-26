
import os

from script import *


#repertoire tmp
os.system("rm -rf tmp")
os.system("mkdir -p tmp")

#nom archive et repertoire
chemin_archive=trouve_archive(".")
nom_repertoire_attendu=chemin_archive.replace(".tar.gz","")

#mise en place de la decompression
decompression(chemin_archive)
verification_nom_repertoire(nom_repertoire_attendu)

#verification des repertoires
consignes_repertoires=verification_repertoires_consignes(nom_repertoire_attendu)
affiche_problemes_repertoire_consignes(consignes_repertoires)


#recherche des fichiers sources
path_src=nom_repertoire_attendu+"/src/"
assert os.path.isdir(path_src)
fichiers_sources=cherche_fichiers_sources(path_src)
fichier_nom=cherche_fichier_nom(path_src)
if fichier_nom==None:
    print("Fichier noms.txt non present dans les sources")
    abort()

consignes_fichiers_invalides=verification_fichiers_invalides_consignes(path_src)

#analyse des noms
binome=recupere_nom_a_partir_fichier(fichier_nom)


#compilation et recherche executable
compilation_erreurs=compile_sources(path_src)
executable_existe=verification_executable_cree_consignes(path_src)
nbr_warning=compte_nombre_warning(compilation_erreurs)

#affichage de synthese
affichage_resultats_consignes_resume(binome,consignes_fichiers_invalides,executable_existe,nbr_warning)

#suppression du repertoire
assert os.path.isdir(nom_repertoire_attendu)
os.system("rm -rf "+nom_repertoire_attendu)
