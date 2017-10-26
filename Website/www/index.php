<?php
require("smarty/smarty.class.php"); // On inclut la classe Smarty

// Création de l'objet Smarty
$smarty = new Smarty();
$smarty->setCaching(false);

//Gestion des redirections
session_start();

//Si le champ page existe, on le récupère sinon on lui attribut la valeur NULL
if(isset($_GET['page']))
{
	$page = $_GET['page'];
}
else
{
	$page = NULL;
}

//Redirection en fonction du champ page de l'url
if($page == "accueil")
{
	$smarty->display("tpl/accueil.tpl");
}
elseif($page == "connexion")
{
    $smarty->display("tpl/connexion.tpl");
}
elseif($page == "categorie")
{
    $smarty->display("tpl/categorie.tpl");
}
elseif($page == "info")
{
	$smarty->display("tpl/info.tpl");
}
elseif($page == "deconnexion")
{
	include"php/deconnexion.php";
}
elseif($page == "rss")
{
	$smarty->display("tpl/rss.tpl");
}
elseif($page == "gestionbdd")
{
	include"php/gestionbdd.php";
}
elseif($page == "inscription-source")
{
	include"php/inscription-source.php";
}
elseif($page == "connexion-source")
{
	include"php/connexion-source.php";
}
else // Affichage de la fenetre d'accueil par défaut
{
	$smarty->display("tpl/accueil.tpl");
}
?>
