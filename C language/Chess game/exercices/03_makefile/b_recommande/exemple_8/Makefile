
#Enchainement de commandes

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



#Question:
# Observez la dependance enchainee entre plusieurs fichiers.
# Lancez make, notez que l'ordre de creation des fichiers se realise dans un ordre coherent.
# Est-ce que fichier_6 est cree? Pourquoi?
# Lancez la commande "make fichier_6.txt" dans la ligne de commande, que ce passe t-il?
