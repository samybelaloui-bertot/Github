<?php
include 'gestionbdd.php';

// En cas de problème avec des erreurs de syntaxes voir http://php.net/

//RECUPERATION VARIABLES
$login=$_POST['login'];
$password=$_POST['password'];

//INIT VARIABLES ERREUR
$flagerror=0;

//CONNEXION BDD
$objet = new Gestionbdd;
$connexion=$objet->connexion();

//ON TESTE SI LE MOT DE PASSE EST CELUI ATTENDU
$stmt = $connexion->prepare("SELECT COUNT(*) FROM utilisateurs WHERE login=? AND password=?");
$stmt->bindParam(1, $login);
$stmt->bindParam(2, $password);

if ($stmt->execute()) {
  while ($row = $stmt->fetch()) {
    
     if ($row['COUNT(*)'] != 1)         //SI LE MOT DE PASSE EST INCORRECT
    {
        $flagerror=1;
        break;
    }
  }
}


if($flagerror==1)
{
    //Si les identifiants ne sont pas ok, rechargement de la page  
	$smarty->display("../tpl/connexion.tpl"); 
}
else
{
	//SI LA CONNEXION EST OK
	//MISE A JOUR DES VARIABLES DE SESSION
    $_SESSION['login'] = $login;
    $smarty->display("../tpl/accueil.tpl");
}

?>