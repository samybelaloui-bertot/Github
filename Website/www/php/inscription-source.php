<?php

include 'gestionbdd.php';

//RECUPERATION VARIABLES
$login=$_POST['login'];
$email=$_POST['email_addr'];
$email_repeat=$_POST['email_addr_repeat'];
$password=$_POST['password'];
$password_repeat=$_POST['password_repeat'];

//INIT VARIABLES MESSAGES D'ERREUR
$flagerror=0;
$ko1=NULL;
$ko2=NULL;
$ko3=NULL;
$ko4=NULL;
$ko5=NULL;
$ko6=NULL;
$ko7=null;

//INIT VARIABLES MESSGES DE CONFIRMATION
$ok1=NULL;
$ok2=NULL;

//CONNEXION BDD ==> FAIRE LE LIEN AVEC SMARTY
$objet = new Gestionbdd;
$connexion=$objet->connexion();

//SI LA TABLE N'EXISTE PAS, CREATION AUTO
$req = $connexion->exec("CREATE TABLE IF NOT EXISTS `utilisateurs` (
    `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
    `login` TEXT NOT NULL ,
    `password` TEXT NOT NULL ,
    `email` TEXT NOT NULL )");

//TEST LOGIN DEJA UTILISE
$requete="SELECT login FROM utilisateurs WHERE login=?";

$stmt = $connexion->prepare($requete);
$stmt->bindParam(1, $login);


$stmt->execute();
$donnees = $stmt->fetch();


if (empty($donnees['login']) !=1)
{
	$ko1= "Erreur, login déjà existant dans la base de données\n";
	$flagerror=1;
}

//TEST LONGUEUR PSEUDO
if(strlen($login)<2 || strlen($login)>20)
{
	$ko3= "Erreur, login trop court ou trop long\n";
	$flagerror=1;

}

//TEST ADRESSES EMAILS IDENTIQUES
if($email!=$email_repeat)
{
	$ko4= "Erreur, emails différents\n";
	$flagerror=1;

}


//TEST LONGUEUR ADRESSE EMAIL (On teste uniquement email car à ce stade les emails sont identiques)
if(strlen($email)<2 || strlen($email)>30)
{
	$ko5= "Erreur, email trop court ou trop long\n";
	$flagerror=1;
}

//TEST MOT DE PASSES IDENTIQUES
if($password!=$password_repeat)
{
	$ko6= "Erreur, mot de passes différents\n"; 
	$flagerror=1;
}

//TEST LONGUEUR MOT DE PASSE (On teste uniquement password car à ce stade les mots de passe sont identiques)
if(strlen($password)<2 || strlen($password)>30)
{
	$ko7= "Erreur, mot de passe trop court ou trop long\n";
	$flagerror=1;
}

//if(isset($ko1, $ko2, $ko3, $ko4, $ko5))
	if($flagerror==1)
{
	//SI ON A UNE ERREUR
	//ALORS ON AFFICHE LES ERREURS ==> A VOIR PAR LA SUITE EN LANGAGE OBJET?
	echo $ko1; echo $ko2; echo $ko3; echo $ko4; echo $ko5; echo $ko6; echo $ko7;

}

else
{
	//SI L'INSCRIPTION EST OK
	 //création de la requête SQL:
 	 $requete="INSERT INTO utilisateurs (login, password, email) VALUES (?,?,?)";

$stmt = $connexion->prepare($requete);
$stmt->bindParam(1, $login);
$stmt->bindParam(2, $password);
$stmt->bindParam(3, $email);

$stmt->execute();
  
	$ok1="Inscription réalisée avec succès";
	exit('<p>'.$ok1.'</p>
   <p>Revenir <a href="../index.php">ici</a> à la page d\'accueil</p>');

	//INITIALISATION DES VARIABLES DE SESSION
	//gestionutilisateur->__nouvellesession($login);	
}

?>