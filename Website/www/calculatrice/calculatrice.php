<?php 

echo 'Vous voulez faire une : ' ; 
echo $_GET['calcul'] ; 
echo ' , donc ';
echo $_GET['param1'];
					if($_GET['calcul']==$add)
				  {
					  echo ' + ';
				  }
				   if($_GET['calcul']==$sous)
				   {
					echo ' - ';
				   }
					  if($_GET['calcul']==$mult)
				   {
						echo ' * ';
				   }
				   if($_GET['calcul']==$div)
				   {
						echo ' / ';
  
				   }
echo $_GET['param2'];
echo '=';
echo $_REQUEST['resultat'];


?> 