<?php

class gestionutilisateur
{
	public function __nouvellesession($login)
{
 		$_SESSION['login']= $login;
}

	public function __findesession()
{
	$_SESSION['login']= NULL;
}

}

?>