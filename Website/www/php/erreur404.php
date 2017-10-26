<?php 
//if (preg_match('/^\/page-([0-9]+)\.(html)$/', $_SERVER['REDIRECT_URL'], $match, PREG_OFFSET_CAPTURE))
if (preg_match('/^\/calculatrice\/(.*)\/([0-9]+)\/([0-9]+)$/', $_SERVER['REDIRECT_URL'], $match, PREG_OFFSET_CAPTURE))

 { 
  //modification du code retour 
  header("Status: 200 OK", false, 200);
	// print_r($match);  
  //alimentation du paramètre GET 
  $_GET['calcul'] = $match[1][0]; 
  $_REQUEST['calcul'] = $match[1][0]; 
  //recupère le premier param
   $_GET['param1'] = $match[2][0]; 
  $_REQUEST['param1'] = $match[2][0]; 
  //recupere le deuxieme param
    $_GET['param2'] = $match[3][0]; 
  $_REQUEST['param2'] = $match[3][0]; 
  /////////////////////On effectue le calcul///////////
  $add='addition';
  $sous='soustraction';
  $div='division';
  $mult='multiplication';
  //addition 
   if($_GET['param1'] != NULL AND $_GET['param2'] != NULL) // Puis on vérifie leur valeur ...
    {
        if($_GET['calcul'] == $div AND $_GET['param2'] == 0)
        {
            $_REQUEST['resultat']='  On peut pas diviser par 0 voyons !';
        }
        else
		{
				  if($_GET['calcul']==$add)
				  {
					  $_REQUEST['resultat']=$_GET['param1']+$_GET['param2'];
					  
					 
				  }
				   else if($_GET['calcul']==$sous)
				   {
						  $_REQUEST['resultat']=$_GET['param1']-$_GET['param2'];
				   }
					  else if($_GET['calcul']==$mult)
				   {
						  $_REQUEST['resultat']=$_GET['param1']*$_GET['param2'];
				   }
				   else if($_GET['calcul']==$div)
				   {
						 $_REQUEST['resultat']=$_GET['param1']/$_GET['param2'];
  
				   }
           else
           {
            $_REQUEST['resultat']='   La requete est incorrecte !';
           }
	}}
  
  include('../calculatrice/calculatrice.php'); 
} 
?> 