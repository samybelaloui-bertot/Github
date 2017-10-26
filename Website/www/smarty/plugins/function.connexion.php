<?php

  function smarty_function_connexion($params, &$smarty)
  {

      $connexion=NULL;
      
      if(!isset($_SESSION['login'])) 
      {
          $connexion = "connexion";
      }
      else
      {
          $connexion = "deconnexion";
      }

       return "<a href='index.php?page=" . $connexion . "'>" . $connexion . "</a>";
  }
?> 