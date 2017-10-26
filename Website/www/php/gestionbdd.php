<?php 
//require("tpl/smarty.class.php"); // INCLUSION SMARTY

class Gestionbdd
{
protected $user;
protected $pass;
protected $bdd;

public function connexion()
{
	//IDENTIFIANTS BDD
	$hote='localhost';
	$bdd='acuBD';
	$user='root';
	$pass='';

		try
		{
			$connexion = new PDO('mysql:host='.$hote.';dbname='.$bdd, $user, $pass,array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));

		}
		catch(Exception $e)
		{
		    die('Impossible de se connecter : '.$e->getMessage());
		}

	return $connexion;
	}


	public function deconnexion()
	{
		//On supprime la session
		session_unset();
		session_destroy();
	}

	public function requete(&$connexion, $requete)
	{
		$reponse = $connexion->query($requete);
		return $donnees = $reponse->fetch();
	}
}
