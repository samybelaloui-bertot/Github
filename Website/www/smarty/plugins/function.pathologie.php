<?php
    include "php/gestionbdd.php";
    function smarty_function_pathologie($params, &$smarty)
    {
      $recherche = "";
      if(isset($_POST['champ_recherche'])){
        $recherche=$_POST['champ_recherche'];
      }

      $meridien = "";
      if(isset($_POST['meridien'])){
        $meridien=$_POST['meridien'];
      }

      $caracteristique = "";
      if(isset($_POST['caracteristique'])){
        $caracteristique=$_POST['caracteristique'];
      }

      $objet = new Gestionbdd;
      $connexion=$objet->connexion();

      $sql_query ="";
      $sql_query=$sql_query."
              SELECT patho.desc  as 'Pathologie', GROUP_CONCAT(symptome.desc SEPARATOR ' - ') as'Symptome' 
                       FROM patho
                       JOIN symptpatho ON patho.idP=symptpatho.idP
                       JOIN symptome ON symptpatho.idS=symptome.idS";

      if($recherche == "" && $meridien=="" && $caracteristique=="")
      {
              $sql_query=$sql_query."
                       GROUP BY Pathologie
                       ORDER BY Pathologie";
              $sth = $connexion->prepare($sql_query);
              $sth->execute();
       }
       elseif($recherche != "" && $meridien=="" && $caracteristique=="" )
       {
         $sql_query=$sql_query."
                       JOIN keysympt ON symptome.idS=keysympt.idS
                       JOIN keywords ON keysympt.idk=keywords.idK
                       WHERE keywords.name LIKE :recherche
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('recherche' => '%'.$recherche.'%'));
 
       }
        elseif($recherche == "" && $meridien!="" && $caracteristique=="")
       {
         $sql_query=$sql_query."
                       JOIN meridien ON meridien.code=patho.mer
                       WHERE meridien.nom LIKE :meridien
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('meridien' => $meridien));
       }
       elseif($recherche == "" && $meridien=="" && $caracteristique!="")
       {
         $sql_query=$sql_query."
                       WHERE patho.desc LIKE :caracteristique
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('caracteristique' => '%'.$caracteristique.'%'));
       }
        elseif($recherche != "" && $meridien!="" && $caracteristique!="")
       {
         $sql_query=$sql_query."
                       JOIN keysympt ON symptome.idS=keysympt.idS
                       JOIN keywords ON keysympt.idk=keywords.idK
                       JOIN meridien ON meridien.code=patho.mer
                       WHERE meridien.nom LIKE :meridien AND keywords.name LIKE :recherche AND patho.desc LIKE :caracteristique
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('meridien' => $meridien,'recherche' => '%'.$recherche.'%','caracteristique' => '%'.$caracteristique.'%'));
       } 
       elseif($recherche != "" && $meridien!="" && $caracteristique=="")
       {
         $sql_query=$sql_query."
                       JOIN keysympt ON symptome.idS=keysympt.idS
                       JOIN keywords ON keysympt.idk=keywords.idK
                       JOIN meridien ON meridien.code=patho.mer
                       WHERE meridien.nom LIKE :meridien AND keywords.name LIKE :recherche
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('meridien' => $meridien,'recherche' => '%'.$recherche.'%'));
       }
          elseif($recherche != "" && $meridien=="" && $caracteristique!="")
       {
         $sql_query=$sql_query."
                       JOIN keysympt ON symptome.idS=keysympt.idS
                       JOIN keywords ON keysympt.idk=keywords.idK
                       WHERE keywords.name LIKE :recherche AND patho.desc LIKE :caracteristique
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('recherche' => '%'.$recherche.'%','caracteristique' => '%'.$caracteristique.'%'));
       }
          elseif($recherche == "" && $meridien!="" && $caracteristique!="")
       {
         $sql_query=$sql_query."
                       JOIN keysympt ON symptome.idS=keysympt.idS
                       JOIN keywords ON keysympt.idk=keywords.idK
                       JOIN meridien ON meridien.code=patho.mer
                       WHERE meridien.nom LIKE :meridien AND patho.desc LIKE :caracteristique
                       GROUP BY Pathologie
                       ORDER BY Pathologie
                     ";

           $sth = $connexion->prepare($sql_query);
           $sth->execute(array('meridien' => $meridien,'caracteristique' => '%'.$caracteristique.'%'));
       }  

      $liste_patho=array();
      $i=0;
      // On vient remplir le tableau avec les 2 élèments qui nous interesse
      while ($donnees = $sth->fetch())
      {
        $liste_patho[$i]['Pathologie'] = $donnees['Pathologie'];
        $liste_patho[$i]['Symptome'] = $donnees['Symptome'];
        $i++;
      }
      //On transmet le tableau au template
      $smarty-> assign('liste_patho',$liste_patho);
    }
?>