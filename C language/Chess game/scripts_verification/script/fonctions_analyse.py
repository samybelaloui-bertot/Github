import os

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

    @classmethod
    def ok_green(self):
        return self.OKGREEN+"OK"+self.ENDC

    @classmethod
    def ko_yellow(self):
        return self.WARNING+"KO"+self.ENDC

    @classmethod
    def ko_red(self):
        return self.FAIL+"KO"+self.ENDC

def trouve_archive(racine):
    fichiers=os.listdir(racine)
    archives=[]
    for f in fichiers:
        if f.endswith("tar.gz") and f!="scripts_verification.tar.gz":
            archives.append(f)

    if len(archives)>1:
        print("Erreur: Trouve plusieurs archives possibles:",str(archives))
        exit()
    if len(archives)==0:
        print("Aucune archive tar.gz trouve dans le repertoire:",str(racine))
        exit()
    
    assert(len(archives)==1)
    
    return archives[0]

def decompression(chemin_archive):
    assert os.path.isfile(chemin_archive)
    os.system("tar xfz "+chemin_archive)

def verification_nom_repertoire(nom_repertoire):
    if os.path.isdir(nom_repertoire)!=True:
        print("Erreur repertoire attendu non trouve apres decompression: "+nom_repertoire)
        exit()


def verification_repertoires_consignes(racine):
    repertoires_consignes={"bin":False,"src":False}
    if os.path.isdir(racine+"/bin")==True:
        repertoires_consignes["bin"]=True
    if os.path.isdir(racine+"/src")==True:
        repertoires_consignes["src"]=True

    return repertoires_consignes
    
def affiche_problemes_repertoire_consignes(consignes_repertoires):
    if consignes_repertoires["bin"]==False:
        print("Ne trouve pas le repertoire bin/")
    if consignes_repertoires["src"]==False:
        print("Ne trouve pas le repertoire src/")
        exit()

def cherche_fichiers_sources(racine):
    fichiers=os.listdir(racine)
    fichiers_src=[]
    for f in fichiers:
        if f.endswith(".c") or f.endswith(".h"):
            fichiers_src.append(racine+f)
    return sorted(fichiers_src)

def cherche_fichier_nom(racine):
    fichiers=os.listdir(racine)
    for f in fichiers:
        if f=="noms.txt":
            return racine+f
    

def clean_line(string):
    string=string.replace("\n","")
    string=string.replace("\t","")
    if string[0]==" ":
        string=string[1:]
    return string

class binome_class:
    def __init__(self):
        self.nom1=""
        self.prenom1=""
        self.nom2=""
        self.prenom2=""
        self.groupe=""

    @classmethod
    def cree_binome(cls,nom1,prenom1,nom2,prenom2,groupe):
        c=cls()
        c.nom1=nom1
        c.prenom1=prenom1
        c.nom2=nom2
        c.prenom2=prenom2
        c.groupe=groupe
        return c

    def clean_nom(self):
        self.nom1=clean_line(self.nom1)
        self.prenom1=clean_line(self.prenom1)
        self.nom2=clean_line(self.nom2)
        self.prenom2=clean_line(self.prenom2)
        self.groupe=clean_line(self.groupe)

    def __eq__(self,b):
        if self.groupe==b.groupe:
            if self.nom1==b.nom1 and self.prenom1==b.prenom1:
                if self.nom2==b.nom2 and self.prenom2==b.prenom2:
                    return True
            if self.nom1==b.nom2 and self.prenom1==b.prenom2:
                if self.nom2==b.nom1 and self.prenom2==b.prenom2:
                    return True
        return False

    def __str__(self):
        return self.nom1+" "+self.prenom1+" "+self.nom2+" "+self.prenom2+" "+self.groupe

    def str_pretty(self):
        s=self.nom1+" "+self.prenom1
        if len(self.nom2)!=0:
            s+=" ; "+self.nom2+" "+self.prenom2
        else:
            s+=" (monome)"
        s+=" ; groupe "+self.groupe
        return s
            
        

def extrait_nom(str_fichier,fichier,str_debug):
    
    if len(str_fichier)==0:
        print("Erreur,",str_debug,"non trouve dans fichier",fichier)
        
    str_fichier=str_fichier.replace("\n","")
    str_fichier=str_fichier.replace("\t","")

    token=str_fichier.split(":")
    if len(token)!=2:
        print("Erreur analyse",str_debug,"[",str_fichier,"] dans fichier",fichier)
        exit()
    nom=token[1]
    nom=nom[0].upper()+nom[1:].lower()

    if nom=="Zzz":
        print("Erreur",str_debug,"non mis a jour (zzz) dans fichier",fichier)
        
    return nom

def extrait_groupe(str_fichier,fichier):
    if len(str_fichier)==0:
        print("Erreur pas de groupe dans fichier",fichier)

    str_fichier=str_fichier.replace("\n","")
    str_fichier=str_fichier.replace("\t","")

    token=str_fichier.split(":")
    if len(token)!=2:
        print("Erreur analyse groupe [",str_fichier,"] dans fichier",fichier)
        exit()
        
    groupe=token[1]
    groupe=groupe.upper()

    if groupe!="A" and groupe!="B" and groupe!="C" and groupe!="D":
        print("Groupe [",groupe,"] inconnu")
        exit()
    return groupe

def recupere_nom_a_partir_fichier(fichier_nom):

    
    assert os.path.isfile(fichier_nom)

    binome=binome_class()

    fid=open(fichier_nom)
    for line in fid:
        if line.find("Nom 1 :")==0:
            binome.nom1=line[7:]
        elif line.find("Prenom 1 :")==0:
            binome.prenom1=line[10:]
        elif line.find("Nom 2 :")==0:
            binome.nom2=line[7:]
        elif line.find("Prenom 2 :")==0:
            binome.prenom2=line[10:]
        elif line.find("Groupe :")==0:
            binome.groupe=line[8:]

    binome.clean_nom()
    
    fid.close()

    return binome



def recupere_nom_fichiers_sources(fichiers):

    tous_noms=[]
    
   
    for f in fichiers:
        assert os.path.isfile(f)

        nom1=os.popen("grep -i "+f+" -e //#Nom1: | tr -d ' '").read()
        prenom1=os.popen("grep -i "+f+" -e //#Prenom1: | tr -d ' '").read()
        nom2=os.popen("grep -i "+f+" -e //#Nom2: | tr -d ' '").read()
        prenom2=os.popen("grep -i "+f+" -e //#Prenom2: | tr -d ' '").read()
        groupe=os.popen("grep -i "+f+" -e //#Groupe: | tr -d ' '").read()

        nom1=extrait_nom(nom1,f,"nom1")
        prenom1=extrait_nom(prenom1,f,"prenom1")
        if len(nom2)>0:
            nom2=extrait_nom(nom2,f,"nom2")
            prenom2=extrait_nom(prenom2,f,"prenom2")
        groupe=extrait_groupe(groupe,f)

        tous_noms.append(binome_class.cree_binome(nom1,prenom1,nom2,prenom2,groupe))

    N=len(tous_noms)
    for k1 in range(0,N):
        for k2 in range(k1+1,N):
            if not tous_noms[k1]==tous_noms[k2]:
                nom1=tous_noms[k1].nom1+" "+tous_noms[k1].prenom1+" "+tous_noms[k1].nom2+" "+tous_noms[k1].prenom2+" "+tous_noms[k1].groupe
                nom2=tous_noms[k2].nom1+" "+tous_noms[k2].prenom1+" "+tous_noms[k2].nom2+" "+tous_noms[k2].prenom2+" "+tous_noms[k2].groupe
                print("Erreur noms ne sont pas coherents [",nom1,"] et [",nom2,"] entre fichier "+fichiers[k1]+" et fichier "+fichiers[k2])

    return tous_noms[0]



def verification_fichiers_invalides_consignes(racine):
    fichiers=os.listdir(racine)
    fichiers_invalides=[]
    for f in fichiers:
        if f.endswith(".o") or f.endswith("~") or f.startswith("."):
            fichiers_invalides.append(racine+f)
    fichiers_invalides=sorted(fichiers_invalides)

    if len(fichiers_invalides)!=0:
        print(bcolors.WARNING,"=> Il reste des fichiers non valides:",fichiers_invalides,bcolors.ENDC)
    return fichiers_invalides


def compile_sources(racine):

    if os.path.isfile(racine+"makefile"):
        os.system("rm "+racine+"makefile")

    os.system("cp script/CMakeLists.txt "+racine)
    os.system("cd "+racine+"; cmake . > /dev/null")
    os.system("cd "+racine+"; make 2> compilation.txt")
    os.system("cp "+racine+"compilation.txt tmp/compilation.txt")

    fid=open("tmp/compilation.txt","r")
    compilation_erreurs=fid.read()
    fid.close()
    return compilation_erreurs
    

def verification_executable_cree_consignes(racine):
    if not os.path.isfile(racine+"projet_3eti"):
        print(bcolors.FAIL+"=> Executable non cree, projet ne compile pas"+bcolors.ENDC)
        return False
    return True

def compte_nombre_warning(compilation_resultat):
    nbr=compilation_resultat.count("warning")
    nbr+=compilation_resultat.count("attention")
    return nbr



def affichage_resultats_consignes_resume(binome,consignes_fichiers_invalides,executable_existe,nbr_warning):
    print("\n\n**********************************")
    print("Analyse de l'archive")
    print(binome.str_pretty())
    if binome.nom1=="A_COMPLETER" or binome.prenom1=="A_COMPLETER" or binome.nom2=="A_COMPLETER" or binome.prenom2=="A_COMPLETER" or binome.groupe=="A_COMPLETER":
        print("NOMS INVALIDES "+bcolors.ko_red())
    print("")

    if len(consignes_fichiers_invalides)==0:
        print("- Fichiers src ["+bcolors.ok_green()+"]")
    else:
        print("- Presence de fichiers invalides dans src/ ["+bcolors.ko_yellow()+"]")
        for k,f in enumerate(consignes_fichiers_invalides):
            print("Fichier invalide ",k+1," : ",f)

    if nbr_warning==0:
        print("- Warning 0 ["+bcolors.ok_green()+"]")
    else:
        print("- Warning(s): "+str(nbr_warning)+" ["+bcolors.ko_yellow()+"]")

    if executable_existe==True:
        print("- Compilation ["+bcolors.ok_green()+"]")
    else:
        print("- Executable non cree, compilation ["+bcolors.ko_red()+"]")


    if executable_existe!=True or nbr_warning!=0:
        print(" => Trace de la compilation dans le fichier tmp/compilation.txt")

    print("\n**********************************\n\n")
