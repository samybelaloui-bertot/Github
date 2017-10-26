<?php 

    include 'gestionbdd.php';

	$objet = new Gestionbdd;
	$objet->deconnexion();

	//redirection
    $smarty->display("../tpl/accueil.tpl");

?>