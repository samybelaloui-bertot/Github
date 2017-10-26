
#Enchainement de commandes (idem que l'exemple precedent)

#"all: fichier_X", signifie que l'on cherche a creer le fichier_X lorsque l'on lance make (Sinon make ne genere que la premiere ligne).
all: fichier_5.txt

fichier_3.txt: fichier_2.txt
	echo "Je suis fichier_3" > fichier_3.txt
	cat fichier_2.txt >> fichier_3.txt 
#cat permet d'afficher le contenu d'un fichier

fichier_2.txt: fichier_1.txt
	cp fichier_1.txt fichier_2.txt

fichier_1.txt: 
	echo "Bonjour, je suis fichier_1" > fichier_1.txt

fichier_5.txt: fichier_4.txt fichier_3.txt
	echo "Contenu de fichier 3:" > fichier_5.txt
	cat fichier_3.txt >> fichier_5.txt
	echo "Contenu de fichier 4:" >> fichier_5.txt
	cat fichier_4.txt >> fichier_5.txt

fichier_6.txt: fichier_4.txt
	cp fichier_4.txt fichier_6.txt

fichier_4.txt: 
	echo "Je suis fichier 4" > fichier_4.txt

clean:
	echo "Je supprime les fichier qui se terminent par .txt"
	rm *.txt



#Question:
# Observez la ligne "clean": quelle commande lance cette ligne?
# Lancez make en ligne de commande.
# Relancez make, que ce passe t-il?
# Lancez "make clean" en ligne de commande. Que ce passe t-il? pourquoi?
# Relancez make.
# Concluez sur le rôle de l'appel a clean.
