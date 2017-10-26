import json
import requests
import base64

#VISION
#[ETAPE 1]
#Point d'accès et clé
endpoint_vision = "https://vision.googleapis.com/v1/images:annotate?key=AIzaSyDPEG8Z1jHH70SWrd6yXV8MWQ4pETyNQPs"

#Type
type = "LABEL_DETECTION"

#Nombre de résultats
maxResults = 10

#Chemin image
image_choisie=raw_input("Saisir le nom de l'image à analyser (ex:image1) : ")
print image_choisie
chemin_image="Vision/images/{0}.jpg".format(image_choisie)

#Codage en base 64
with open(chemin_image, "rb") as image_brute:
    image_b64=base64.b64encode(image_brute.read())

#[ETAPE 2]
#Construction de la requete Json
requete_vision= { "requests":[ {"features":[ { "type": type,"maxResults": maxResults } ],
"image":{ "content" : image_b64 } } ] }


#Affichage requete
print "******** [OK] Requete vision envoyée ********"
#print json.dumps(requete,indent=1)


#[ETAPE 3]
#Envoie requete
reponse_vision = requests.post(endpoint_vision, json=requete_vision)


#Affichage réponse complète
print "******** [OK] Réponse vision reçue ********"
#print json.dumps(reponse.json(),indent=1)



#[ETAPE 4]
#Identification et stockage des attributs dans un fichier texte
#print "******** Identification de {0} ********".format(chemin_image)

#Stockage nom image
##fichier = open("attributs.txt", "a")
##fichier.write('*'+chemin_image+'*')
##fichier.close()

attribut=""
nbresults=0
erreur=0

for id_attribut in range(maxResults):
    try:
        if(reponse_vision.json()["responses"][0]["labelAnnotations"][id_attribut]["description"])!=None:
            nbresults=nbresults+1
    except:
        erreur=1



for id_attribut in range(nbresults-1):
    attribut=attribut+(reponse_vision.json()["responses"][0]["labelAnnotations"][id_attribut]["description"])+", "
    #attribut="player"

#print "Affichage attributs"
#print attribut
    #Affichage attributs
#print "[{0}] : {1}".format(id_attribut, attribut)

##    #Stockage des attributs
##    fichier = open("attributs.txt", "a")
##    fichier.write(attribut+';')
##    fichier.close()

##print "******** Stockage dans fichier texte OK ********"



#NATURAL LANGUAGE
    #Point d'accès et clé
endpoint_nat = "https://language.googleapis.com/v1/documents:analyzeEntities?key=AIzaSyDPEG8Z1jHH70SWrd6yXV8MWQ4pETyNQPs"

encodingType = "UTF8"
type = "PLAIN_TEXT"

content = attribut


requete_nat={ "encodingType": encodingType, "document": { "type": type,
  "content": content } }

#Affichage requete
print "******** [OK] Requete natural language envoyée ********"
#print json.dumps(requete_nat,indent=1)


#Envoie requete
reponse_nat = requests.post(endpoint_nat, json=requete_nat)


#Affichage réponse complète
print "******** [OK] Réponse natural language reçue ********"
#print json.dumps(reponse_nat.json(),indent=1)


#Construction de la phrase

#Identification
nb_lieu=0
nb_lieu_temp=0
nb_autre=0
nb_autre_temp=0
nb_personne=0
nb_personne_temp=0
lieu=[]
autre=[]
personne=[]
dial_lieu=""
dial_autre=""
dial_personne=""
doublons_lieu=0
doublons_autre=0
doublons_personne=0
flag_lieu=0
flag_autre=0
flag_personne=0

#Init traduction
#Point d'accès et clé
endpoint_tra = "https://translation.googleapis.com/language/translate/v2?key=AIzaSyDPEG8Z1jHH70SWrd6yXV8MWQ4pETyNQPs"



for id_typeattribut in range(nbresults-1):
    try:
        typeattribut = reponse_nat.json()["entities"][id_typeattribut]["type"]
        attribut = reponse_nat.json()["entities"][id_typeattribut]["name"]
    except:
        typeattribut = ""
        attribut = ""

    #Traduction
    req_trans={'q' : attribut, 'source' : 'en', 'target' : 'fr', 'format' : 'text'}
    reponse_tr=requests.post(endpoint_tra, json=req_trans)
    attribut_fr=reponse_tr.json()['data']['translations'][0]['translatedText'].encode('utf8')

    
    #print "[{0}] : {1} -> {2} ".format(id_typeattribut, attribut , typeattribut)

    #LIEUX
    if typeattribut=="LOCATION":
        nb_lieu=nb_lieu+1
    #Stockage dans la liste
        
        if(attribut_fr not in lieu):
            flag_lieu=1
            lieu.append(attribut_fr)
        else:
            flag_lieu=0
            doublons_lieu=doublons_lieu+1
        

    #OBJETS DIVERS
    if typeattribut=="OTHER":
        
        nb_autre=nb_autre+1
 
        if(attribut_fr not in autre):
            flag_autre=1
            autre.append(attribut_fr)
        else:
            flag_autre=0
            doublons_autre=doublons_autre+1


    #PERSONNES
    if typeattribut=="PERSON":
        nb_personne=nb_personne+1

        if(attribut_fr not in personne):
            flag_personne=1
            personne.append(attribut_fr)
        else:
            flag_personne=0
            doublons_personne=doublons_personne+1

        
    #Construction
    if(nb_lieu == 1):
        nb_lieu_temp=nb_lieu
        dial_lieu = "La scène se passe dans un {0}".format(lieu[nb_lieu-1-doublons_lieu])
        
    if(nb_lieu > 1)and(nb_lieu<3)and(nb_lieu!=nb_lieu_temp)and(flag_lieu==1):
        nb_lieu_temp=nb_lieu
        dial_lieu=dial_lieu+", ou alors dans un {0}".format(lieu[nb_lieu-1-doublons_lieu])

    if(nb_autre == 1):       
        nb_autre_temp=nb_autre
        dial_autre = "Sur l'image, on peut voir un {0}".format(autre[nb_autre-1-doublons_autre])

    if(nb_autre > 1)and(nb_autre<3)and(nb_autre!=nb_autre_temp)and(flag_autre==1):       
        nb_autre_temp=nb_autre
        dial_autre=dial_autre+" et un {0}".format(autre[nb_autre-1-doublons_autre])


    if(nb_personne == 1):
        nb_personne_temp=nb_personne
        dial_personne = "On voit quelqu'un qui semble être un {0}".format(personne[nb_personne-1-doublons_personne])

    if(nb_personne > 1)and(nb_personne<3)and(nb_personne!=nb_personne_temp)and(flag_personne==1):
        nb_personne_temp=nb_personne
        dial_personne=dial_personne+". Cette personne peut être aussi un {0}".format(personne[nb_personne-1-doublons_personne])


print "******** [OK] Requete + réponse traduction envoyée et reçue ********"
    
print "-------------------"        
print "Construction phrase"
print "-------------------"


phrase="{0}. {1}. {2}.".format(dial_lieu, dial_personne, dial_autre)
print phrase


    
