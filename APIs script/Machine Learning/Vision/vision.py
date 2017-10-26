import json
import requests
import base64

#[ETAPE 1]
#Point d'accès et clé
endpoint = "https://vision.googleapis.com/v1/images:annotate?key=AIzaSyDPEG8Z1jHH70SWrd6yXV8MWQ4pETyNQPs"

#Type
type = "WEB_DETECTION"
#LABEL_DETECTION, WEB_DETECTION

#Nombre de résultats
maxResults = 10

#Chemin image
chemin_image="images/image4.jpg"

#Codage en base 64
with open(chemin_image, "rb") as image_brute:
    image_b64=base64.b64encode(image_brute.read())

#[ETAPE 2]
#Construction de la requete Json
requete= { "requests":[ {"features":[ { "type": type,"maxResults": maxResults } ],
"image":{ "content" : image_b64 } } ] }


#Affichage requete
print "******** Requete envoyée ********"
#print json.dumps(requete,indent=1)


#[ETAPE 3]
#Envoie requete
reponse = requests.post(endpoint, json=requete)


#Affichage réponse complète
print "******** Réponse reçue ********"
print json.dumps(reponse.json(),indent=1)



#[ETAPE 4]
#Identification et stockage des attributs dans un fichier texte
print "******** Identification de {0} ********".format(chemin_image)

#Stockage nom image
fichier = open("attributs.txt", "a")
fichier.write('*'+chemin_image+'*')
fichier.close()


nbresults=0
erreur=0

for id_attribut in range(maxResults):
    try:
        if(reponse.json()["responses"][0]["labelAnnotations"][id_attribut]["description"])!=None:
            nbresults=nbresults+1
    except:
        erreur=1



for id_attribut in range(nbresults-1):
    attribut=reponse.json()["responses"][0]["labelAnnotations"][id_attribut]["description"]

    #Affichage attributs
    print "[{0}] : {1}".format(id_attribut, attribut)

    #Stockage des attributs
    fichier = open("attributs.txt", "a")
    fichier.write(attribut+';')
    fichier.close()

print "******** Stockage dans fichier texte OK ********"



#Remarques :
# Sources de l'image : Soit elle est hébergée, alors on met l'url a la place de chemin_image 
#et on remplace content par "imageUri" dans la requete json, soit elle est locale et on la convertit en base 64
# Ne pas afficher la requete envoyée si on utilise la conversion b64, car beaucoup de lignes
#
# Pour identifier, [0] quand un [est ouvert et qu'il n'y a qu'un seul attribut, [x] quand plusieurs attributs pour choisir 
# Ouverture fichier en mode w = écrase les données précédentes. Avec "a", on les converse et crée le fichier si n'existe pas
